#include <iostream>
#include <sstream>
#include <exception>
#include "rational/rational.hpp"
#include <cstdint>

Rational::Rational(const int32_t num) noexcept {
	p_ = num;
	q_ = 1;
};

Rational::Rational(const int32_t num, const int32_t denum) {
	p_ = num;
	q_ = denum;
	if (q_ == 0)
		throw std::domain_error{ "Zero Denominator" };
	reducing(*this);
};

/*Rational::Rational(const Rational& rhs) {
	p_ = rhs.p_;
	q_ = rhs.q_;
}

Rational& Rational::operator=(const Rational& r) {
	p_ = r.p_;
	q_ = r.q_;
	return *this;
}*/

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
		if ((den < 0) && (num < 0)) {
			p_ = abs(num);
			q_ = abs(den);
		}
		else {
			if (den < 0) {
				p_ = -num;
				q_ = abs(den);
			}
			else
			{
				p_ = num;
				q_ = den;
			}

		}
		reducing(*this);
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

Rational Rational::operator++() noexcept {
	return (*this += 1);
}
Rational Rational::operator--() noexcept {
	return (*this -= 1);
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
Rational Rational::operator+(const int lhs) noexcept {
	p_ += q_ * lhs;
	return *this;
}
Rational Rational::operator-(const int lhs) noexcept {
	p_ -= q_ * lhs;
	return *this;
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
Rational Rational::operator+=(const Rational& rhs) noexcept {
	p_ = rhs.p_ * q_ + rhs.q_ * p_;
	q_ = rhs.q_ * q_;
	reducing(*this);
	return *this;
}
Rational Rational::operator-=(const Rational& rhs) noexcept {
	p_ = rhs.q_ * p_ - rhs.p_ * q_;
	q_ = rhs.q_ * q_;
	reducing(*this);
	return *this;
}
Rational Rational::operator*=(const Rational& rhs) noexcept {
	p_ = rhs.p_ * p_;
	q_ = rhs.q_ * q_;
	reducing(*this);
	return *this;
}
Rational Rational::operator/=(const Rational& rhs) {
	if ((rhs.p_ == 0)) {
		throw std::exception("Division by zero!");
	}
	else {
		p_ *= rhs.q_;
		q_ *= rhs.p_;
		reducing(*this);
		return(*this);
	}
}

bool Rational::operator==(const Rational& rhs) const  noexcept {
	{

		return p_ == rhs.p_ && q_ == rhs.q_;
	}
}


bool Rational::operator!=(const Rational& rhs)  const noexcept {
	if ((p_ * rhs.q_) != (rhs.p_ * q_)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator> (const Rational& rhs)  const noexcept {
	if ((p_ * rhs.q_) > (rhs.p_ * q_)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator< (const Rational& rhs)  const noexcept {
	if ((p_ * rhs.q_) < (rhs.p_ * q_)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator>= (const Rational& rhs)  const noexcept {
	if ((p_ * rhs.q_) >= (rhs.p_ * q_)) {
		return true;
	}
	else {
		return false;
	}
}
bool Rational::operator<= (const Rational& rhs)  const noexcept {
	if ((p_ * rhs.q_) <= (rhs.p_ * q_)) {
		return true;
	}
	else {
		return false;
	}
}






















