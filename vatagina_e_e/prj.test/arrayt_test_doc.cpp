
#include <iostream>
#include "arrayt/arrayt.hpp"


typedef double T;
TEST_CASE("[arrayt] - ArrayT size and capasity") {
    ArrayT<T> ab(6);
    CHECK(ab.ssize() == 6);

    ab.resize(5);
    CHECK(ab.ssize() == 5);

    ArrayT<T> a(1);
    CHECK(a[0] == 0);

    a.insert(1, 1);
    CHECK(a[1] == 1);

    a.insert(2, 2);
    CHECK(a[2] == 2);

    a.remove(2);
    CHECK(a.ssize() == 2);
}
