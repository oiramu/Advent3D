#include "Advent3D.h"

int main()
{
	Window window("Advent", 800, 600);

	glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
	
	Shader shader("ML.vs", "ML.fs");

	while (window.Open())
	{
		window.Clear();

		


		window.Update();
	}

	return 0;
}