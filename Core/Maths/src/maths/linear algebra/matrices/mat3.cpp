#include "mat3.h"

namespace advent { namespace maths {

	mat3::mat3()
	{
		for (int i = 0; i < 3 * 3; i++)
			elements[i] = 0.0f;
	}

	mat3::mat3(float diagonal)
	{
		for (int i = 0; i < 3 * 3; i++)
			elements[i] = 0.0f;

		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;

	}

	mat3 mat3::identity()
	{
		return mat3(1.0f);
	}

	mat3& mat3::multiply(const mat3& other)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				float sum = 0.0f;

				for (int e = 0; e < 3; e++)
				{
					sum += elements[x + e * 3] * other.elements[e + y * 3];
				}

				elements[x + y * 3] = sum;
			}
		}

		return *this;
	}

	mat3 operator* (mat3 left, const mat3& right)
	{
		return left.multiply(right);
	}

	mat3& mat3::operator+= (const mat3& other)
	{
		return multiply(other);
	}
} }