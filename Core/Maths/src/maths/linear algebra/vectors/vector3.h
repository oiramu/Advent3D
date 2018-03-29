#pragma once

#include <iostream>
#include <math.h>

namespace Advent3D { namespace Maths {

class Vector3
{
	//components
	float x;
	float y;
	float z;

	//length
	float magnitude;

	//constructors
	Vector3();
	Vector3(const float& x, const float& y, const float& z);

	//operations
	Vector3& Add(const Vector3& other);
	Vector3& Subtract(const Vector3& other);
	Vector3& Multiply(const Vector3& other);
	Vector3& Divide(const Vector3& other);

	//operators
	friend Vector3& operator+ (Vector3& left, const Vector3& right);
	friend Vector3& operator- (Vector3& left, const Vector3& right);
	friend Vector3& operator* (Vector3& left, const Vector3& right);
	friend Vector3& operator/ (Vector3& left, const Vector3& right);

	friend std::ostream& operator<< (std::ostream& stream, const Vector3& vector);

	Vector3& operator+= (const Vector3& other);
	Vector3& operator-= (const Vector3& other);
	Vector3& operator*= (const Vector3& other);
	Vector3& operator/= (const Vector3& other);

	//utility functions
	void Normalize();

	void CalculateMagnitude();

};
} }