#include "Advent3D.h"

int main()
{
	Window window("Advent", 800, 600);

	glClearColor(0.09f, 0.09f, 0.09f, 1.0f);
	
	Shader shader("shader.shader");

	while (window.Open())
	{
		window.Clear();

		ImGui::Begin("WINDOW");

		ImGui::End();



		window.Update();
	}

	return 0;
}