#include "src\Internal\window.h"
#include "maths\linear algebra\linear_algebra.h"

int main()
{
	using namespace Advent3D;
	using namespace Graphics;
	using namespace Maths;

	Window window("test", 800, 600);


	while (window.Open())
	{
		window.Clear();
		


		window.Update();
	}

	return 0;
}