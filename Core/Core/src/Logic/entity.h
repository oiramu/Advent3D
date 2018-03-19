#pragma once

//maths
#include <GLM\vec3.hpp>

struct Entity
{
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	Entity(glm::vec3 pos = glm::vec3(0, 0, 0), glm::vec3 rot = glm::vec3(0, 0, 0), glm::vec3 sca = glm::vec3(1, 1, 1))
		:position(pos), rotation(rot), scale(sca) {}
};