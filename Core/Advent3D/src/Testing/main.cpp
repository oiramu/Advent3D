#include "..\Internal\window.h"

int main()
{
	Window window("The Survivor", 800, 600);

	while (window.Open())
	{
		window.Clear();



		window.Update();
	}

	return 0;
}