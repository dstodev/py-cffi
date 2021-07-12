import cffi
import pathlib

SELF_DIR = pathlib.Path(__file__).parent
BUILD_DIR = SELF_DIR.parent / 'cmake-build-debug'
LIB_PATH = BUILD_DIR / 'bin/libmylib.dll'


class FFIMyLib:
	def __init__(self):
		ffi = cffi.FFI()
		ffi.cdef("""
			typedef struct {
				int value;
			} MyType;
			void print_hello();
			void print_cstring(const char *str);
			void fill_string(char *str, size_t size, char fill);
		""")
		self.ffi = ffi
		self.lib = ffi.dlopen(str(LIB_PATH))

	def __getattr__(self, item):
		return getattr(self.lib, item)
