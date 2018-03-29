#pragma once

//opengl
#include <GL\gl3w.h>

//maths
#include <glm/glm.hpp>

//STL
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

namespace Advent3D { namespace Graphics {

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

class Shader
{
private:

	unsigned int m_ID;

	unsigned int ActiveAttributes;
	unsigned int ActiveUniforms;

	//utility functions
	int GetUniformLocation(const std::string& name);

	void CheckCompileErrors(GLuint shader, std::string type);

public:

	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);

	std::vector<Attribute> Attributes;
	std::vector<Uniform> Uniforms;

	void Bind();

	bool HasUniform(const std::string& name);

	void SetBool(const std::string &name, bool value) const;

	void SetInt(const std::string &name, int value) const;

	void SetFloat(const std::string &name, float value) const;

	void SetVec2(const std::string &name, const glm::vec2 &value) const;

	void SetVec2(const std::string &name, float x, float y) const;

	void SetVec3(const std::string &name, const glm::vec3 &value) const;

	void SetVec3(const std::string &name, float x, float y, float z) const;

	void SetVec4(const std::string &name, const glm::vec4 &value) const;

	void SetVec4(const std::string &name, float x, float y, float z, float w);

	void SetMat2(const std::string &name, const glm::mat2 &mat) const;

	void SetMat3(const std::string &name, const glm::mat3 &mat) const;

	void SetMat4(const std::string &name, const glm::mat4 &mat) const;

};
	
} }