#include "Advent3D.h"

int main()
{
	Window window("Advent", 800, 600);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);


	while (window.Open())
	{
		window.Clear();

		

		window.Update();
	}

	return 0;
}