#pragma once

#include <iostream>

namespace Advent3D { namespace Maths {

	struct Vector2
	{
		float x;
		float y;

		Vector2();
		Vector2(const float& x, const float& y);

		Vector2& Add(const Vector2& other);
		Vector2& Subtract(const Vector2& other);
		Vector2& Multiply(const Vector2& other);
		Vector2& Divide(const Vector2& other);

		friend Vector2& operator+ (Vector2& left, const Vector2& right);
		friend Vector2& operator- (Vector2& left, const Vector2& right);
		friend Vector2& operator* (Vector2& left, const Vector2& right);
		friend Vector2& operator/ (Vector2& left, const Vector2& right);

		Vector2& operator+= (const Vector2& other);
		Vector2& operator-= (const Vector2& other);
		Vector2& operator*= (const Vector2& other);
		Vector2& operator/= (const Vector2& other);

		friend std::ostream& operator<< (std::ostream& stream, const Vector2& vector);
	};
		 
} }