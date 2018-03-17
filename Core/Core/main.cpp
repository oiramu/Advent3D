#include "Advent3D.h"

int main()
{
	Window window("Advent", 800, 600);

	glClearColor(0.09f, 0.09f, 0.09f, 1.0f);


	while (window.Open())
	{
		window.Clear();


		
		window.Update();
	}

	return 0;
}