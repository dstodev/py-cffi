add_library(mylib SHARED
	mylib.cxx
	mylib.h
)

target_include_directories(mylib
	PUBLIC
		${CMAKE_CURRENT_BINARY_DIR}
)
include(GenerateExportHeader)
generate_export_header(mylib)
