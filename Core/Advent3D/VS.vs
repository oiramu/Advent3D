#version 330 core

layout (location = 0) in vec4 position;

int main()
{
	glPosition = position;
}