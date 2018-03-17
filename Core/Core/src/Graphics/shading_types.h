#pragma once

#include <GL\gl3w.h>
#include <string>

const char* GetTypeFromEnum(GLenum e);

struct Attribute
{
	std::string Name;
	int Size;
	unsigned int Location;
};

struct Uniform
{
	std::string Name;
	int Size;
	unsigned int Location;
};