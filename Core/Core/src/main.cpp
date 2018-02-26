#include "General\window.h"
#include <string>

int main()
{
	Window window("Advent", glm::vec2(800, 600));

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	while (window.Open())
	{
		window.Clear();
		


		window.Update();
	}

	return 0;
}