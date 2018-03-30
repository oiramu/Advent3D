#include "shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	const char* vShaderCode = advent::utils::read_file(vertexPath).c_str();
	const char * fShaderCode = advent::utils::read_file(fragmentPath).c_str();

	unsigned int vertex;
	unsigned int fragment;
	unsigned int geometry;

	int success;
	char infoLog[512];

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	CheckCompileErrors(vertex, "VERTEX");


	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	CheckCompileErrors(fragment, "FRAGMENT");

	m_ID = glCreateProgram();

	glAttachShader(m_ID, vertex);
	glAttachShader(m_ID, fragment);

	glLinkProgram(m_ID);
	CheckCompileErrors(m_ID, "PROGRAM");

	glDetachShader(m_ID, vertex);
	glDetachShader(m_ID, fragment);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

}

void Shader::bind() const
{
	glUseProgram(m_ID);
}

void Shader::SetBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
}

void Shader::SetVec2(const std::string &name, const advent::maths::vec2 &vec) const
{
	glUniform2f(glGetUniformLocation(m_ID, name.c_str()), vec.x, vec.y);
}

void Shader::SetVec3(const std::string &name, const advent::maths::vec3 &vec) const
{
	glUniform3f(glGetUniformLocation(m_ID, name.c_str()), vec.x, vec.y, vec.z);
}

void Shader::SetVec4(const std::string &name, const advent::maths::vec4 &vec) const
{
	glUniform4f(glGetUniformLocation(m_ID, name.c_str()), vec.x, vec.y, vec.z, vec.w);
}

void Shader::SetMat4(const std::string &name, const advent::maths::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE, mat.elements);
}

//TODO: come up with a better solution and finish implementing uniforms
void Shader::CheckCompileErrors(GLuint shader, std::string type)
{
	GLint success;
	GLchar infoLog[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER::COMPILER_ERROR::" << type << ": failed to compile\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER::PROGRAM_LINKING_ERROR:: of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
		}
	}
}