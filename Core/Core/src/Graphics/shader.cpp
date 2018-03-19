#include "shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{
	
	//shaders code
	std::string vertexCode;
	std::string fragmentCode;
	std::string geometryCode;
	
	//shader files
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	std::ifstream gShaderFile;
	
	//ensure files can throw exceptions
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	
	try
	{
		//open the files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		
		//read the file's contents and put them into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		//close the files
		vShaderFile.close();
		fShaderFile.close();
		
		//convert the streams into strings
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

		//if the geometry shader path is given, load it
		if (geometryPath != nullptr)
		{
			gShaderFile.open(geometryPath);
			std::stringstream gShaderStream;
			gShaderStream << gShaderFile.rdbuf();
			gShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}

	catch (std::ifstream::failure e)
	{
		std::cout << "SHADER::READING_ERROR" << std::endl;
	}

	//put the shader code into const char*
	const char* vShaderCode = vertexCode.c_str();
	const char * fShaderCode = fragmentCode.c_str();

	//compile the shaders
	unsigned int vertex;
	unsigned int fragment;
	unsigned int geometry;

	int success;
	char infoLog[512];

	//VERTEX
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	CheckCompileErrors(vertex, "VERTEX");
	
	//FRAGMENT
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	CheckCompileErrors(fragment, "FRAGMENT");

	//GEOMETRY (compile only if it's path is given)
	if (geometryPath != nullptr)
	{
		const char * gShaderCode = geometryCode.c_str();
		geometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometry, 1, &gShaderCode, NULL);
		glCompileShader(geometry);
		CheckCompileErrors(geometry, "GEOMETRY");
	}

	//create the shader program
	m_ID = glCreateProgram();

	glAttachShader(m_ID, vertex);
	glAttachShader(m_ID, fragment);
	
	if (geometryPath != nullptr)
		glAttachShader(m_ID, geometry);
	
	glLinkProgram(m_ID);
	CheckCompileErrors(m_ID, "PROGRAM");
	
	//detach the shaders from the program before deleting them
	glDetachShader(m_ID, vertex);
	glDetachShader(m_ID, fragment);
	
	if (geometryPath != nullptr)
		glDetachShader(m_ID, geometry);


	//delete the shaders
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	
	if (geometryPath != nullptr)
		glDeleteShader(geometry);

	//set up the Attributes and the Uniforms, with their appropriate values//
	//TODO: set up 'X.Type' to glType, and make sure that it gets coverted to a string based on its value//

	//name//
	char buffer[128];

	//type//
	GLenum glType;

	//loop through the attributes and set their values//
	for (unsigned int i = 0; i < ActiveAttributes; i++)
	{
		glGetActiveAttrib(m_ID, i, sizeof(buffer), 0, &Attributes[i].Size, &glType, buffer);

		Attributes[i].Name = std::string(buffer);

		Attributes[i].Location = glGetAttribLocation(m_ID, buffer);
	}

	//do the same for the uniforms//
	for (unsigned int i = 0; i < ActiveUniforms; i++)
	{
		glGetActiveUniform(m_ID, i, sizeof(buffer), 0, &Uniforms[i].Size, &glType, buffer);

		Uniforms[i].Name = std::string(buffer);

		Uniforms[i].Location = glGetUniformLocation(m_ID, buffer);
	}
}

void Shader::Bind()
{
	glUseProgram(m_ID);
}

bool Shader::HasUniform(const std::string& name)
{
	for (unsigned int i = 0; i < Uniforms.size(); i++)
	{
		if (Uniforms[i].Name == name)
			return true;
	}

	return false;
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

void Shader::SetVec2(const std::string &name, const glm::vec2 &value) const
{
	glUniform2fv(glGetUniformLocation(m_ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec2(const std::string &name, float x, float y) const
{
	glUniform2f(glGetUniformLocation(m_ID, name.c_str()), x, y);
}

void Shader::SetVec3(const std::string &name, const glm::vec3 &value) const
{
	glUniform3fv(glGetUniformLocation(m_ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec3(const std::string &name, float x, float y, float z) const
{
	glUniform3f(glGetUniformLocation(m_ID, name.c_str()), x, y, z);
}

void Shader::SetVec4(const std::string &name, const glm::vec4 &value) const
{
	glUniform4fv(glGetUniformLocation(m_ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec4(const std::string &name, float x, float y, float z, float w)
{
	glUniform4f(glGetUniformLocation(m_ID, name.c_str()), x, y, z, w);
}

void Shader::SetMat2(const std::string &name, const glm::mat2 &mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat3(const std::string &name, const glm::mat3 &mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat4(const std::string &name, const glm::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

//utility functions
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

int Shader::GetUniformLocation(const std::string& name)
{
	//loop through the uniform vector and check if there is a uniform with the same name//
	for (unsigned int i = 0; i < Uniforms.size(); ++i)
	{
		if (Uniforms[i].Name == name)
			return Uniforms[i].Location;

		else
		{
			//if it does not exist print an error message to the console//
			std::cout << "The uniform '" << Uniforms[i].Name << "' does not exist." << std::endl;
			return -1;
		}
	}

	return 0;
}