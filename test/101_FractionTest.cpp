#include "catch.hpp"

#include "../Math/Fraction.h"
#include <sstream>

using namespace dw;

TEST_CASE("Fraction test: Test constructor", "Math")
{
   // Should be 2 results
   Fraction fraction(3,4);
   REQUIRE(fraction.numerator()   == 3);
   REQUIRE(fraction.denominator() == 4);
   
   // Test default constructor
   Fraction fraction2;
   REQUIRE(fraction2.numerator()   == 0);
   REQUIRE(fraction2.denominator() == 1);
   
   // Ensure no 0 in the denominator
   Fraction fraction3(0,0);
   REQUIRE(fraction3.numerator()   == 0);
   REQUIRE(fraction3.denominator() == 1);
}

TEST_CASE("Fraction Test: Test copy constructor", "Math")
{
   Fraction fraction(3,4);
   Fraction fractionCopy(fraction);
   
   REQUIRE(fractionCopy.numerator()   == 3);
   REQUIRE(fractionCopy.denominator() == 4);
}

TEST_CASE("Fraction Test: Test assignment", "Math")
{
   Fraction fraction(3,4);
   Fraction fractionCopy = fraction;
   
   REQUIRE(fractionCopy.numerator()   == 3);
   REQUIRE(fractionCopy.denominator() == 4);
}

TEST_CASE("Fraction Test: operator==", "Math")
{
   Fraction fraction1(3,4);
   Fraction fraction2(6,8);
   Fraction fraction3(-3,4);
   Fraction fraction4(3,5);
   Fraction fraction5(5,4);
   
   REQUIRE(fraction1 == fraction2);
}

TEST_CASE("Fraction Test: Operator<<", "Math")
{
   Fraction fraction1(3,4);
   Fraction fraction2(3,-4);
   
   std::stringstream ss;
   ss << fraction1;
   REQUIRE(ss.str() == "3/4");
   
   std::stringstream ss2;
   ss2 << fraction2;
   REQUIRE(ss2.str() == "-3/4");
}

TEST_CASE("Fraction Test: Test negative sign always goes to numerator", "Math")
{
   Fraction fraction(3,-4);
   
   REQUIRE(fraction.numerator()   == -3);
   REQUIRE(fraction.denominator() == 4);
}

TEST_CASE("Fraction Test: Test fraction is normalized", "Math")
{
   Fraction fraction(300,400);
   
   REQUIRE(fraction.numerator()   == 3);
   REQUIRE(fraction.denominator() == 4);
}

TEST_CASE("Fraction Test: Test operator+", "Math")
{
   Fraction fraction(3, 4);
   Fraction fraction2(2, 4);
   
   Fraction newFraction = fraction + fraction2;
   REQUIRE(newFraction.numerator()   == 5);
   REQUIRE(newFraction.denominator() == 4);
   
   newFraction = fraction + Fraction(6,8);
   REQUIRE(newFraction.numerator()   == 3);
   REQUIRE(newFraction.denominator() == 2);
}

TEST_CASE("Fraction Test: Test operator-", "Math")
{
   Fraction fraction(3, 4);
   Fraction fraction2(2, 4);
   
   Fraction newFraction = fraction - fraction2;
   REQUIRE(newFraction.numerator()   == 1);
   REQUIRE(newFraction.denominator() == 4);
   
   newFraction = fraction - Fraction(8,8);
   REQUIRE(newFraction.numerator()   == -1);
   REQUIRE(newFraction.denominator() == 4);
}

TEST_CASE("Fraction Test: Test operator*", "Math")
{
   Fraction fraction(3, 4);
   Fraction fraction2(3, -4);
   
   Fraction newFraction = fraction * fraction2;
   REQUIRE(newFraction.numerator()   == -9);
   REQUIRE(newFraction.denominator() == 16);
   
   newFraction = fraction * Fraction(2,3);
   REQUIRE(newFraction.numerator()   == 1);
   REQUIRE(newFraction.denominator() == 2);
}

TEST_CASE("Fraction Test: Test operator/", "Math")
{
   Fraction fraction(3, 4);
   Fraction fraction2(2, 4);
   
   Fraction newFraction = fraction / fraction2;
   REQUIRE(newFraction.numerator()   == 3);
   REQUIRE(newFraction.denominator() == 2);
   
   newFraction = fraction / Fraction(2,3);
   REQUIRE(newFraction.numerator()   == 9);
   REQUIRE(newFraction.denominator() == 8);
}
