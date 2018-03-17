#include "shader.h"

Shader::Shader(const std::string& filepath)
{
	//open the file//
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	
	ShaderType type = ShaderType::NONE;

	if (stream.good())
	{
		//read the file//
		while (getline(stream, line))
		{
			//look for the '#shader' keyword//
			if (line.find("#shader") != std::string::npos)
			{	
				//split the code between vertex and fragment source//
				if (line.find("vertex") != std::string::npos)
				{
					type = ShaderType::VERTEX;
				}

				else if (line.find("fragment") != std::string::npos)
				{
					type = ShaderType::FRAGMENT;
				}
			}

			else
			{
				//put the code in the appropriate 'slot' of the stringstream 'ss'//
				ss[(int)type] << line << '\n';
			}
		}
	}

	//create the program//
	m_ID = glCreateProgram();

	//VERTEX SHADER//
	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
	const char* vs_src = ss[0].str().c_str();

	glShaderSource(vs, 1, &vs_src, nullptr);
	glCompileShader(vs);

	int fs_result;
	glGetShaderiv(vs, GL_COMPILE_STATUS, &fs_result);

	if (fs_result == GL_FALSE)
	{
		int length;
		glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(vs, length, &length, message);

		std::cout << "Failed to compile vertex shader." << std::endl << message;
		glDeleteShader(vs);
	}
	
	//FRAGMENT SHADER//
	unsigned int fs = glCreateShader(GL_VERTEX_SHADER);
	const char* fs_src = ss[1].str().c_str();

	glShaderSource(fs, 1, &fs_src, nullptr);
	glCompileShader(fs);

	int vs_result;
	glGetShaderiv(fs, GL_COMPILE_STATUS, &vs_result);

	if (vs_result == GL_FALSE)
	{
		int length;
		glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(fs, length, &length, message);

		std::cout << "Failed to compile fragment shader." << std::endl << message;
		glDeleteShader(vs);
	}

	//configure program//
	glAttachShader(m_ID, vs);
	glAttachShader(m_ID, fs);

	glLinkProgram(m_ID);
	glValidateProgram(m_ID);

	glDetachShader(m_ID, vs);
	glDetachShader(m_ID, fs);

	glDeleteShader(vs);
	glDeleteShader(fs);

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

//activate the shader//
void Shader::Bind()
{
	//use the program//
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

//utility functions//
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
}
