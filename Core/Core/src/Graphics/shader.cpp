#include "shader.h"

Shader::Shader(const std::string& filepath)
{
	ShaderSource src = ParseShader(filepath);
	m_ID = CreateShader(src.VertexSource, src.FragmentSource);
}

Shader::Shader(const std::string& vertexCode, const std::string& fragmentCode)
{
	m_ID = CreateShader(vertexCode, fragmentCode);
}

void Shader::Bind()
{
	glUseProgram(m_ID);
	UpdateInfo();
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glGetProgramiv(program, GL_ACTIVE_ATTRIBUTES, &ActiveAttributes);
	glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &ActiveUniforms);

	glDetachShader(program, vs);
	glDetachShader(program, fs);

	glDeleteShader(vs);
	glDeleteShader(fs);

	//resize the vectors to the number of active elements
	
	Attributes.resize(ActiveAttributes);
	Uniforms.resize(ActiveUniforms);

	//iterate over all the active attributes

	char buffer[128];
	for (unsigned int i = 0; i < ActiveAttributes; i++)
	{
		GLenum glType;
		glGetActiveAttrib(program, i, sizeof(buffer), 0, &Attributes[i].Size, &glType, buffer);
		Attributes[i].Name = std::string(buffer);
		Attributes[i].Type = TYPE::BOOL;

		Attributes[i].Location = glGetAttribLocation(program, buffer);
	}

	//same for the uniforms

	for (unsigned int i = 0; i < ActiveUniforms; i++)
	{
		GLenum glType;
		glGetActiveUniform(program, i, sizeof(buffer), 0, &Uniforms[i].Size, &glType, buffer);
		Uniforms[i].Name = std::string(buffer);
		Uniforms[i].Type = TYPE::BOOL;

		Uniforms[i].Location = glGetUniformLocation(program, buffer);
	}

	return program;
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

void Shader::UpdateInfo()
{
	//query the program for the attributes and uniforms count
	glGetProgramiv(m_ID, GL_ACTIVE_ATTRIBUTES, &ActiveAttributes);
	glGetProgramiv(m_ID, GL_ACTIVE_UNIFORMS, &ActiveUniforms);

	//resize to fit the new number of elements
	Attributes.resize(ActiveAttributes);
	Uniforms.resize(ActiveUniforms);

	//loop through the attributes vector and set the corresponding values
	char buffer[128];
	for (unsigned int i = 0; i < ActiveAttributes; i++)
	{
		GLenum glType;
		
		glGetActiveAttrib(m_ID, i, sizeof(buffer), 0, &Attributes[i].Size, &glType, buffer);
		
		Attributes[i].Name = std::string(buffer);
		
		Attributes[i].Type = TYPE::BOOL;

		Attributes[i].Location = glGetAttribLocation(m_ID, buffer);
	}

	//loop through the uniforms vector and set the corresponding values
	for (unsigned int i = 0; i < ActiveUniforms; i++)
	{
		GLenum glType;
		
		glGetActiveUniform(m_ID, i, sizeof(buffer), 0, &Uniforms[i].Size, &glType, buffer);
		
		Uniforms[i].Name = std::string(buffer);
		
		Uniforms[i].Type = TYPE::BOOL;

		Uniforms[i].Location = glGetUniformLocation(m_ID, buffer);
	}
}

ShaderSource Shader::ParseShader(const std::string& fileP)
{
	std::ifstream stream(fileP);

	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];

	ShaderType type = ShaderType::NONE;

	if (stream.good())
	{
		while (getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
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
				ss[(int)type] << line << '\n';
			}
		}

		return { ss[0].str(), ss[1].str() };
	}

	else
	{
		std::cout << "the filepath to the shader is probably wrong" << std::endl;
		return { ss[0].str(), ss[1].str() };
	}
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& src)
{
	unsigned int id = glCreateShader(type);
	const char* source = src.c_str();
	
	glShaderSource(id, 1, &source, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader." << '\n' << message;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

int Shader::GetUniformLocation(const std::string& name)
{

	for (unsigned int i = 0; i < Uniforms.size(); ++i)
	{
		if (Uniforms[i].Name == name)
			return Uniforms[i].Location;
	}

	return -1;
}
