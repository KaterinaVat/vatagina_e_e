#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "rational\rational.hpp"


TEST_CASE("INICIALIZATION") {
	CHECK(Rational() == Rational(0, 1));
	CHECK(Rational(3) == Rational(3, 1));
	CHECK(Rational(10, 4) == Rational(5, 2));
	CHECK(Rational(5, 4) == Rational(5, 4));
	CHECK(Rational(-5, 4) == Rational(-5, 4));
	CHECK(Rational(-5, -4) == Rational(5, 4));
	CHECK(Rational(5, -4) == Rational(-5, 4));
	CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("ARIFMETIC OPERATIONS +") {
	CHECK((Rational(2, 5) + Rational(1, 5)) == Rational(3, 5));
	CHECK((Rational(1, 3) + Rational(2, 5)) == Rational(11, 15));
	CHECK((Rational(3, 8) + Rational(3, 6)) == Rational(7, 8));
	CHECK((Rational(3, 9) + 1) == Rational(4, 3));
	CHECK((Rational(-3, 8) + Rational(3, 6)) == Rational(1, 8));
}
TEST_CASE("ARIFMETIC OPERATIONS -") {
	CHECK((Rational(16,18) - Rational(2,18)) == Rational(7,9));
	CHECK((Rational(4,9) - Rational(3,10)) == Rational(13,90));
	CHECK((Rational(171,20) - 1) == Rational(151,20));
	CHECK((Rational(18 ,19) - Rational(3, 19)) == Rational(15, 19));
}

TEST_CASE("ARIFMETIC OPERATIONS *") {
	CHECK((Rational(2, 5) * Rational(6, 7)) == Rational(12, 35));
	CHECK((Rational(3, 8) * Rational(16, 27)) == Rational(2, 9));
	CHECK((Rational(-2, 5) * Rational(6, 7)) == Rational(-12, 35));
	CHECK((Rational(-2, 5) * Rational(-6, 7)) == Rational(12, 35));
}

TEST_CASE("ARIFMETIC OPERATIONS /") {
	CHECK((Rational(12, 35) / Rational(4, 7)) == Rational(3, 5));
	CHECK((Rational(-12, 35) / Rational(4, 7)) == Rational(-3, 5));
}

TEST_CASE("++ --") {
	CHECK((++Rational(3, 5)) == Rational(8, 5));
	CHECK((--Rational(18, 4)) == Rational(7, 2));
}