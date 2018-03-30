#include "vec4.h"

namespace Advent3D { namespace Maths {

//constructors
vec4::vec4()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
	this->magnitude = 0.0f;
}

vec4::vec4(const float& x, const float& y, const float& z, const float& w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
	CalculateMagnitude();
}

//operations
vec4& vec4::Add(const vec4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	CalculateMagnitude();

	return *this;
}

vec4& vec4::Subtract(const vec4& other)
{
	x -= other.x;
	y -= other.y;
	z += other.z;
	w -= other.w;
	CalculateMagnitude();

	return *this;
}

vec4& vec4::Multiply(const vec4& other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
	CalculateMagnitude();

	return *this;
}

vec4& vec4::Divide(const vec4& other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;
	w /= other.w;
	CalculateMagnitude();

	return *this;
}

//operators
vec4& operator+ (vec4& left, const vec4& right)
{
	return left.Add(right);
}

vec4& operator- (vec4& left, const vec4& right)
{
	return left.Subtract(right);
}

vec4& operator* (vec4& left, const vec4& right)
{
	return left.Multiply(right);
}

vec4& operator/ (vec4& left, const vec4& right)
{
	return left.Divide(right);
}

vec4& vec4::operator+= (const vec4& other)
{
	return Add(other);
}

vec4& vec4::operator-= (const vec4& other)
{
	return Subtract(other);
}

vec4& vec4::operator*= (const vec4& other)
{
	return Multiply(other);
}

vec4& vec4::operator/= (const vec4& other)
{
	return Divide(other);
}

std::ostream& operator<< (std::ostream& stream, const vec4& vector)
{
	stream << "vec4: (" << vector.x << " , " << vector.y << " , " << vector.z << " , " << vector.w << ")\n";
	stream << "Magnitude: " << vector.magnitude;
	return stream;
}

//utility functions
void vec4::CalculateMagnitude()
{
	magnitude = sqrt(x*x + y*y);
}

void vec4::Normalize()
{
	magnitude = 1;
}	
} }