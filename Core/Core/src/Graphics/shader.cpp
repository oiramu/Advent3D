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
	glGetProgramiv(m_ID, GL_ACTIVE_ATTRIBUTES, &ActiveAttributes);
	glGetProgramiv(m_ID, GL_ACTIVE_UNIFORMS, &ActiveUniforms);
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

	glDetachShader(program, vs);
	glDetachShader(program, fs);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
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
	if (m_UniformCache.find(name) != m_UniformCache.end())
		return m_UniformCache[name];

	int uniformLocation = glGetUniformLocation(m_ID, name.c_str());

	if (uniformLocation == -1)
	{
		std::cout << "The Uniform '" << name << "' does not exist." << std::endl;
	}

	return uniformLocation;
}
