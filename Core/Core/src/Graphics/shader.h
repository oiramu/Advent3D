#pragma once

#include <Gl\glew.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

#include <glm\glm.hpp>

struct ShaderSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:

	unsigned int m_ID;
	std::unordered_map<std::string, int> m_UniformCache;

	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderSource ParseShader(const std::string& fileP);
	unsigned int CompileShader(unsigned int type, const std::string& src);

	int GetUniformLocation(const std::string& name);

public:

	Shader (const std::string& filepath);
	Shader(const std::string& vertexCode, const std::string& fragmentCode);

	void bind() { glUseProgram(m_ID); }


	template<typename T>
	void SetUniform(const std::string& name, const T& value)
	{
		static_assert(false);
	}

	template<>
	void SetUniform <int>(const std::string& name, const int& value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	template<>
	void SetUniform <float>(const std::string& name, const float& value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}

	template<>
	void SetUniform <glm::vec2>(const std::string& name, const glm::vec2& value)
	{
		glUniform2fv(GetUniformLocation(name), 1, &value[0]);
	}

	template<>
	void SetUniform <glm::vec3>(const std::string& name, const glm::vec3& value)
	{
		glUniform3fv(GetUniformLocation(name), 1, &value[0]);
	}

	template<>
	void SetUniform <glm::vec4>(const std::string& name, const glm::vec4& value)
	{
		glUniform4fv(GetUniformLocation(name), 1, &value[0]);
	}

	template<>
	void SetUniform <glm::mat2>(const std::string& name, const glm::mat2& value)
	{
		glUniformMatrix2fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
	}

	template<>
	void SetUniform <glm::mat3>(const std::string& name, const glm::mat3& value)
	{
		glUniformMatrix3fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
	}

	template<>
	void SetUniform <glm::mat4>(const std::string& name, const glm::mat4& value)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &value[0][0]);
	}
};