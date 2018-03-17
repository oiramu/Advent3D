#shader vertex
#version 330 core

layout(location = 0)in vec4 pos;

void main()
{
	gl_Position = pos;
}

#shader fragment
#version 330 core

out vec4 color;

uniform float unif1;

void main()
{
	color = vec4(unif1);
}
