#include "mylib.h"

#include <cstdio>

using std::size_t;


void print_hello() {
	std::printf("%s\n", "hello");
}

void print_cstring(const char *str) {
	std::printf("%s\n", str);
}

void fill_string(char *str, size_t size, char fill) {
	for (size_t i{0}; i < size; ++i) {
		str[i] = fill;
	}
}
