#include "file_utils.h"

namespace advent { namespace utils {

std::string read_file(const char* filepath)
{
	FILE* file = fopen(filepath, "rt");

	fseek(file, 0, SEEK_END);

	unsigned long length = ftell(file);

	char* data = new char[length + 1];

	memset(data, 0, length + 1);

	fseek(file, 0, SEEK_SET);

	fread(data, 1, length, file);

	fclose(file);

	std::string result(data);

	delete[] data;

	return result;
}

void write_file(const char* filepath, const char* content)
{
	FILE *file = fopen(filepath, "w");

	if (file == NULL)
	{
		printf("Error opening file: %s", filepath);
		exit(1);
	}

	fprintf(file, content);

	fclose(file);
}
} }