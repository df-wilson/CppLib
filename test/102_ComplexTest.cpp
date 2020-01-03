#include "catch.hpp"

#include "../Math/Complex.h"

TEST_CASE("Complex: Constructor test", "MATH")
{
   // Test default construction
   dw::Complex x;
   double real = x.getR();
   double imaginary = x.getI();
   
   REQUIRE(real == Approx(0.0));
   REQUIRE(imaginary == Approx(0.0));
   
   // Test construction with supplied values
   dw::Complex y(10.5, 15.0);
   real = y.getR();
   imaginary = y.getI();
   
   REQUIRE(real == Approx(10.5));
   REQUIRE(imaginary == Approx(15.0));
}

TEST_CASE("Complex: Assignment test", "MATH")
{
   dw::Complex x(101.15, 15.73);
   dw::Complex y(11.5, 5.7);
   
   double real = x.getR();
   double imaginary = x.getI();
   REQUIRE(real == Approx(101.15));
   REQUIRE(imaginary == Approx(15.73));
   
   real = y.getR();
   imaginary = y.getI();
   REQUIRE(real == Approx(11.5));
   REQUIRE(imaginary == Approx(5.7));

   y = x;
   real = y.getR();
   imaginary = y.getI();
   REQUIRE(real == Approx(101.15));
   REQUIRE(imaginary == Approx(15.73));
}

TEST_CASE("Complex: Equality test", "MATH")
{
   dw::Complex x;
   dw::Complex y;
   dw::Complex z(5.5, 6.5);
   
   REQUIRE(x == y);
   REQUIRE_FALSE(x == z);
   
   x = z;
   REQUIRE(x == z);
}

TEST_CASE("Complex: Inquality test", "MATH")
{
   dw::Complex x;
   dw::Complex y;
   dw::Complex z(5.5, 6.5);
   
   REQUIRE_FALSE(x != y);
   REQUIRE(x != z);
   
   x = z;
   REQUIRE_FALSE(x != z);
}

TEST_CASE("Complex: operator/", "Math")
{
   dw::Complex x(3, -2);
   dw::Complex y(5, 7);
   dw::Complex z;
   
   z = x/y;
   double real = z.getR();
   double imaginary = z.getI();
   REQUIRE(real == Approx(0.01351).margin(0.00001));
   REQUIRE(imaginary == Approx(-0.41891).margin(0.00001));
   
   dw::Complex x2(3, 2);
   dw::Complex y2(4, -3);
   z = x2/y2;
   real = z.getR();
   imaginary = z.getI();
   REQUIRE(real == Approx(0.24).margin(0.00001));
   REQUIRE(imaginary == Approx(0.68).margin(0.00001));
   
   dw::Complex x3(4, 5);
   dw::Complex y3(2, 6);
   z = x3/y3;
   real = z.getR();
   imaginary = z.getI();
   REQUIRE(real == Approx(0.95).margin(0.00001));
   REQUIRE(imaginary == Approx(-0.35).margin(0.00001));
   
   dw::Complex x4(4, 5);
   dw::Complex y4(0, 0);
   z = x4/y4;
   real = z.getR();
   imaginary = z.getI();
   REQUIRE(real == Approx(0.0).margin(0.00001));
   REQUIRE(imaginary == Approx(0.0).margin(0.00001));
}

TEST_CASE("Complex: operator/=", "Math")
{
   dw::Complex x(3, -2);
   dw::Complex y(5, 7);
   
   x /= y;
   double real = x.getR();
   double imaginary = x.getI();
   REQUIRE(real == Approx(0.01351).margin(0.00001));
   REQUIRE(imaginary == Approx(-0.41891).margin(0.00001));
   
   dw::Complex x2(3, 2);
   dw::Complex y2(4, -3);
   x2 /= y2;
   real = x2.getR();
   imaginary = x2.getI();
   REQUIRE(real == Approx(0.24).margin(0.00001));
   REQUIRE(imaginary == Approx(0.68).margin(0.00001));
   
   dw::Complex x3(4, 5);
   dw::Complex y3(2, 6);
   x3 /= y3;
   real = x3.getR();
   imaginary = x3.getI();
   REQUIRE(real == Approx(0.95).margin(0.00001));
   REQUIRE(imaginary == Approx(-0.35).margin(0.00001));
   
   dw::Complex x4(4, 5);
   dw::Complex y4(0, 0);
   x4 /= y4;
   real = x4.getR();
   imaginary = x4.getI();
   REQUIRE(real == Approx(0.0).margin(0.00001));
   REQUIRE(imaginary == Approx(0.0).margin(0.00001));
}
