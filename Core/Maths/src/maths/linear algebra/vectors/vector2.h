#pragma once

#include <iostream>
#include <math.h>

namespace Advent3D { namespace Maths {

struct Vector2
{
	//components
	float x;
	float y;

	//length
	float magnitude;

	//constructors
	Vector2();
	Vector2(const float& x, const float& y);

	//operations
	Vector2& Add(const Vector2& other);
	Vector2& Subtract(const Vector2& other);
	Vector2& Multiply(const Vector2& other);
	Vector2& Divide(const Vector2& other);

	//operators
	friend Vector2& operator+ (Vector2& left, const Vector2& right);
	friend Vector2& operator- (Vector2& left, const Vector2& right);
	friend Vector2& operator* (Vector2& left, const Vector2& right);
	friend Vector2& operator/ (Vector2& left, const Vector2& right);
	
	friend std::ostream& operator<< (std::ostream& stream, const Vector2& vector);

	Vector2& operator+= (const Vector2& other);
	Vector2& operator-= (const Vector2& other);
	Vector2& operator*= (const Vector2& other);
	Vector2& operator/= (const Vector2& other);

	//utility functions
	void Normalize();

	void CalculateMagnitude();

};
		 
} }