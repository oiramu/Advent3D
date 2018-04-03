#pragma once

#include <iostream>

namespace advent { namespace utils {

std::string read_file(const char* filepath);

void write_file(const char* filepath, const char* content);

} }