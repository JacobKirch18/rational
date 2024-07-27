#include <gtest/gtest.h>
#include "rational.hpp"

TEST(DefaultCtor, setsValueToZero) {

	Rational r;
	EXPECT_EQ(r.num(), 0);
	EXPECT_EQ(r.den(), 1);

}

TEST(ValueCtor, initializesWithCorrectValue) {

	Rational r1 = { 1, 2 };
	EXPECT_EQ(r1.num(), 1);
	EXPECT_EQ(r1.den(), 2);

	Rational r2 = { 4, 8 };
	EXPECT_EQ(r2.num(), 1);
	EXPECT_EQ(r2.den(), 2);

}

TEST(Setters, setCorrectValues) {

	Rational r;

	r.den(12);
	EXPECT_EQ(r.num(), 0);
	EXPECT_EQ(r.den(), 1);

	r.num(4);
	EXPECT_EQ(r.num(), 4);
	EXPECT_EQ(r.den(), 1);

	r.den(-8);
	EXPECT_EQ(r.num(), -1);
	EXPECT_EQ(r.den(), 2);

}

TEST(MathOps, calculateCorrectly) {

	Rational r1 = { 3, 4 };
	Rational r2 = { 5, 6 };
	Rational r3;

	r3 = r1 + r2;
	EXPECT_EQ(r3.num(), 19);
	EXPECT_EQ(r3.den(), 12);

	r3 = r1 - r2;
	EXPECT_EQ(r3.num(), -1);
	EXPECT_EQ(r3.den(), 12);

	r3 = r1 * r2;
	EXPECT_EQ(r3.num(), 5);
	EXPECT_EQ(r3.den(), 8);

	r3 = -r1;
	EXPECT_EQ(r3.num(), -3);
	EXPECT_EQ(r3.den(), 4);

	// divide by zero
	EXPECT_ANY_THROW(r3 = r2 / (r1 - r1));

}

TEST(MathAssignOps, assignCorrectly) {

	Rational r1 = { 3, 4 };
	Rational r2 = { 1, 3 };

	r1 *= r2;
	EXPECT_EQ(r1.num(), 1);
	EXPECT_EQ(r1.den(), 4);

	r1 += r2;
	EXPECT_EQ(r1.num(), 7);
	EXPECT_EQ(r1.den(), 12);

	++r1;
	EXPECT_EQ(r1.num(), 19);
	EXPECT_EQ(r1.den(), 12);

}

TEST(CompareOp, returnCorrectComparison) {

	Rational r1 = { 1, 2 };
	Rational r2 = { 2, 5 };
	bool b;

	b = r1 == r2;
	EXPECT_EQ(b, false);

	b = r1 > r2;
	EXPECT_EQ(b, true);

}

TEST(ConvertOps, convertCorrectly) {

	Rational r = 5;
	EXPECT_EQ(r.num(), 5);
	EXPECT_EQ(r.den(), 1);

	double d = (double)r;
	EXPECT_EQ(d, 5.0);

	r += 7;
	EXPECT_EQ(r.num(), 12);
	EXPECT_EQ(r.den(), 1);

	EXPECT_EQ(r, 12.0);

	r = 10.0 / 3.0;
	EXPECT_EQ(r.num(), 3333333);
	EXPECT_EQ(r.den(), 1000000);

	int i = (int)r;
	EXPECT_EQ(i, 3);

}

TEST(IoOps, scanProperly) {

	std::istringstream in("6 / 8");
	Rational r;
	in >> r;
	EXPECT_EQ(r.num(), 3);
	EXPECT_EQ(r.den(), 4);

}

TEST(IoOps, printProperly) {

	Rational r = { 3, 4 };
	std::ostringstream out;
	out << r;
	EXPECT_EQ(out.str(), "3/4");

}
