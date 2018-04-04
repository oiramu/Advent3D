//DISCLAIMER: this file is used to TEST the engine's features. This file is, in fact, not part of the engine source code.  

#include "src\internal\application\window.h"
#include "src\internal\graphics\shader.h"
#include "src\internal\graphics\buffers\buffer.h"
#include "src\internal\graphics\buffers\index_buffer.h"
#include "src\internal\graphics\buffers\vertex_array.h"
#include "src\internal\graphics\2D\renderable2D.h"
#include "src\internal\graphics\2D\renderers\batch_renderer2D.h"
#include "src\internal\graphics\2D\sprite.h"

#include <maths\maths.h>

int main()
{
	using namespace advent;
	using namespace graphics;
	using namespace maths;
	using namespace utils;
	
	Window win("test", 960, 540);
	Shader shader("VS.vs", "FS.fs");
	BatchRenderer2D renderer;

	Sprite sprite(vec3(5, 5, 0), vec2(2, 2), vec4(1.0f, 0.0f, 0.0f, 1.0f));
	Sprite sprite1(vec3(1, 0, 1), vec2(2, 2), vec4(0.0f, 0.0f, 1.0f, 1.0f));


	mat4 ortho = mat4::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	shader.bind();
	shader.setMat4("pr_matrix", ortho);

	//TODO: INPUT MOUSE POSITION BUG!!

	while (win.Open())
	{
		win.Clear();
	
		renderer.begin();
		renderer.submit(&sprite);
		renderer.submit(&sprite1);
		renderer.end();

		renderer.flush();

		win.Update();
	}

	return 0;
}