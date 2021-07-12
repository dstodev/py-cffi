from unittest import TestCase
from cffi import FFI

from src.ffi_mylib import FFIMyLib


class TestFFIMyLib(TestCase):
	def __init__(self, *args, **kwargs):
		super().__init__(*args, **kwargs)
		self.mylib = FFIMyLib()

	def test_print_hello_callable(self):
		self.mylib.print_hello()

	def test_print_cstring_callable(self):
		self.mylib.print_cstring(b'hello too')

	def test_fill_string(self):
		str_len = 10
		string = self.mylib.ffi.new('char[]', str_len + 1)
		self.mylib.fill_string(string, str_len, b'c')
		self.assertEqual(b'cccccccccc', self.mylib.ffi.string(string))

	def test_MyType_instantiable(self):
		mt = self.mylib.ffi.new('MyType*')
		self.assertEqual(0, mt.value)
		mt.value = 1
		self.assertEqual(1, mt.value)
