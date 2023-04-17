

add_executable(rational_test_doc rational_test_doc.cpp)
target_link_libraries(rational_test_doc rational)
add_test(NAME rational_test_doc COMMAND rational_test_doc)

add_executable(arrayd_test arrayd_test.cpp)
target_link_libraries(arrayd_test arrayd)
add_test(NAME arrayd_test COMMAND arrayd_test)

add_executable(arrayt_test arrayt_test.cpp)
target_link_libraries(arrayt_test INTERFACE arrayt)
add_test(NAME arrayt_test COMMAND arrayt_test)


