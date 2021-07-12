include(GoogleTest)

function(add_test target)
	set(flags "")
	set(single_option_args "")
	set(multi_option_args "SOURCES" "LIBRARIES")

	cmake_parse_arguments(PARSE_ARGV 1 arg "${flags}" "${single_option_args}" "${multi_option_args}")

	add_executable(${target}
		${arg_SOURCES}
	)
	target_link_libraries(${target}
		PRIVATE
			${arg_LIBRARIES}
			gtest_main
	)

	gtest_discover_tests(${target}
		DISCOVERY_TIMEOUT 10
	)
endfunction()
