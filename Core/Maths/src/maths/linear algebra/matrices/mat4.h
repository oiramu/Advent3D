#pragma once

#include <math.h>
#include "..\..\common.h"
#include "..\vectors\vec3.h"

namespace Advent3D { namespace Maths {

struct mat4
{
	//components
	float elements[4*4];

	//constructors
	mat4();
	mat4(float diagonal);

	//utility functions
	static mat4 Identity();

	static mat4 Ortho(float left, float right, float bottom, float top, float near, float far);
	static mat4 Perspective(float fov, float aspectRatio, float near, float far);

	//transformations
	static mat4 Translation(const vec3& translation);
	static mat4 Rotation(float angle,const vec3& axis);
	static mat4 Scale(const vec3& scale);

	//operations
	mat4& Multiply(const mat4& other);
	friend mat4 operator* (mat4 left, const mat4& right);
	mat4& operator+= (const mat4& other);

	friend std::ostream& operator<< (std::ostream& stream, const mat4& vector);
};

} }