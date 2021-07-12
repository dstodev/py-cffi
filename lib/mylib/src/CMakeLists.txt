add_library(mylib SHARED
	mylib.cxx
	mylib.h
)

target_include_directories(mylib
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_BINARY_DIR}  # for mylib_export.h
)

include(GenerateExportHeader)
generate_export_header(mylib)
