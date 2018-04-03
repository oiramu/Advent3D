#pragma once

//maths
#include "..\vectors\vec3.h"

namespace advent { namespace maths {

	struct mat3
	{
		//data
		union
		{
			float elements[3 * 3];
			vec3 columns[3];
		};

		//constructors
		mat3();
		mat3(float diagonal);

		//utility functions
		static mat3 identity();

		//operations
		mat3& multiply(const mat3& other);
		friend mat3 operator* (mat3 left, const mat3& right);
		mat3& operator+= (const mat3& other);
	};

} }