#pragma once

//opengl
#include <GL\gl3w.h>

//maths
#include <maths\linear_algebra.h>

//file reading 
#include <utils\file_utils.h>

namespace advent { namespace graphics {

class Shader
{
private:

	GLuint m_ID;

	enum SHADER_TYPE { PROGRAM, VERTEX, FRAGMENT, GEOMETRY, COMPUTE };

	void CheckCompileErrors(GLuint shader, const SHADER_TYPE& type) const;

public:

	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr, const char* computePath = nullptr);
	~Shader();

	void bind() const;

	void setBool(const std::string& name, bool value) const;

	void setInt(const std::string& name, int value) const;

	void setFloat(const std::string& name, float value) const;

	void setVec2(const std::string& name, const maths::vec2 &vec) const;

	void setVec3(const std::string& name, const maths::vec3 &vec) const;

	void setVec4(const std::string& name, const maths::vec4 &vec) const;

	void setMat2(const std::string& name, const maths::mat2& mat, GLboolean transpose = GL_FALSE) const;

	void setMat3(const std::string& name, const maths::mat3& mat, GLboolean transpose = GL_FALSE) const;

	void setMat4(const std::string &name, const maths::mat4 &mat, GLboolean transpose = GL_FALSE) const;

};
} }