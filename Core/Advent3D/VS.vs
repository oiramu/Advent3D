#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0f);

out vec4 VXcolor;

void main()
{
	gl_Position = pr_matrix * vw_matrix * mat4(1.0f) * position;
	VXcolor = color;
}