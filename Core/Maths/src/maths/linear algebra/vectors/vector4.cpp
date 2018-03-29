#include "Vector4.h"

namespace Advent3D { namespace Maths {

//constructors
Vector4::Vector4()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
	this->magnitude = 0.0f;
}

Vector4::Vector4(const float& x, const float& y, const float& z, const float& w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
	CalculateMagnitude();
}

//operations
Vector4& Vector4::Add(const Vector4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	CalculateMagnitude();

	return *this;
}

Vector4& Vector4::Subtract(const Vector4& other)
{
	x -= other.x;
	y -= other.y;
	z += other.z;
	w -= other.w;
	CalculateMagnitude();

	return *this;
}

Vector4& Vector4::Multiply(const Vector4& other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
	CalculateMagnitude();

	return *this;
}

Vector4& Vector4::Divide(const Vector4& other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;
	w /= other.w;
	CalculateMagnitude();

	return *this;
}

//operators
Vector4& operator+ (Vector4& left, const Vector4& right)
{
	return left.Add(right);
}

Vector4& operator- (Vector4& left, const Vector4& right)
{
	return left.Subtract(right);
}

Vector4& operator* (Vector4& left, const Vector4& right)
{
	return left.Multiply(right);
}

Vector4& operator/ (Vector4& left, const Vector4& right)
{
	return left.Divide(right);
}

Vector4& Vector4::operator+= (const Vector4& other)
{
	return Add(other);
}

Vector4& Vector4::operator-= (const Vector4& other)
{
	return Subtract(other);
}

Vector4& Vector4::operator*= (const Vector4& other)
{
	return Multiply(other);
}

Vector4& Vector4::operator/= (const Vector4& other)
{
	return Divide(other);
}

std::ostream& operator<< (std::ostream& stream, const Vector4& vector)
{
	stream << "Vector4: (" << vector.x << " , " << vector.y << " , " << vector.z << " , " << vector.w << ")\n";
	stream << "Magnitude: " << vector.magnitude;
	return stream;
}

//utility functions
void Vector4::CalculateMagnitude()
{
	magnitude = sqrt(x*x + y*y);
}

void Vector4::Normalize()
{
	magnitude = 1;
}	
} }