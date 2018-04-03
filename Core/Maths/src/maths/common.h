#pragma once

#include <math.h>

namespace advent { namespace maths {

//converts degrees to radians
inline float ToRadians(const float& degrees)
{
	return degrees * (3.14159265358979323846f / 180.0f);
}

//returns the absolute of "value"
inline float Abs(const float& value)
{
	return fabsf(value);
}

} }