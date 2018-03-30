#include "vec2.h"

namespace Advent3D { namespace Maths {

//constructors
vec2::vec2()
{
	this->x = 0.0f;
	this->y = 0.0f;
	CalculateMagnitude();
}

vec2::vec2(const float& x, const float& y)
{
	this->x = x;
	this->y = y;
	CalculateMagnitude();
}

//operations
vec2& vec2::Add(const vec2& other)
{
	x += other.x;
	y += other.y;
	CalculateMagnitude();

	return *this;
}

vec2& vec2::Subtract(const vec2& other)
{
	x -= other.x;
	y -= other.y;
	CalculateMagnitude();

	return *this;
}

vec2& vec2::Multiply(const vec2& other)
{
	x *= other.x;
	y *= other.y;
	CalculateMagnitude();

	return *this;
}

vec2& vec2::Divide(const vec2& other)
{
	x /= other.x;
	y /= other.y;
	CalculateMagnitude();

	return *this;
}

//operators
vec2& operator+ (vec2& left, const vec2& right)
{
	return left.Add(right);
}

vec2& operator- (vec2& left, const vec2& right)
{
	return left.Subtract(right);
}

vec2& operator* (vec2& left, const vec2& right)
{
	return left.Multiply(right);
}

vec2& operator/ (vec2& left, const vec2& right)
{
	return left.Divide(right);
}

vec2& vec2::operator+= (const vec2& other)
{
	return Add(other);
}

vec2& vec2::operator-= (const vec2& other)
{
	return Subtract(other);
}

vec2& vec2::operator*= (const vec2& other)
{
	return Multiply(other);
}

vec2& vec2::operator/= (const vec2& other)
{
	return Divide(other);
}

std::ostream& operator<< (std::ostream& stream, const vec2& vector)
{
	stream << "vec2: (" << vector.x << " , " << vector.y << ")\n";
	stream << "Magnitude: " << vector.magnitude;
	return stream;
}

//utility functions
void vec2::CalculateMagnitude()
{
	magnitude = sqrt(x*x + y*y);
}

void vec2::Normalize()
{
	magnitude = 1;
}

} }