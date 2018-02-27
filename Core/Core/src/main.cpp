#include "General\window.h"

int main()
{
	Window window("Advent", glm::vec2(800, 600));

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	while (window.Open())
	{
		window.Clear();
		
		if (Input::GetKey(Button::Left))
		{
			std::cout << "LEFT" << std::endl;
		}

		window.Update();
	}

	return 0;
}