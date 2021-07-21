#include "mylib.h"

#include <cstdio>
#include <cstring>

#include <cstdlib>

using std::size_t;
using std::malloc;
using std::strlen;
using std::strcpy;
using std::free;


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

char *get_cstring(const char *str) {
	// Python CFFI cannot use "new[]" or "delete[]" for some reason.
	char *cstr = static_cast<char *>(malloc(strlen(str) + 1));
	strcpy(cstr, str);
	return cstr;
}

void free_cstring(char **str) {
	free(*str);
	*str = nullptr;
}
