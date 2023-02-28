#ifndef RATIONAL_LIB
#define RATIONAL_LIB

#pragma once
#include <iosfwd>


class Rational {
public:
	Rational() {};
	Rational(const int32_t numerous)
	{
		p = numerous;
		q = 1;
	};
	Rational(const int32_t num, const int32_t den) {
		p = num;
		q = den;
	};

	std::ostream& write(std::ostream& ostrm) const;
	std::istream& read(std::istream& istrm);


	void reducing(Rational& rhs);
	Rational operator+(Rational& const rhs);
	Rational operator- (Rational& const rhs);
	Rational operator*(Rational& const rhs);
	Rational operator/ (Rational& const rhs);
	Rational operator- ();
	Rational operator+=(Rational& const rhs);
	Rational operator-=(Rational& const rhs);
	Rational operator*=(Rational& const rhs);
	Rational operator/=(Rational& const rhs);
	bool operator==(Rational& const rhs);
	bool operator!=(Rational& const rhs);
	bool operator> (Rational& const rhs);
	bool operator< (Rational& const rhs);
	bool operator>= (Rational& const rhs);
	bool operator<= (Rational& const rhs);


private:
	int32_t p = 0;
	int32_t q = 1;
	static const char slash = '/';
};

std::istream& operator>>(std::istream& istrm, Rational& rhs);
std::ostream& operator<<(std::ostream& out, const Rational& rhs);
#endif 