/**
* Class:     Complex
* Library:   MATH
* 
* Overview:  A class to implement a complex number.
*
*/

/*----------  Program Includes  ---------------*/
#include "Complex.h"

/*---------  System Includes    ---------------*/
#include <iostream>
#include <cmath>

/*----------  Implementation  -----------------*/

namespace dw {
   
const double HALF_PI = 1.5707963;
const double PI = 3.1415927;

/*----------  Public Functions  ---------------*/
   
Complex::Complex(const Complex& other)
{
   set(other.mR, other.mI);
}

Complex& Complex::operator=(const Complex& other)
{
   set(other.mR, other.mI);
   return *this;
}

Complex& Complex::operator+=(const Complex& rhs)
{
   set(mR + rhs.mR, mI + rhs.mI);
   return *this;
}

Complex& Complex::operator-=(const Complex& rhs)
{
   set(mR - rhs.mR, mI - rhs.mI);
   return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
   int term1 = mR * rhs.mR;
   int term2 = mR * rhs.mI;
   int term3 = mI * rhs.mR;
   int term4 = mI * rhs.mI;
   
   // Calculate the real component. term 4 has i squared which equals -1.
   mR = term1 + (term4*-1);
   
   // Calculate the imaginary component
   mI = term2 + term3;
   
   return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
   *this = operator/(*this, rhs);
   
   return *this; 
}


double Complex::magnitude() const
{
   if(mMagnitude == 0.0) {
      mMagnitude = std::sqrt(mR*mR + mI*mI);
   }
   
   return mMagnitude;
}


double Complex::angleRad() const
{
   if(mAngle == 0.0) {
      if(mR == 0.0 && mI == 0.0) {
         // Do nothing
      }
      else if(mR == 0.0 && mI > 0.0) {
         mAngle = HALF_PI;
      }
      else if(mR == 0.0 && mI < 0.0) {
         mAngle = -HALF_PI;
      }
      else if (mR > 0.0) {
         mAngle = std::atan(mI/mR);
      }
      else if(mR < 0.0 && mI >= 0.0)
      {
         mAngle = std::atan(mI/mR) + PI;
      }
      else {
         mAngle = std::atan(mI/mR) - PI;            
      }
   }
      
   if(mAngle < 0.0) {
      mAngle = (2.0 * PI) + mAngle;
   }
   
   return mAngle;
}


/*---------  Private Functions  ---------------*/
void Complex::set(double r, double i)
{
   mR = r;
   mI = i;
}


bool operator==(const Complex& lhs, const Complex& rhs)
{
   return (lhs.mR == rhs.mR && lhs.mI == rhs.mI);
}

bool operator!=(const Complex& lhs, const Complex& rhs)
{
   return !(lhs == rhs);
}

const Complex operator+(const Complex& lhs, const Complex& rhs)
{
      Complex x;
      x.mR = lhs.mR + rhs.mR;
      x.mI = lhs.mI + rhs.mI;
      
      return x;
}

const Complex operator-(const Complex& lhs, const Complex& rhs)
{
      Complex x;
      x.mR = lhs.mR - rhs.mR;
      x.mI = lhs.mI - rhs.mI;
      
      return x;
}

const Complex operator-(const Complex& rhs)
{
   Complex x;
   x.mR = -rhs.mR;
   x.mI = -rhs.mI;
   
   return x;
}

const Complex operator*(const Complex& lhs, const Complex& rhs)
{
   Complex x;
   
   int term1 = lhs.mR * rhs.mR;
   int term2 = lhs.mR * rhs.mI;
   int term3 = lhs.mI * rhs.mR;
   int term4 = lhs.mI * rhs.mI;
   
   // Calculate the real component. term 4 has i squared which equals -1.
   x.mR = term1 + (term4*-1);
   
   // Calculate the imaginary component
   x.mI = term2 + term3;
   
   return x;
}

const Complex operator/(const Complex& lhs, const Complex& rhs)
{
   Complex result;
   
   // First find the conjugate of the right hand side
   Complex conjugate(rhs.mR, -rhs.mI);
   
   // Multiply the numerator and denominator by the conjugate
   Complex numerator = lhs * conjugate;
   Complex denominator = rhs * conjugate;
   
   // denominator should have imaginary component of 0 and real component not 0
   if(denominator.mI != 0.0) {
      std::cout << "ERROR in algorithm\n";
   }
   
   if(denominator.mR == 0.0) {
      std::cout << "ERROR divide by 0\n";
   }
   else {
      // denominator should have an imaginary part of 0 at this point. Divide the 
      // numerator by the real portion of the denominator.
      result.mR = numerator.mR / denominator.mR;
      result.mI = numerator.mI / denominator.mR;
   }
   
   return result; 
   
}

std::ostream& operator<<(std::ostream& ostr, const Complex& complexIn)
{
   //ostr << complexIn.mR << " + " << complexIn.mI << "i";
   ostr << complexIn.mR;
   if(complexIn.mI < 0.0) {
      ostr << " - " << -complexIn.mI;
   }
   else {
      ostr << " + " << complexIn.mI;
   }
      
   ostr << "i";
      
   return ostr;
}

} // end namespace
