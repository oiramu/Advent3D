#pragma once

//maths
#include "..\..\common.h"
#include "..\vectors\vec3.h"
#include "..\vectors\vec4.h"

namespace advent { namespace maths {

struct mat4
{
	//data
	union
	{
		float elements[4*4];
		vec4 columns[4];
	};

	//constructors
	mat4();
	mat4(float diagonal);

	//utility functions
	static mat4 identity();

	static mat4 ortho(float left, float right, float bottom, float top, float near, float far);
	static mat4 perspective(float fov, float aspectRatio, float near, float far);

	//transformations
	static mat4 translation(const vec3& translation);
	static mat4 rotation(float angle,const vec3& axis);
	static mat4 scale(const vec3& scale);

	//operations
	mat4& multiply(const mat4& other);
	friend mat4 operator* (mat4 left, const mat4& right);
	mat4& operator+= (const mat4& other);
};

} }