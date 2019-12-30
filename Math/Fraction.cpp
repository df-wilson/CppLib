/**
 * Class:     Complex
 * Library:   MATH
 * 
 * Overview:  A class to implement a fraction.
*/

/*---------  Program Includes  ----------------*/
#include "Fraction.h"

/*----------  Implementation  -----------------*/

namespace dw {
   
/*----------  Public Methods  -----------------*/

Fraction::Fraction(int numerator, int denominator) 
         :mNumerator(numerator), mDenominator(denominator)
{
   normalize();
}


bool Fraction::operator==(const Fraction& rhs) const
{
   return (mNumerator == rhs.mNumerator && mDenominator == rhs.mDenominator); 
}


Fraction Fraction::operator+(const Fraction& rhs) const
{
   int lcd = lcm(mDenominator, rhs.mDenominator);
   int quotient = lcd/mDenominator;
   int quotiont2 = lcd/rhs.mDenominator;
   
   Fraction newFraction(mNumerator * quotient + rhs.mNumerator * quotiont2, lcd);
   
   return newFraction;
}


Fraction Fraction::operator-(const Fraction& rhs) const
{
   int lcd = lcm(mDenominator, rhs.mDenominator);
   int quotient = lcd/mDenominator;
   int quotiont2 = lcd/rhs.mDenominator;
   
   Fraction newFraction(mNumerator * quotient - rhs.mNumerator * quotiont2, lcd);
   
   return newFraction;
}


Fraction Fraction::operator*(const Fraction& rhs) const
{
   Fraction newFraction(mNumerator * rhs.mNumerator,
                        mDenominator * rhs.mDenominator);
   
   return newFraction;
}


Fraction Fraction::operator/(const Fraction& rhs) const
{
   // Take reciprocal of fractionIn and multiply to implement to avoid loss of precision.
   Fraction newFraction(mNumerator * rhs.mDenominator,
                        mDenominator * rhs.mNumerator);
   
   return newFraction;
}


/*---------  Private Methods  ------------------*/

void Fraction::normalize()
{
   if(mDenominator == 0 || mNumerator == 0) {
      mDenominator = 1;
      mNumerator   = 0;
   }
   
   // Negative sign always goes into numerator
   if(mDenominator < 0) {
      mDenominator *= -1;
      mNumerator   *= -1;
   }
   
   // factor out the greatest common factor
   int n = gcf(mNumerator, mDenominator);
   mDenominator /= n;
   mNumerator   /= n;
}


int Fraction::gcf(int a, int b) const
{
   if(b == 0) {
      return abs(a);
   } else {
      return gcf(b, a % b);
   }
}


int Fraction::lcm(int a, int b) const
{
   int n = gcf(a, b);
      
   return a / n * b;
}


/*---------  Friend functions  ----------------*/

std::ostream& operator<<(std::ostream& os, Fraction& fraction)
{
   os << fraction.mNumerator << "/" << fraction.mDenominator;
   return os;
}

} // End namespace dw
