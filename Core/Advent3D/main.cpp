//DISCLAIMER: this file is used to TEST the engine's features. This file is, in fact, not part of the engine source code.  

#include "src\internal\application\window.h"
#include "src\internal\graphics\shader.h"
#include "src\internal\graphics\buffers\buffer.h"
#include "src\internal\graphics\buffers\index_buffer.h"
#include "src\internal\graphics\buffers\vertex_array.h"
#include "src\internal\graphics\2D\renderable2D.h"
#include "src\internal\graphics\2D\renderers\simple_renderer2D.h"

#include <maths\maths.h>

int main()
{
	using namespace advent;
	using namespace graphics;
	using namespace maths;
	using namespace utils;
	
	Window win("test", 960, 540);
	Shader shader("VS.vs", "FS.fs");
	SimpleRenderer2D renderer;

	Renderable2D sprite(vec3(5, 5, 0), vec2(4, 4), vec4(1.0f, 0.0f, 0.0f, 1.0f), shader);
	Renderable2D sprite1(vec3(1, 0, 1), vec2(4, 4), vec4(0.0f, 0.0f, 1.0f, 1.0f), shader);


	mat4 ortho = mat4::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	while (win.Open())
	{
		win.Clear();
		
		shader.bind();
		shader.setMat4("pr_matrix", ortho);
		renderer.submit(&sprite);
		renderer.submit(&sprite1);

		renderer.flush();

		win.Update();
	}

	return 0;
}