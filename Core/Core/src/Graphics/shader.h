#pragma once

#include <Gl\gl3w.h>//TODO Switch to GLAD/gl3w

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <GLM\glm.hpp>

#include "shading_types.h"


struct ShaderSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{

public:
	
	Shader (const std::string& filepath);
	Shader(const std::string& vertexCode, const std::string& fragmentCode);

	std::vector<Attribute> Attributes;
	std::vector<Uniform> Uniforms;

	int ActiveAttributes;
	int ActiveUniforms;

	void Bind();

	bool HasUniform(const std::string& name);

	void UpdateInfo();

	template<typename T>
	void SetUniform(const std::string& name, const T& value)
	{
		static_assert(false);
	}

	template<>
	void SetUniform <int>(const std::string& name, const int& value)
	{
		if(GetUniformLocation(name) >= 0)
			glUniform1i(GetUniformLocation(name), value);
	}

	template<>
	void SetUniform <float>(const std::string& name, const float& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniform1f(GetUniformLocation(name), value);
	}

	template<>
	void SetUniform <glm::vec2>(const std::string& name, const glm::vec2& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniform2fv(GetUniformLocation(name), 1, &value[0]);
	}

	template<>
	void SetUniform <glm::vec3>(const std::string& name, const glm::vec3& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniform3fv(GetUniformLocation(name), 1, &value[0]);
	}

	template<>
	void SetUniform <glm::vec4>(const std::string& name, const glm::vec4& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniform4fv(GetUniformLocation(name), 1, &value[0]);
	}

	template<>
	void SetUniform <glm::mat2>(const std::string& name, const glm::mat2& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniformMatrix2fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
	}

	template<>
	void SetUniform <glm::mat3>(const std::string& name, const glm::mat3& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
	}

	template<>
	void SetUniform <glm::mat4>(const std::string& name, const glm::mat4& value)
	{
		if (GetUniformLocation(name) >= 0)
			glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
	}

private:

	unsigned int m_ID;

	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderSource ParseShader(const std::string& fileP);
	unsigned int CompileShader(unsigned int type, const std::string& src);

	int GetUniformLocation(const std::string& name);
};