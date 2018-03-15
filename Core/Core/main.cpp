#include "Advent3D.h"

int main()
{
	Window window("Engine", 800, 600);

	glClearColor(0.09f, 0.09f, 0.09f, 1.0f);

	Shader shader("shader.shader");


	while (window.Open())
	{
		window.Clear();

		ImGui::Begin("Window");

		ImGui::End();

		window.Update();
	}

	return 0;
}