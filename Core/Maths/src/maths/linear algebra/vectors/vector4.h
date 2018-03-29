#pragma once

#include <iostream>
#include <math.h>

namespace Advent3D { namespace Maths {

class Vector4
{
	//components
	float x;
	float y;
	float z;
	float w;

	//length
	float magnitude;

	//constructors
	Vector4();
	Vector4(const float& x, const float& y, const float& z, const float& w);

	//operations
	Vector4& Add(const Vector4& other);
	Vector4& Subtract(const Vector4& other);
	Vector4& Multiply(const Vector4& other);
	Vector4& Divide(const Vector4& other);

	//operators
	friend Vector4& operator+ (Vector4& left, const Vector4& right);
	friend Vector4& operator- (Vector4& left, const Vector4& right);
	friend Vector4& operator* (Vector4& left, const Vector4& right);
	friend Vector4& operator/ (Vector4& left, const Vector4& right);

	friend std::ostream& operator<< (std::ostream& stream, const Vector4& vector);

	Vector4& operator+= (const Vector4& other);
	Vector4& operator-= (const Vector4& other);
	Vector4& operator*= (const Vector4& other);
	Vector4& operator/= (const Vector4& other);

	//utility functions
	void Normalize();

	void CalculateMagnitude();

};
} }