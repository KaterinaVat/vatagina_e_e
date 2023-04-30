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
	//Rational(const Rational&&)=default;
	Rational(const int32_t num) noexcept;
	Rational(const int32_t num, const int32_t denom);
	Rational& operator=(const Rational&) ;
	~Rational() = default;
	std::ostream& write(std::ostream& ostrm) const;
	std::istream& read(std::istream& istrm);


	void reducing();
	
	
	Rational operator++() noexcept;
	Rational operator++(int) noexcept;
	Rational operator--() noexcept;
	Rational operator--(int) noexcept;
	Rational operator- () noexcept;
	Rational operator+=(const Rational& rhs) noexcept;
	Rational operator-=(const Rational& rhs) noexcept;
	Rational operator*=(const Rational& rhs) noexcept;
	Rational operator/=(const Rational& rhs);
	
	Rational operator+(const int lhs) noexcept;
	Rational operator-(const int lhs) noexcept;
	bool operator==( const Rational& rhs) const noexcept;
	bool operator!=(const Rational& rhs)  const noexcept;
	bool operator> (const Rational& rhs)  const noexcept;
	bool operator< ( const Rational& rhs)  const noexcept;
	bool operator>= (const Rational& rhs)  const noexcept;
	bool operator<= ( const Rational& rhs)  const noexcept;		

private:
	int32_t p_{ 0 };
	int32_t q_{ 1 };
	static const char slash{ '/' };
};

std::istream& operator>>(std::istream& istrm, Rational& rhs);
std::ostream& operator<<(std::ostream& out, const Rational& rhs);

inline Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
	return Rational(lhs) += rhs;
}

inline Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
	return Rational(lhs) -= rhs;
}

inline Rational operator/(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs) /= rhs;
}

inline Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
	return Rational(lhs) *= rhs;
}
#endif 
