#include "rational.hpp"

Rational::Rational() {

	numerator = 0;
	denominator = 1;

}

Rational::Rational(int num, int den) {

	if (den != 0) {

		numerator = num;
		denominator = den;
		simplifyRational();

	}
	else {
		throw std::domain_error("Denominator cannot be zero");
	}

}

int Rational::num() const {
	return numerator;
}

void Rational::num(int num) {

	numerator = num;
	simplifyRational();

}

int Rational::den() const {
	return denominator;
}

void Rational::den(int den) {

	if (den != 0) {

		denominator = den;
		simplifyRational();

	}
	else {
		throw std::domain_error("Denominator cannot be zero");
	}

}

ostream& Rational::print(ostream& out) const {
	return out << numerator << '/' << denominator;
}

istream& Rational::scan(istream& in) {
	
	char slash;

	in >> numerator;

	if (in >> slash && slash != '/') {
		in.putback(slash);
		in.setstate(std::ios::failbit);
	}

	in >> denominator;

	simplifyRational();

	return in;

}

void Rational::simplifyRational() {

	if (numerator == 0) {
		denominator = 1;
	}
	else {

		int a = (numerator > denominator) ? numerator : denominator;
		int b = (numerator > denominator) ? denominator : numerator;

		int gcd = findGCD(a, b);

		numerator = numerator / gcd;
		denominator = denominator / gcd;

	}

	if (denominator < 0) {
		makeNumNeg();
	}

}

void Rational::makeNumNeg() {

	numerator = -numerator;
	denominator = -denominator;

}

int Rational::findGCD(int a, int b) {

	int gcd;

	if (a % b == 0) {
		gcd = b;
	}
	else {
		gcd = findGCD(b, a % b);
	}

	return gcd;

}

int Rational::findLCM(int a, int b) {
	return a / findGCD(a, b) * b;
}

bool Rational::operator <(Rational const& rhs) const {
	return ((double)numerator / (double)denominator) <
		((double)rhs.numerator / (double)rhs.denominator);
}

bool Rational::operator >(Rational const& rhs) const {
	return ((double)numerator / (double)denominator) > 
		((double)rhs.numerator / (double)rhs.denominator);
}

bool Rational::operator <=(Rational const& rhs) const {
	return ((double)numerator / (double)denominator) <=
		((double)rhs.numerator / (double)rhs.denominator);
}

bool Rational::operator >=(Rational const& rhs) const {
	return ((double)numerator / (double)denominator) >=
		((double)rhs.numerator / (double)rhs.denominator);
}

Rational Rational::operator +(Rational const& rhs) const {

	int lcm = findLCM(denominator, rhs.denominator);
	int numSum = numerator * (lcm / denominator) + rhs.numerator * (lcm / rhs.denominator);
	Rational r = { numSum, lcm };
	r.simplifyRational();
	return r;

}

Rational Rational::operator -(Rational const& rhs) const {

	int lcm = findLCM(denominator, rhs.denominator);
	int numSum = numerator * (lcm / denominator) - rhs.numerator * (lcm / rhs.denominator);
	Rational r = { numSum, lcm };
	r.simplifyRational();
	return r;

}

Rational Rational::operator *(Rational const& rhs) const {

	Rational r = { numerator * rhs.numerator, denominator * rhs.denominator };
	r.simplifyRational();
	return r;

}

Rational Rational::operator /(Rational const& rhs) const {

	Rational r = { numerator * rhs.denominator, denominator * rhs.numerator };
	r.simplifyRational();
	return r;

}

Rational Rational::operator ++(int) {

	Rational copy = *this;
	++(*this);
	return copy;

}

Rational Rational::operator --(int) {

	Rational copy = *this;
	--(*this);
	return copy;

}
