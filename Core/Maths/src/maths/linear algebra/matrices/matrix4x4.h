#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "..\..\common.h"
#include "..\vectors\vector3.h"

namespace Advent3D { namespace Maths {

struct Matrix4x4
{
	//components
	float elements[4*4];

	//constructors
	Matrix4x4();
	Matrix4x4(float diagonal);

	//utility functions
	static Matrix4x4 Identity();

	static Matrix4x4 Ortho(float left, float right, float bottom, float top, float near, float far);
	static Matrix4x4 Perspective(float fov, float aspectRatio, float near, float far);

	//transformations
	static Matrix4x4 Translation(const Vector3& translation);
	static Matrix4x4 Rotation(float angle,const Vector3& axis);
	static Matrix4x4 Scale(const Vector3& scale);

	//operations
	Matrix4x4& Multiply(const Matrix4x4& other);
	friend Matrix4x4 operator* (Matrix4x4 left, const Matrix4x4& right);
	Matrix4x4& operator+= (const Matrix4x4& other);
};

} }