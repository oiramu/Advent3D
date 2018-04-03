#pragma once

//maths
#include "..\vectors\vec2.h"

namespace advent { namespace maths {

	struct mat2
	{
		//data
		union
		{
			float elements[2 * 2];
			vec2 columns[2];
		};

		//constructors
		mat2();
		mat2(float diagonal);

		//utility functions
		static mat2 identity();

		//operations
		mat2& multiply(const mat2& other);
		friend mat2 operator* (mat2 left, const mat2& right);
		mat2& operator+= (const mat2& other);
	};
} }