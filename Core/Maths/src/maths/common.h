#pragma once

namespace advent { namespace maths {

//the first 20 digits of PI. Enough for most of its applications
#define PI = 3.14159265358979323846f;

//converts degrees to radians
inline float ToRadians(const float& degrees)
{
	return degrees * (PI / 180.0f);
}

//returns the absolute of "value"
inline float Abs(const float& value)
{
	return abs(value);
}

} }