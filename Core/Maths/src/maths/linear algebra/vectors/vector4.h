#pragma once

#include <iostream>

namespace Advent3D { namespace Maths {

struct Vector4
{
	float x;
	float y;
	float z;
	float w;

	Vector4();
	Vector4(const float& x, const float& y, const float& z,const float& w);

	Vector4& Add(const Vector4& other);
	Vector4& Subtract(const Vector4& other);
	Vector4& Multiply(const Vector4& other);
	Vector4& Divide(const Vector4& other);

	friend Vector4& operator+ (Vector4& left, const Vector4& right);
	friend Vector4& operator- (Vector4& left, const Vector4& right);
	friend Vector4& operator* (Vector4& left, const Vector4& right);
	friend Vector4& operator/ (Vector4& left, const Vector4& right);

	Vector4& operator+= (const Vector4& other);
	Vector4& operator-= (const Vector4& other);
	Vector4& operator*= (const Vector4& other);
	Vector4& operator/= (const Vector4& other);

	friend std::ostream& operator<< (std::ostream& stream, const Vector4& vector);
};

} }