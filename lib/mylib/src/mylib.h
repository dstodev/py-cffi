#ifndef PY_CFFI_MYLIB_H
#define PY_CFFI_MYLIB_H

#include <cstddef>
#include "mylib_export.h"

extern "C" {

typedef struct {
	int value;
} MyType;

void print_hello();
void print_cstring(const char *str);
void fill_string(char *str, size_t size, char fill);

}

#endif  // PY_CFFI_MYLIB_H
