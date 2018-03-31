#include "src\internal\window.h"
#include "src\internal\shader.h"
#include "maths.h"

#include <string>

int main()
{
	using namespace advent;
	using namespace graphics;
	using namespace maths;
	using namespace utils;
	
	Window win("test", 960, 540);
	Shader shader("VS.vs", "FS.fs");

	float vertices[] =
	{
		4,3,
		12,3,
		4,6,
		4,6,
		12,6,
		12,3
	};

	unsigned int VBO;
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
	glEnableVertexAttribArray(0);

	mat4 pr_matrix = mat4::ortho(0.0f, 16.0, 0.0f, 9.0f, -1.0f, 1.0f);

	while (win.Open())
	{
		win.Clear();
		
		
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		shader.bind();
		shader.setMat4("pr_matrix", pr_matrix);
		
		glDrawArrays(GL_TRIANGLES, 0, 6);

		win.Update();
	}

	return 0;
}