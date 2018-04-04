#version 330 core

layout (location = 0) out vec4 color;

uniform vec2 light_pos;

in VS_DATA
{
	vec4 color;
} fs_in;

void main()
{
	color = fs_in.color;
}