#include "mat2.h"

namespace advent { namespace maths {

	mat2::mat2()
	{
		for (int i = 0; i < 2 * 2; i++)
			elements[i] = 0.0f;
	}

	mat2::mat2(float diagonal)
	{
		for (int i = 0; i < 2 * 2; i++)
			elements[i] = 0.0f;

		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;

	}

	mat2 mat2::identity()
	{
		return mat2(1.0f);
	}

	mat2& mat2::multiply(const mat2& other)
	{
		for (int y = 0; y < 2; y++)
		{
			for (int x = 0; x < 2; x++)
			{
				float sum = 0.0f;

				for (int e = 0; e < 2; e++)
				{
					sum += elements[x + e * 2] * other.elements[e + y * 2];
				}

				elements[x + y * 2] = sum;
			}
		}

		return *this;
	}

	mat2 operator* (mat2 left, const mat2& right)
	{
		return left.multiply(right);
	}

	mat2& mat2::operator+= (const mat2& other)
	{
		return multiply(other);
	}

} }