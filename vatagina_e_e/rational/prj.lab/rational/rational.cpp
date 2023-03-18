#include <iostream>
#include <sstream>
#include <exception>
#include "rational/rational.hpp"
#include <cstdint>
#include <cmath>
#include <algorithm>

Rational::Rational(const int32_t num) noexcept {
	p_ = num;
	q_ = 1;
};

Rational::Rational(const int32_t num, const int32_t denum) {
	p_ = num;
	q_ = denum;
	if (q_ == 0)
		throw std::invalid_argument{ "Zero Denominator" };
	reducing(*this);
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
	if ((den > 0) && (separator == Rational::slash)) {
		istrm.good();
		if (istrm.good()) {
			p_ = num;
			q_ = den;
			reducing(*this);
		}
		return istrm;
	}
	else {
		istrm.setstate(std::ios_base::failbit);
	}
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

Rational Rational::operator+(Rational& const lhs) noexcept {
	p_ = lhs.p_ * q_ + lhs.q_ * p_;
	q_ = lhs.q_ * q_;
	reducing(*this);
	return *this;
}
Rational Rational::operator-(Rational& const lhs) noexcept {
	p_ = lhs.q_ * p_ - lhs.p_ * q_;
	q_ = lhs.q_ * q_;
	reducing(*this);
	return *this;
}
Rational Rational::operator*(Rational& const lhs) noexcept {
	p_ = p_ * lhs.p_;
	q_ = q_ * lhs.q_;
	reducing(*this);
	return *this;
}
Rational Rational::operator/(Rational& const lhs) {
	Rational temp = lhs;
	p_ = p_ * lhs.q_;
	q_ = q_ * lhs.p_;
	reducing(*this);
	return *this;
}
Rational Rational::operator+(const int lhs) noexcept {
	p_ += q_ * lhs;
	return *this;
}
Rational Rational::operator-(const int lhs) noexcept {
	p_ -= q_ * lhs;
	return *this;
}
Rational Rational::completing(Rational& rhs) {
	if ((rhs.q_ < 0) && (rhs.p_ < 0)) {
		p_ = abs(rhs.p_);
		q_ = abs(rhs.q_);
	}
	else {
		if (rhs.q_ < 0) {
			p_ = -rhs.p_;
			q_ = abs(rhs.q_);
		}
	}
	return (*this);
}

Rational Rational::reducing(Rational& rhs) {
	completing(rhs);
	int32_t counter = std::max(rhs.p_, rhs.q_);
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
	return (rhs);
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












