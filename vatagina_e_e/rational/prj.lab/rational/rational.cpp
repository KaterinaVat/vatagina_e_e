#include <iostream>
#include <sstream>
#include <exception>
#include "rational/rational.h"
#include <cstdint>

Rational::Rational(const int32_t num) noexcept {
	p_ = num;
};

Rational::Rational(const int32_t num, const int32_t denum) {
	p_ = num;
	q_ = denum;
};


std::ostream& Rational::write(std::ostream& ostrm) const {
	ostrm << p_ << slash << q_;
	return ostrm;
}
std::istream& Rational::read(std::istream& istrm) {
	int32_t num = 0;
	char separator = 0;
	int32_t den = 1;
	istrm >> num >> separator >> den;
	if (istrm.good()) {
		if (den == 0) {
			throw std::invalid_argument("Expected positive denumerator");
		}
		if (separator != Rational::slash) {
			throw std::invalid_argument("Expected / symbol");
		}
		if (den < 0) {
			p_ = -num;
			q_ = abs(den);
		}
		else {
			p_ = num;
			q_ = den;
		}
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

Rational operator+(Rational& const lhs, Rational& const rhs) noexcept {
	return Rational(lhs) += rhs;
}
Rational operator-(Rational& const lhs, Rational& const rhs) noexcept {
	return Rational(lhs) -= rhs;
}
Rational operator*(Rational& const lhs, Rational& const rhs) noexcept {
	return Rational(lhs) *= rhs;
}
Rational operator/(Rational& const lhs, Rational& const rhs) {
	return Rational(lhs) /= rhs;
}
void Rational::reducing(Rational& rhs) {
	int32_t devider = 1;
	int32_t max_number = 1;
	if (rhs.p_ >= rhs.q_) {
		max_number = rhs.p_;
	}
	else {
		max_number = rhs.q_;
	}
	int32_t counter = max_number;
	int32_t ans = 1;
	while (counter > 0) {
		if ((rhs.p_ % counter == 0) && (rhs.q_ % counter == 0)) {
			ans = counter;
			break;
		}
		else {
			counter -= 1;
		}
	}
	rhs.p_ /= ans;
	rhs.q_ /= ans;
}
Rational Rational::operator- () noexcept {
	p_ = -p_;
	q_ = q_;
	reducing(*this);
	return (*this);
}
Rational Rational::operator+=(Rational& const rhs) noexcept {
	p_ = rhs.p_ * q_ + rhs.q_ * p_;
	q_ = rhs.q_ * q_;
	reducing(*this);
	return *this;
}
Rational Rational::operator-=(Rational& const rhs) noexcept {
	p_ = rhs.p_ * q_ - rhs.q_ * p_;
	q_ = rhs.q_ * q_;
	reducing(*this);
	return *this;
}
Rational Rational::operator*=(Rational& const rhs) noexcept {
	p_ = rhs.p_ * p_;
	q_ = rhs.q_ * q_;
	reducing(*this);
	return *this;
}
Rational Rational::operator/=(Rational& const rhs) {
	if ((rhs.p_ == 0) || (q_ == 0)) {
		throw std::exception("Division by zero!");
	}
	else {
		Rational temp{ 0,1 };
		Rational temp0{ 0,1 };
		temp = rhs;
		temp0 = { p_,q_ };
		p_ = temp0.p_ * temp.q_;
		q_ = temp0.q_ * temp.p_;
		reducing(*this);
		return *this;
	}
}
bool Rational::operator==(Rational& const rhs)  {
	if (((p_ * rhs.q_) == (rhs.p_ * q_))) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator!=(Rational& const rhs) {
	if ((p_ * rhs.q_) != (rhs.p_ * q_)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator> (Rational& const rhs)  {
	if ((p_ * rhs.q_) > (rhs.p_ * q_)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator< (Rational& const rhs)  {
	if ((p_ * rhs.q_) < (rhs.p_ * q_)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator>= (Rational& const rhs) {
	if ((p_ * rhs.q_) >= (rhs.p_ * q_)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator<= (Rational& const rhs)  {
	if ((p_ * rhs.q_) <= (rhs.p_ * q_)) {
		return true;
	}
	else {
		return false;
	}
}






















/*#include <iostream>
#include <sstream>
#include <exception>
#include "rational/rational.h"
#include <cstdint>

Rational::Rational(const int32_t num, const int32_t denum) {
	p = num;
	q = denum;
};

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
			throw std::invalid_argument("Expected positive denumerator");
		}
		if (separator != Rational::slash) {
			throw std::invalid_argument("Expected / symbol");
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
};
std::istream& operator>>(std::istream& istrm, Rational& rhs) {
	return rhs.read(istrm);

}


Rational Rational::operator+(Rational& const lhs,Rational& const rhs) {
	return Rational(lhs) += rhs;
	
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
		throw std::exception("Division by zero!");
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
	if (((p * rhs.q) == (rhs.p * q))) {
		return true;
	}
	else {
		return false;
	}
}
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
*/