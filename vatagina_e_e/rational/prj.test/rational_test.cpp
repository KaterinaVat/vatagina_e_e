#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <rational/rational.hpp>

TEST_CASE("[rational] - Rational ctor") {
	CHECK(Rational() == Rational(0, 1));
	CHECK(Rational(3) == Rational(3, 1));
	CHECK(Rational(-3) == Rational(-3, 1));
	CHECK(Rational(10, 6) == Rational(5, 3));
	CHECK(Rational(-10, 6) == Rational(-5, 3));
	CHECK(Rational(10, -6) == Rational(-5, 3));
	CHECK(Rational(-10, -6) == Rational(5, 3));
	CHECK_THROWS(Rational(1, 0));
}
//
//TEST_CASE("[rational] - Rational ctor"){
//	CHECK((Rational(1, 2) + Rational(2, 5)) == Rational(9, 10));
//	CHECK((Rational(1, 2) + Rational(-2, 5)) == Rational(1, 10));
//	CHECK((Rational(1, 2) + Rational(2, -5)) == Rational(1, 10));
//	CHECK((Rational(1, 2) + Rational(-2, -5)) == Rational(9, 10));
//}
//
//TEST_CASE("[rational] - Rational ctor") {
//	CHECK((Rational(121, 7) - Rational(6, 5)) == Rational(583, 35));
//	CHECK((Rational(121, 7) - Rational(-6, 5)) == Rational(647, 35));
//	CHECK((Rational(121, 7) - Rational(6, -5)) == Rational(647, 35));
//	CHECK((Rational(121, 7) - Rational(-6, -5)) == Rational(583, 35));
//}
//
//TEST_CASE("[rational] - Rational ctor") {
//	CHECK((Rational(1, 2) * Rational(2, 5)) == Rational(1, 5));
//	CHECK((Rational(1, 2) * Rational(-2, 5)) == Rational(-1, 5));
//	CHECK((Rational(1, 2) * Rational(2, -5)) == Rational(-1, 5));
//	CHECK((Rational(1, 2) * Rational(-2, -5)) == Rational(1, 5));
//}
