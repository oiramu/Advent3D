#pragma once

#include <iostream>
#include <math.h>

namespace Advent3D { namespace Maths {

struct vec3
{
	//components
	float x;
	float y;
	float z;

	//length
	float magnitude;

	//constructors
	vec3();
	vec3(const float& x, const float& y, const float& z);

	//operations
	vec3& Add(const vec3& other);
	vec3& Subtract(const vec3& other);
	vec3& Multiply(const vec3& other);
	vec3& Divide(const vec3& other);

	//operators
	friend vec3& operator+ (vec3& left, const vec3& right);
	friend vec3& operator- (vec3& left, const vec3& right);
	friend vec3& operator* (vec3& left, const vec3& right);
	friend vec3& operator/ (vec3& left, const vec3& right);

	friend std::ostream& operator<< (std::ostream& stream, const vec3& vector);

	vec3& operator+= (const vec3& other);
	vec3& operator-= (const vec3& other);
	vec3& operator*= (const vec3& other);
	vec3& operator/= (const vec3& other);

	//utility functions
	void Normalize();

	void CalculateMagnitude();

};
} }