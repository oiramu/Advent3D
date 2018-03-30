#include "maths.h"

int main()
{
	using namespace Advent3D;

	Maths::mat4 proj = Maths::mat4::Perspective(40.0f,16.0f/9.0f, 0.1f,100.0f);

	std::cout << proj << std::endl;
	
	system("PAUSE");

	return 0;
}