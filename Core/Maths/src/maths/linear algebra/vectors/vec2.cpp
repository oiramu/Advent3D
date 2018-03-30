#include "vec2.h"

namespace Advent3D { namespace Maths {

//constructors
vec2::vec2()
{
	this->x = 0.0f;
	this->y = 0.0f;
	calculateMagnitude();
}

vec2::vec2(const float& x, const float& y)
{
	this->x = x;
	this->y = y;
	calculateMagnitude();
}

//operations
vec2& vec2::add(const vec2& other)
{
	x += other.x;
	y += other.y;
	calculateMagnitude();

	return *this;
}

vec2& vec2::subtract(const vec2& other)
{
	x -= other.x;
	y -= other.y;
	calculateMagnitude();

	return *this;
}

vec2& vec2::multiply(const vec2& other)
{
	x *= other.x;
	y *= other.y;
	calculateMagnitude();

	return *this;
}

vec2& vec2::divide(const vec2& other)
{
	x /= other.x;
	y /= other.y;
	calculateMagnitude();

	return *this;
}

//operators
vec2& operator+ (vec2& left, const vec2& right)
{
	return left.add(right);
}

vec2& operator- (vec2& left, const vec2& right)
{
	return left.subtract(right);
}

vec2& operator* (vec2& left, const vec2& right)
{
	return left.multiply(right);
}

vec2& operator/ (vec2& left, const vec2& right)
{
	return left.divide(right);
}

vec2& vec2::operator+= (const vec2& other)
{
	return add(other);
}

vec2& vec2::operator-= (const vec2& other)
{
	return subtract(other);
}

vec2& vec2::operator*= (const vec2& other)
{
	return multiply(other);
}

vec2& vec2::operator/= (const vec2& other)
{
	return divide(other);
}

std::ostream& operator<< (std::ostream& stream, const vec2& vector)
{
	stream << "vec2: (" << vector.x << " , " << vector.y << ")\n";
	stream << "magnitude: " << vector.magnitude;
	return stream;
}

//utility functions
void vec2::calculateMagnitude()
{
	magnitude = sqrt(x*x + y*y);
}

void vec2::normalize()
{
	magnitude = 1;
}

} }