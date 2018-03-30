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
	vec3& add(const vec3& other);
	vec3& subtract(const vec3& other);
	vec3& multiply(const vec3& other);
	vec3& divide(const vec3& other);

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
	void normalize();

	void calculateMagnitude();

};
} }