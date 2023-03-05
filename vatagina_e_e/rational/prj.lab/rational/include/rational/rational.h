#pragma once

#ifndef RATIONAL_LIB
#define RATIONAL_LIB


#include <iosfwd>
#include <cstdint>

class Rational {
public:
	Rational() = default;
	Rational(const Rational&) = default;
	Rational(const int32_t num) noexcept;
	Rational(const int32_t num, const int32_t denom);

	~Rational() = default;
	std::ostream& write(std::ostream& ostrm) const;
	std::istream& read(std::istream& istrm);

	void reducing(Rational& rhs);

	int32_t num() const noexcept { return p_; }
	int32_t denom() const noexcept { return q_; }

	Rational operator- () noexcept;
	Rational operator+=(Rational& const rhs) noexcept;
	Rational operator-=(Rational& const rhs) noexcept;
	Rational operator*=(Rational& const rhs) noexcept;
	Rational operator/=(Rational& const rhs);
	bool operator==(Rational& const rhs) ;
	bool operator!=(Rational& const rhs) ;
	bool operator> (Rational& const rhs);
	bool operator< (Rational& const rhs);
	bool operator>= (Rational& const rhs) ;
	bool operator<= (Rational& const rhs) ;


private:
	int32_t p_ = 0;
	int32_t q_ = 1;
	static const char slash = '/';
};
Rational operator+(Rational& const lhs, Rational& const rhs) noexcept;
Rational operator-(Rational& const lhs, Rational& const rhs) noexcept;
Rational operator*(Rational& const lhs, Rational& const rhs) noexcept;
Rational operator/(Rational& const lhs, Rational& const rhs);


std::istream& operator>>(std::istream& istrm, Rational& rhs);
std::ostream& operator<<(std::ostream& out, const Rational& rhs);
#endif 








/*#pragma once

#ifndef RATIONAL_LIB
#define RATIONAL_LIB


#include <iosfwd>
#include <cstdint>

class Rational {
public:
	Rational() = default;
	Rational(const Rational&) = default;
	Rational(const int32_t num, const int32_t denom);
	~Rational() = default;
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
*/
