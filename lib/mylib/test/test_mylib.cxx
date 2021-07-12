#include <gtest/gtest.h>

#include <mylib.h>

using std::size_t;

TEST(MyLib, print_hello) {
	print_hello();
}

TEST(MyLib, print_cstring) {
	print_cstring("hello too");
}

TEST(MyLib, fill_string) {
	static const size_t str_len = 10;
	char str[str_len + 1]{};
	fill_string(str, str_len, 'c');
	ASSERT_STREQ("cccccccccc", str);
}
