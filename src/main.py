import cffi
import pathlib


if __name__ == '__main__':
	lib_path = pathlib.Path(__file__).parent.parent / 'cmake-build-debug/bin/libmylib.dll'

	ffi = cffi.FFI()
	ffi.cdef("""
		void print_hello();
	""")
	lib = ffi.dlopen(str(lib_path))

	lib.print_hello()
