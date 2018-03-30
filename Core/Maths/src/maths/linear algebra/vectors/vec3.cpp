#include "vec3.h"

namespace Advent3D { namespace Maths {

//constructors
vec3::vec3()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->magnitude = 0.0f;
}

vec3::vec3(const float& x, const float& y, const float& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	CalculateMagnitude();
}

//operations
vec3& vec3::Add(const vec3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	CalculateMagnitude();

	return *this;
}

vec3& vec3::Subtract(const vec3& other)
{
	x -= other.x;
	y -= other.y;
	z += other.z;
	CalculateMagnitude();

	return *this;
}

vec3& vec3::Multiply(const vec3& other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;
	CalculateMagnitude();

	return *this;
}

vec3& vec3::Divide(const vec3& other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;
    CalculateMagnitude();

	return *this;
}

//operators
vec3& operator+ (vec3& left, const vec3& right)
{
	return left.Add(right);
}

vec3& operator- (vec3& left, const vec3& right)
{
	return left.Subtract(right);
}

vec3& operator* (vec3& left, const vec3& right)
{
	return left.Multiply(right);
}

vec3& operator/ (vec3& left, const vec3& right)
{
	return left.Divide(right);
}

vec3& vec3::operator+= (const vec3& other)
{
	return Add(other);
}

vec3& vec3::operator-= (const vec3& other)
{
	return Subtract(other);
}

vec3& vec3::operator*= (const vec3& other)
{
	return Multiply(other);
}

vec3& vec3::operator/= (const vec3& other)
{
	return Divide(other);
}

std::ostream& operator<< (std::ostream& stream, const vec3& vector)
{
	stream << "vec3: (" << vector.x << " , " << vector.y << " , " << vector.z << ")\n";
	stream << "Magnitude: " << vector.magnitude;
	return stream;
}

//utility functions
void vec3::CalculateMagnitude()
{
	magnitude = sqrt(x*x + y*y);
}

void vec3::Normalize()
{
	magnitude = 1;
}
} }