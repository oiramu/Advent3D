#include "src\internal\application\window.h"
#include "src\internal\graphics\shader.h"
#include "src\internal\graphics\buffers\buffer.h"
#include "src\internal\graphics\buffers\index_buffer.h"
#include "src\internal\graphics\buffers\vertex_array.h"


#include <maths\maths.h>

int main()
{
	using namespace advent;
	using namespace graphics;
	using namespace maths;
	using namespace utils;
	
	Window win("test", 960, 540);
	Shader shader("VS.vs", "FS.fs");

	GLfloat vertices[] =
	{
		0,0,0,
		0,3,0,
		8,3,0,
		8,0,0
	};

	GLushort indices[] = {0,1,2,2,3,0};

	VertexArray VAO;

	Buffer* VBO = new Buffer(vertices, 4 * 3, 3);
	IndexBuffer IBO(indices,6);
	
	VAO.addBuffer(VBO, 0);

	mat4 ortho = mat4::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	shader.bind();
	shader.setMat4("pr_matrix", ortho);
	shader.setMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

	while (win.Open())
	{
		win.Clear();
		
		VAO.bind();
		IBO.bind();
		glDrawElements(GL_TRIANGLES, IBO.getCount(), GL_UNSIGNED_SHORT, nullptr);
		IBO.unbind();
		VAO.unbind();

		win.Update();
	}

	return 0;
}