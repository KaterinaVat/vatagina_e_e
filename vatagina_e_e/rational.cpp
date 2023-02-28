#include <iostream>
#include <sstream>
#include <exception>
#include "rational.h"
using namespace std;

/*
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

	std::ostream& writeTo(std::ostream& ostrm) const;

	std::istream& readFrom(std::istream& istrm);

	std::ostream& operator<< (std::ostream& out) {
		out << this->p << this->slash << this->q;
		return out;
	}
	std::istream& operator>> (std::istream& istrm) {
		return readFrom(istrm);
	}

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
	int getP(Rational& const rhs);
	int getQ(Rational& const rhs);

private:
	int32_t p = 0;
	int32_t q = 1;
	static const char slash = '/';
};
*/


std::ostream& Rational::write(std::ostream& ostrm) const {
	ostrm << p << slash << q;
	return ostrm;
}
std::istream& Rational::read(std::istream& istrm) {
	int32_t num = 0;
	char separator = 0;
	int32_t den = 1;
	istrm >> num >> separator >> den;
	if (istrm.good()) {
		if (den <= 0) {
			throw invalid_argument("Expected positive denumerator");
		}
		if (separator != Rational::slash) {
			throw invalid_argument("Expected / symbol");
		}
		p = num;
		q = den;

	}
	else {
		istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
	return rhs.write(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	return rhs.read(istrm);

}

Rational Rational::operator+(Rational& const rhs) {
	p = p * rhs.q + rhs.p * q;
	q = rhs.q * q;
	reducing(*this);
	return *this;
}
Rational Rational::operator- (Rational& const rhs) {
	p = p * rhs.q - rhs.p * q;
	q = rhs.q * q;
	reducing(*this);
	return *this;
}
Rational Rational::operator*(Rational& const rhs) {
	p = rhs.p * p;
	q = rhs.q * q;
	reducing(*this);
	return *this;
}
Rational Rational::operator/ (Rational& const rhs) {
	if ((rhs.p == 0) || (q == 0)) {
		throw exception("Division by zero!");
	}
	else {
		p = p * rhs.q;
		q = rhs.p * q;

		reducing(*this);
		return *this;
	}
}
void Rational::reducing(Rational& rhs) {
	int32_t devider = 1;
	int32_t max_number = 1;
	if (rhs.p >= rhs.q) {
		max_number = rhs.p;
	}
	else {
		max_number = rhs.q;
	}
	int32_t counter = max_number;
	int32_t ans = 1;
	while (counter > 0) {
		if ((rhs.p % counter == 0) && (rhs.q % counter == 0)) {
			ans = counter;
			break;
		}
		else {
			counter -= 1;
		}
	}
	rhs.p /= ans;
	rhs.q /= ans;
}
Rational Rational::operator- () {
	p = -p;
	q = q;
	reducing(*this);
	return (*this);
}
Rational Rational::operator+=(Rational& const rhs) {
	p = rhs.p * q + rhs.q * p;
	q = rhs.q * q;
	reducing(*this);
	return *this;
}
Rational Rational::operator-=(Rational& const rhs) {
	p = rhs.p * q - rhs.q * p;
	q = rhs.q * q;
	reducing(*this);
	return *this;
}
Rational Rational::operator*=(Rational& const rhs) {
	p = rhs.p * p;
	q = rhs.q * q;
	reducing(*this);
	return *this;
}
Rational Rational::operator/=(Rational& const rhs) {
	Rational temp{ 0,1 };
	Rational temp0{ 0,1 };
	temp = rhs;
	temp0 = { p,q };
	p = temp0.p * temp.q;
	q = temp0.q * temp.p;
	reducing(*this);
	return *this;
}
bool Rational::operator==(Rational& const rhs) {
	return (p == rhs.p) && (q == rhs.q);
bool Rational::operator!=(Rational& const rhs) {
	if ((p * rhs.q) != (rhs.p * q)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator> (Rational& const rhs) {
	if ((p * rhs.q) > (rhs.p * q)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator< (Rational& const rhs) {
	if ((p * rhs.q) < (rhs.p * q)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator>= (Rational& const rhs) {
	if ((p * rhs.q) >= (rhs.p * q)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator<= (Rational& const rhs) {
	if ((p * rhs.q) <= (rhs.p * q)) {
		return true;
	}
	else {
		return false;
	}
}

/*
int main() {
	using namespace std;

	try {
		cout << "Arifmetic operations" << endl;
		Rational fraction_one(24, 8);
		Rational fraction_second(12, 36);
		cout << fraction_one << " + " << fraction_second << " = " << fraction_one + fraction_second << endl;
		cout << fraction_one << " - " << fraction_second << " = " << fraction_one - fraction_second << endl;
		cout << fraction_one << " * " << fraction_second << " = " << fraction_one * fraction_second << endl;
		cout << fraction_one << " / " << fraction_second << " = " << fraction_one / fraction_second << endl;

		cout << "Arifmetic operations of types { +=, -=, *=, /= }" << endl;
		Rational a(1, 1);
		a = fraction_one;
		a += fraction_second;
		cout << fraction_one << " + " << fraction_second << " += " << a << endl;
		a = fraction_one;
		a -= fraction_second;
		cout << fraction_one << " - " << fraction_second << " -= " << a << endl;
		a = fraction_one;
		a *= fraction_second;
		cout << fraction_one << " * " << fraction_second << " *= " << a << endl;
		a = fraction_one;
		a /= fraction_second;
		cout << fraction_one << " / " << fraction_second << " /= " << a << endl;

		cout << "Unary minus" << endl;
		cout << fraction_one << " = " << -fraction_one << endl;

		cout << "Equality - Inequality check operations" << endl;
		cout << fraction_one << " == " << fraction_second << "   " << (fraction_one == fraction_second) << endl;
		cout << fraction_one << " != " << fraction_second << "   " << (fraction_one != fraction_second) << endl;
		cout << fraction_one << " < " << fraction_second << "   " << (fraction_one < fraction_second) << endl;
		cout << fraction_one << " <= " << fraction_second << "   " << (fraction_one <= fraction_second) << endl;
		cout << fraction_one << " > " << fraction_second << "   " << (fraction_one > fraction_second) << endl;
		cout << fraction_one << " >= " << fraction_second << "   " << (fraction_one >= fraction_second) << endl;

		Rational fr_test(0, 1);							//ввод дроби
		cout << "Write the rational number " << endl;
		cin >> fr_test;
		cout << fr_test << endl;

		Rational first(6, 9);							//проверка исключения при делении на ноль
		Rational second(5, 7);
		Rational third(5, 7);
		cout << first << " / (" << second << " - " << third << ")" << endl;

		//cout << (first / (second - third)) << endl;
		Rational ans(1, 0);
		ans = second - third;
		ans = first / ans;
		cout << ans << endl;
	}
	catch (const invalid_argument& ar) {
		cout << "Expected positive denumerator" << endl;
	}
	catch (const exception& ex) {
		cout << "Division by zero!" << endl;
	}
	}
	*/
