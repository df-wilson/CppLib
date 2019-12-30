/**
 * @class   Fraction
 *
 * @author  Dean Wilson
 * @version 1.0
 * @date    Nov 24, 2015
 *
 * Library  MATH
 *
 * A class to represent a fraction. 
 */

#ifndef FRACTION_H
#define FRACTION_H

/*---------  System Includes  -----------------*/
#include <cstdlib>
#include <iostream>

namespace dw {
   
/*---------  Class Definition  ----------------*/
class Fraction
{
public:
   /*---------  Public Methods  ------------------*/
   
   Fraction(int numerator = 0, int denominator = 1);
   
   virtual ~Fraction() = default;
   
   int numerator() const
   {
      return mNumerator;
   }
   
   int denominator() const
   {
      return mDenominator;
   }
   
   bool operator==(const Fraction &other) const;
   Fraction operator+(const Fraction& rhs) const;
   Fraction operator-(const Fraction& rhs) const;
   Fraction operator*(const Fraction& rhs) const;
   Fraction operator/(const Fraction& rhs) const;
   
   friend std::ostream& operator<<(std::ostream& os, Fraction& fraction);
   
private:
   /*---------  Private Data     -----------------*/
   int mNumerator;
   int mDenominator;
   
   /*---------  Private Methods  -----------------*/
   void normalize();
   int gcf(int a, int b) const;
   int lcm(int a, int b) const;
};

} // End namespace dw

#endif // FRACTION_H
