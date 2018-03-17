#pragma once

#include <string>

enum TYPE
{
	BOOL,
	INT,
	FLOAT,
	SAMPLER1D,
	SAMPLER2D,
	SAMPLER3D,
	SAMPLER_CUBE,
	VEC2,
	VEC3,
	VEC4,
	MAT2,
	MAT3,
	MAT4
};

struct Uniform
{
	TYPE Type;
	std::string Name;
	int Size;
	unsigned int Location;
};

struct Attribute
{
	TYPE Type;
	std::string Name;
	int Size;
	unsigned int Location;
};