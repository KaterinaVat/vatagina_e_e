add_library(filter filter.cpp include/filter/filter.hpp)

set_property(TARGET filter PROPERTY CXX_STANDARD 20)
target_include_directories(filter PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )
TARGET_LINK_LIBRARIES (filter ${OpenCV_LIBS})


include_directories(ctikz)
target_link_libraries(filter ctikz)

