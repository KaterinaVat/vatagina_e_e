#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <arrayd/arrayd.hpp>

TEST_CASE("[arrayd] - ArrayD size and capasity") {
  ArrayD ab(6);
    CHECK(ab.ssize() == 6);

    ab.resize(5);
    CHECK(ab.ssize() == 5);

    ArrayD a(5);
    CHECK(a[0] == 0);

    a.insert(1, 1);
    CHECK(a[1] == 1);

    a.insert(2, 2);
    CHECK(a[2] == 2);

    ArrayD test_array(5);
    CHECK(test_array.ssize() == 5);

    std::ptrdiff_t last_size = test_array.ssize();
    test_array[0] = 1;
    test_array[1] = 2;
    test_array[2] = 3;
    test_array[3] = 4;
    test_array[4] = 5;
    test_array.remove(2);
    CHECK(test_array.ssize() == (last_size-1)); 
}
