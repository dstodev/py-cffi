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

TEST(MyLib, MyType_instantiable) {
	MyType mt{};
	ASSERT_EQ(0, mt.value);
	mt.value = 1;
	ASSERT_EQ(1, mt.value);
}
