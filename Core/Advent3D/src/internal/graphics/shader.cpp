#include "shader.h"

namespace advent { namespace graphics {

Shader::Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath, const char* computePath)
{
	std::string VSCode = advent::utils::read_file(vertexPath);
	std::string FSCode = advent::utils::read_file(fragmentPath);

	const char* vShaderCode = VSCode.c_str();
	const char * fShaderCode = FSCode.c_str();

	GLuint vertex;
	GLuint fragment;
	GLuint geometry;
	GLuint compute;

	//VERTEX
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	CheckCompileErrors(vertex, SHADER_TYPE::VERTEX);

	//FRAGMENT
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	CheckCompileErrors(fragment, SHADER_TYPE::FRAGMENT);

	//COMPUTE
	if (computePath != nullptr)
	{
		std::string CSCode = advent::utils::read_file(computePath);
		const char* cShaderCode = CSCode.c_str();

		compute = glCreateShader(GL_COMPUTE_SHADER);
		
		glShaderSource(compute, 1, &cShaderCode, NULL);
		glCompileShader(compute);
		
		CheckCompileErrors(compute, SHADER_TYPE::COMPUTE);
	}

	//GEOMETRY
	if (geometryPath != nullptr)
	{
		std::string GSCode = advent::utils::read_file(geometryPath);
		const char* gShaderCode = GSCode.c_str();

		geometry = glCreateShader(GL_GEOMETRY_SHADER);
		
		glShaderSource(geometry, 1, &gShaderCode, NULL);
		glCompileShader(geometry);
		
		CheckCompileErrors(geometry, SHADER_TYPE::GEOMETRY);
	}

	m_ID = glCreateProgram();

	glAttachShader(m_ID, vertex);
	glAttachShader(m_ID, fragment);

	if (geometryPath != nullptr)
		glAttachShader(m_ID, geometry);

	if (computePath != nullptr)
		glAttachShader(m_ID, compute);

	glLinkProgram(m_ID);
	CheckCompileErrors(m_ID, SHADER_TYPE::PROGRAM);

	glDetachShader(m_ID, vertex);
	glDetachShader(m_ID, fragment);

	if (geometryPath != nullptr)
		glDetachShader(m_ID, geometry);

	if (computePath != nullptr)
		glDetachShader(m_ID, compute);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	if (geometryPath != nullptr)
		glDeleteShader(geometry);

	if (computePath != nullptr)
		glDeleteShader(compute);
}

void Shader::bind() const
{
	glUseProgram(m_ID);
}

void Shader::setBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
	glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
}

void Shader::setVec2(const std::string &name, const advent::maths::vec2 &vec) const
{
	glUniform2f(glGetUniformLocation(m_ID, name.c_str()), vec.x, vec.y);
}

void Shader::setVec3(const std::string &name, const advent::maths::vec3 &vec) const
{
	glUniform3f(glGetUniformLocation(m_ID, name.c_str()), vec.x, vec.y, vec.z);
}

void Shader::setVec4(const std::string &name, const advent::maths::vec4 &vec) const
{
	glUniform4f(glGetUniformLocation(m_ID, name.c_str()), vec.x, vec.y, vec.z, vec.w);
}

void Shader::setMat2(const std::string& name, const maths::mat2& mat, GLboolean transpose) const
{
	glUniformMatrix2fv(glGetUniformLocation(m_ID, name.c_str()), 1, transpose, mat.elements);
}

void Shader::setMat3(const std::string& name, const maths::mat3& mat, GLboolean transpose) const
{
	glUniformMatrix3fv(glGetUniformLocation(m_ID, name.c_str()), 1, transpose, mat.elements);
}

void Shader::setMat4(const std::string& name, const maths::mat4& mat, GLboolean transpose) const
{
	glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, transpose, mat.elements);
}

void Shader::CheckCompileErrors(GLuint shader, const SHADER_TYPE& type) const
{
	GLint result;
	GLchar infoLog[1024];

	if (type != SHADER_TYPE::PROGRAM)
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
		if (!result)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			printf("\n %s", infoLog);
		}
	}

	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &result);
		if (!result)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			printf("\n Program linking error: \n\n %s ", infoLog);
		}
	}
}

Shader::~Shader()
{
	glDeleteProgram(m_ID);
}

} }