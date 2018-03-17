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

uniform vec4 unif1;
uniform vec4 unif2;

void main()
{
	color = unif1*unif2;
}
