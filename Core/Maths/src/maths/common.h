#pragma once

namespace advent { namespace maths {

#define PI = 3.14159265358979323846f;

template <typename T>
inline T ToRadians(const T& degrees)
{
	return degrees * (PI / 180.0f);
}

template <typename T>
inline T Abs(const T& value)
{
	return abs(value);
}

} }