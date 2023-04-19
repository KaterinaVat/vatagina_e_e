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
	if (((num > 0) || (num < 0)) && (denum > 0)) {
		p_ = num;
		q_ = denum;
	}
	else {
		if ((num > 0) && (denum < 0)) {
			p_ = num * (-1);
				q_ = denum * (-1);
		}
		else {
			if ((num < 0) && (denum < 0)) {
				p_ = num * (-1);
				q_ = denum * (-1);
			}
		}
	}
	if (denum == 0)
		throw std::invalid_argument{ "Zero Denominator" };
	reducing();
};

std::ostream& Rational::write(std::ostream& ostrm) const {
	ostrm << p_ << slash << q_;
	return ostrm;
}
std::istream& Rational::read(std::istream& istrm) {
	char sym = ' ';
	while (std::isspace(istrm.peek())) { // isspace - проверка на проблел 
		sym = istrm.get();				// peek - возвращает следующий символ для чтения
	}									// get - считывает несколько символов из потока
	static const char minus{ '-' };
	bool fr_is_neg = false;
	if (istrm.peek() == minus) {
		fr_is_neg = true;
		sym = istrm.get();
	}


	while (std::isdigit(istrm.peek())) {
		sym = istrm.get();
		num *= 10;
		num += static_cast<int>(sym - '0');
	}

	if (sym == minus) {
		istrm.setstate(std::ios_base::failbit);
		return istrm;
	}

	if (istrm.peek() != Rational::slash) {
		istrm.setstate(std::ios_base::failbit);
		return istrm;
	}
	
	while (std::isdigit(istrm.peek())) {
		sym = istrm.get();
		denom *= 10;
		denom += static_cast<int>(sym - '0');
	}

	if (sym == '/') {
		istrm.setstate(std::ios_base::failbit);
		return istrm;
	}
	if (istrm.good() || istrm.eof()) {
		if (denom == 0) {
			istrm.setstate(std::ios_base::failbit);
			return istrm;
		} 
		p_ = num;
		q_ = denom;
		if (fr_is_neg){
		p_ = num*(-1);
		}
		reducing();
	}
	return istrm;
}
Rational& Rational::operator=(const Rational& rhs) {
    p_ = rhs.p_;
    q_ = rhs.q_;
    return *this;
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

Rational Rational::operator+(const int lhs) noexcept {
	p_ += q_ * lhs;
	return *this;
}
Rational Rational::operator-(const int lhs) noexcept {
	p_ -= q_ * lhs;
	return *this;
}

void Rational::reducing() {
	int32_t counter = std::min(p_, q_);
	int32_t ans = 1;
	while (counter > 0) {
		if ((p_ % counter == 0) && (q_ % counter == 0)) {
			ans = counter;
			break;
		}
		else {
			counter -= 1;
		}
	}
	p_ /= ans;
	q_ /= ans;
}
Rational Rational::operator- () noexcept {
	p_ = -p_;
	q_ = q_;
	reducing();
	return (*this);
}
Rational Rational::operator+=(const Rational& rhs) noexcept {
	p_ = rhs.p_ * q_ + rhs.q_ * p_;
	q_ = rhs.q_ * q_;
	reducing();
	return *this;
}
Rational Rational::operator-=(const Rational& rhs) noexcept {
		p_ = rhs.q_ * p_ - rhs.p_ * q_;
		q_ = rhs.q_ * q_;
	reducing();
	return *this;
}
Rational Rational::operator*=(const Rational& rhs) noexcept {
	p_ = rhs.p_ * p_;
	q_ = rhs.q_ * q_;
	reducing();
	return *this;
}
Rational Rational::operator/=(const Rational& rhs) {
	if ((rhs.p_ == 0)) {
		throw std::exception("Division by zero!");
	}
	else {
		p_ *= rhs.q_;
		q_ *= rhs.p_;
		reducing();
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
Rational Rational::operator++(int) {
    Rational tmp(*this);
    ++(*this);
    return tmp;
}
Rational Rational::operator--(int) {
    Rational tmp(*this);
    --(*this);
    return tmp;
}











