#pragma once

#ifndef RATIONAL_LIB
#define RATIONAL_LIB


#include <iosfwd>
#include <cstdint>
#include <numeric>

class Rational {
public:
	Rational() = default;
	Rational(const Rational&) = default;
	Rational(const int32_t num) noexcept;
	Rational(const int32_t num, const int32_t denom);
	Rational& operator=(const Rational&) = default;
	~Rational() = default;
	std::ostream& write(std::ostream& ostrm) const;
	std::istream& read(std::istream& istrm);


	Rational reducing(Rational& rhs);
	Rational completing(Rational& rhs);
	int32_t num() const noexcept { return p_; }
	int32_t denom() const noexcept { return q_; }
	Rational operator++() noexcept;
	Rational operator--() noexcept;
	Rational operator- () noexcept;
	Rational operator+=(const Rational& rhs) noexcept;
	Rational operator-=(const Rational& rhs) noexcept;
	Rational operator*=(const Rational& rhs) noexcept;
	Rational operator/=(const Rational& rhs);
	bool operator==(const Rational& rhs) const noexcept;
	bool operator!=(const Rational& rhs)  const noexcept;
	bool operator> (const Rational& rhs)  const noexcept;
	bool operator< (const Rational& rhs)  const noexcept;
	bool operator>= (const Rational& rhs)  const noexcept;
	bool operator<= (const Rational& rhs)  const noexcept;
	Rational operator+(const int lhs) noexcept;
	Rational operator-(const int lhs) noexcept;
	Rational operator+(Rational& const lhs) noexcept;
	Rational operator-(Rational& const lhs) noexcept;
	Rational operator*(Rational& const lhs) noexcept;
	Rational operator/(Rational& const lhs);
private:
	int32_t p_{ 0 };
	int32_t q_{ 1 };
	static const char slash{ '/' };
};

std::istream& operator>>(std::istream& istrm, Rational& rhs);
std::ostream& operator<<(std::ostream& out, const Rational& rhs);
#endif 