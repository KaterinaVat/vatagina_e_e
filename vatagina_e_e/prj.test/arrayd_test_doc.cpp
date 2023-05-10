#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <arrayd/arrayd.hpp>

TEST_CASE("[arrayd] - ArrayD size and capasity") {
    ArrayD ab(6);
    CHECK(ab.ssize() == 6);

    ab.resize(5);
    CHECK(ab.ssize() == 5);

    ArrayD a(1);
    CHECK(a[0] == 0);

    a.insert(1,1);
    CHECK(a[1] == 1);

    a.insert(2, 2);
    CHECK(a[2] == 2);

    a.remove(2);
    CHECK(a.ssize() == 2);   
}
