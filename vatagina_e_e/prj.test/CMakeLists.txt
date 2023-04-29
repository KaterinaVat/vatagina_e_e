

add_executable(rational_test_doc rational_test_doc.cpp)
target_link_libraries(rational_test_doc rational doctest::doctest)
add_test(NAME rational_test_doc COMMAND rational_test_doc)

add_executable(arrayd_test_doc arrayd_test_doc.cpp)
target_link_libraries(arrayd_test_doc arrayd doctest::doctest)
add_test(NAME arrayd_test_doc COMMAND arrayd_test)

add_executable(arrayt_test_doc arrayt_test.cpp)
target_link_libraries(arrayt_test_doc arrayt doctest::doctest)
add_test(NAME arrayt_test_doc COMMAND arrayt_test)

