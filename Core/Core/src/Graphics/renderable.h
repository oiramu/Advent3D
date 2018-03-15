#pragma once

#include <GL\glew.h>
#include "..\Logic\entity.h"
#include <vector>

#include <GLM\vec2.hpp>
#include <GLM\vec3.hpp>
#include <GLM\vec4.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec4 color;
};

class Renderable : public Entity
{
private:

	std::vector<Vertex> vertices;

public:

	Renderable(glm::vec3 pos = glm::vec3(0, 0, 0), glm::vec3 rot = glm::vec3(0, 0, 0), glm::vec3 sca = glm::vec3(1, 1, 1))
		:Entity(pos,rot,sca) {}


};