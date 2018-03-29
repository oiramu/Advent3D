#include "Vector3.h"

namespace Advent3D { namespace Maths {

//constructors
Vector3::Vector3()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->magnitude = 0.0f;
}

Vector3::Vector3(const float& x, const float& y, const float& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	CalculateMagnitude();
}

//operations
Vector3& Vector3::Add(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	CalculateMagnitude();

	return *this;
}

Vector3& Vector3::Subtract(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z += other.z;
	CalculateMagnitude();

	return *this;
}

Vector3& Vector3::Multiply(const Vector3& other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;
	CalculateMagnitude();

	return *this;
}

Vector3& Vector3::Divide(const Vector3& other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;
    CalculateMagnitude();

	return *this;
}

//operators
Vector3& operator+ (Vector3& left, const Vector3& right)
{
	return left.Add(right);
}

Vector3& operator- (Vector3& left, const Vector3& right)
{
	return left.Subtract(right);
}

Vector3& operator* (Vector3& left, const Vector3& right)
{
	return left.Multiply(right);
}

Vector3& operator/ (Vector3& left, const Vector3& right)
{
	return left.Divide(right);
}

Vector3& Vector3::operator+= (const Vector3& other)
{
	return Add(other);
}

Vector3& Vector3::operator-= (const Vector3& other)
{
	return Subtract(other);
}

Vector3& Vector3::operator*= (const Vector3& other)
{
	return Multiply(other);
}

Vector3& Vector3::operator/= (const Vector3& other)
{
	return Divide(other);
}

std::ostream& operator<< (std::ostream& stream, const Vector3& vector)
{
	stream << "Vector3: (" << vector.x << " , " << vector.y << " , " << vector.z << ")\n";
	stream << "Magnitude: " << vector.magnitude;
	return stream;
}

//utility functions
void Vector3::CalculateMagnitude()
{
	magnitude = sqrt(x*x + y*y);
}

void Vector3::Normalize()
{
	magnitude = 1;
}
} }