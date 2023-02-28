# CMakeList.txt: проект CMake для vatagina_e_e; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("rational_lib")

include_directories(.)

add_subdirectory(rational)

add_executable (rational.test 
	test.cpp 
)
target_link_libraries(rational.test rational)


add_executable (rational.doctest
	rational.doctest.cpp	
)
target_link_libraries(rational.doctest rational)