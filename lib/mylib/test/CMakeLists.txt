include(add_test)

add_test(test_mylib
	SOURCES
		test_mylib.cxx

	LIBRARIES
		mylib
)
