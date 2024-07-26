#pragma once

#include <iostream>
#include <stdexcept>

using std::ostream;
using std::istream;

class Rational {

public:

	Rational();
	Rational(int, int);

	int num() const;
	void num(int);

	int den() const;
	void den(int);

	ostream& print(ostream& out) const;
	istream& scan(istream& in);

	bool operator ==(Rational const& rhs) const = default;
	// implicit != operation with c++ 20

	bool operator <(Rational const&) const;

	bool operator >(Rational const&) const;

	bool operator <=(Rational const&) const;

	bool operator >=(Rational const&) const;

	Rational operator -() const { return { -numerator, denominator }; }

	Rational operator +(Rational const&) const;

	Rational operator -(Rational const&) const;

	Rational operator *(Rational const&) const;

	Rational operator /(Rational const&) const;

	Rational& operator +=(Rational const& rhs) { return *this = *this + rhs; }
										  
	Rational& operator -=(Rational const& rhs) { return *this = *this - rhs; }
										  
	Rational& operator *=(Rational const& rhs) { return *this = *this * rhs; }
										  
	Rational& operator /=(Rational const& rhs) { return *this = *this / rhs; }

	Rational& operator ++() { return *this = *this + 1; }

	Rational& operator --() { return *this = *this - 1; }

	Rational operator ++(int);

	Rational operator --(int);

	Rational(int number) : numerator(number), denominator(1) {}

	explicit operator int() const { return numerator / denominator;}

	Rational(double number) : numerator(number* doubleBase), denominator(doubleBase) { simplifyRational(); }

	explicit operator double() const { return (double)numerator / (double)denominator; }

private:

	int numerator;
	int denominator;

	static const int doubleBase = 1000000;

	void simplifyRational();

	void makeNumNeg();

	static int findGCD(int, int);

	static int findLCM(int, int);

};

inline Rational operator +(int const& i, Rational const& r) { return r + i; }

inline Rational operator -(int const& i, Rational const& r) { return (Rational)i - r; }

inline Rational operator *(int const& i, Rational const& r) { return r * i; }

inline Rational operator /(int const& i, Rational const& r) { return (Rational)i / r; }

inline Rational operator +(double const& d, Rational const& r) { return r + d; }

inline Rational operator -(double const& d, Rational const& r) { return (Rational)d - r; }

inline Rational operator *(double const& d, Rational const& r) { return r * d; }

inline Rational operator /(double const& d, Rational const& r) { return (Rational)d / r; }

inline bool operator <(int const& i, Rational const& r) { return r > i; }

inline bool operator >(int const& i, Rational const& r) { return r < i; }

inline bool operator <=(int const& i, Rational const& r) { return r >= i; }

inline bool operator >=(int const& i, Rational const& r) { return r <= i; }

inline bool operator <(double const& d, Rational const& r) { return r > d; }

inline bool operator >(double const& d, Rational const& r) { return r < d; }

inline bool operator <=(double const& d, Rational const& r) { return r >= d; }

inline bool operator >=(double const& d, Rational const& r) { return r <= d; }

inline ostream& operator <<(ostream& out, Rational const& r) { return r.print(out); }

inline istream& operator >>(istream& in, Rational& r) { return r.scan(in); }
