#pragma once

//opengl
#include <GL\gl3w.h>

//maths
#include "maths\linear_algebra.h"

//file reading
#include "..\utils\file_utils.h"

//STL
#include <iostream>

class Shader
{
private:

	unsigned int m_ID;

	void CheckCompileErrors(GLuint shader, std::string type);

public:

	Shader(const char* vertexPath, const char* fragmentPath);

	void bind() const;

	void SetBool(const std::string &name, bool value) const;

	void SetInt(const std::string &name, int value) const;

	void SetFloat(const std::string &name, float value) const;

	void SetVec2(const std::string &name, const advent::maths::vec2 &vec) const;

	void SetVec3(const std::string &name, const advent::maths::vec3 &vec) const;

	void SetVec4(const std::string &name, const advent::maths::vec4 &vec) const;

	void SetMat4(const std::string &name, const advent::maths::mat4 &mat) const;

};