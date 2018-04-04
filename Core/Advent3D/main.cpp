//DISCLAIMER: this file is used to TEST the engine's features. This file is, in fact, not part of the engine source code.  

#include "src\internal\application\window.h"
#include "src\internal\graphics\2D\batch_renderer2D.h"
#include "src\internal\graphics\2D\sprite.h"
#include "src\internal\graphics\shader.h"
#include "utils\timer.h"

#include <maths\maths.h>

#include <string>

int main()
{
	using namespace advent;
	using namespace graphics;
	using namespace maths;
	using namespace utils;
	
	Window win("test", 960, 540);
	Shader shader("VS.vs", "FS.fs");

	mat4 ortho = mat4::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	BatchRenderer2D renderer;
	Renderable2D sprite(vec3(0, 0, 0), vec2(2, 2), vec4(1.0f, 0.0f, 0.0f, 1.0f));

	shader.bind();
	shader.setMat4("pr_matrix", ortho);
	
	while (win.Open())
	{
		win.Clear();
	
		renderer.begin();
		renderer.submit(&sprite);
		renderer.end();

		renderer.flush();

		win.Update();
	}

	return 0;
}