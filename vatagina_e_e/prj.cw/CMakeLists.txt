cmake_minimum_required (VERSION 3.18)

project ("filter")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_VERBOSE_MAKEFILE True)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file" -G Ninja)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}/bin.relwithdbg)

find_package(OpenCV)


add_subdirectory(filter)
add_subdirectory(example)
add_subdirectory(CTikz)


# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)


if(WIN32)
    set(OpenCV_RUNTIME_PATH "${OpenCV_DIR}/../../bin")
else()
    set(OpenCV_RUNTIME_PATH "${OpenCV_DIR}/../../lib")
endif()

if(INSTALL_TARGET)
    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*opencv_core*"
    )
    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*opencv_highgui*"
    )
    install(DIRECTORY "${OpenCV_RUNTIME_PATH}/"
      DESTINATION bin
      FILES_MATCHING PATTERN "*opencv_imgproc*"
    )
endif()

install(TARGETS filter ctikz  DESTINATION bin)
               # RUNTIME DESTINATION bin
                #LIBRARY DESTINATION lib 
                #ARCHIVE DESTINATION static)
install(DIRECTORY filter/include/ DESTINATION include/filter)
install(DIRECTORY ctikz/include/ DESTINATION include/ctikz)
install(FILES filter/filter.cpp DESTINATION filter)
install(FILES ctikz/ctikz.cpp DESTINATION ctikz)
install(TARGETS example DESTINATION bin)
install(DIRECTORY example/ DESTINATION bin/)
install(DIRECTORY cmake/ DESTINATION .)


install(FILES ctikz/include/ctikz/ctikz.hpp DESTINATION include/ctikz)
install(FILES CMakeLists.txt filter/CMakeLists.txt example/CMakeLists.txt ctikz/CMakeLists.txt DESTINATION .)





