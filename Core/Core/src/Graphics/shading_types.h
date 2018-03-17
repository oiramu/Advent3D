#pragma once

#include <string>

struct Attribute
{
	std::string Name;
	std::string Type;
	int Size;
	unsigned int Location;
};

struct Uniform
{
	std::string Name;
	std::string Type;
	int Size;
	unsigned int Location;
};