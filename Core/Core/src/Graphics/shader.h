#pragma once

//opengl header//
#include <Gl\gl3w.h>

//STL//
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//maths//
#include <GLM\glm.hpp>

//uniform and attribute structs//
#include "shading_types.h"

class Shader
{

public:
	
	Shader (const std::string& filepath);

	//list of attributes and uniforms used by the shader//
	std::vector<Attribute> Attributes;
	std::vector<Uniform> Uniforms;

	//activate the shader//
	void Bind() const;

	//check if a uniform exists//
	bool HasUniform(const std::string& name);

	//base template//
	template<typename T>
	void SetUniform(const std::string& name, const T& value)
	{
		static_assert(false);
	}

	//int//
	template<>
	void SetUniform <int>(const std::string& name, const int& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniform1i(GetUniformLocation(name), value);
	}

	//unsigned int//
	template<>
	void SetUniform <unsigned int>(const std::string& name, const unsigned int& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniform1ui(GetUniformLocation(name), value);
	}

	//float//
	template<>
	void SetUniform <float>(const std::string& name, const float& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniform1f(GetUniformLocation(name), value);
	}

	//vec2//
	template<>
	void SetUniform <glm::vec2>(const std::string& name, const glm::vec2& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniform2fv(GetUniformLocation(name), 1, &value[0]);
	}

	//vec3//
	template<>
	void SetUniform <glm::vec3>(const std::string& name, const glm::vec3& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniform3fv(GetUniformLocation(name), 1, &value[0]);
	}

	//vec4//
	template<>
	void SetUniform <glm::vec4>(const std::string& name, const glm::vec4& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniform4fv(GetUniformLocation(name), 1, &value[0]);
	}

	//mat3//
	template<>
	void SetUniform <glm::mat2>(const std::string& name, const glm::mat2& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniformMatrix2fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
	}

	//mat3//
	template<>
	void SetUniform <glm::mat3>(const std::string& name, const glm::mat3& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
	}

	//mat4//
	template<>
	void SetUniform <glm::mat4>(const std::string& name, const glm::mat4& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
	}


private:

	//ID//
	unsigned int m_ID;

	//amount of attributes and uniforms currenly used from the shader//
	unsigned int ActiveAttributes;
	unsigned int ActiveUniforms;
	
	//utility functions//
	int GetUniformLocation(const std::string& name);
};
