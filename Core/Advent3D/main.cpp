#include "src\internal\window.h"
#include "src\internal\shader.h"
#include "maths.h"

int main()
{
	using namespace advent;
	using namespace graphics;
	using namespace maths;
	using namespace utils;

	Shader shader("VS.vs", "FS.fs");
	shader.bind();

	system("PAUSE");

	return 0;
}