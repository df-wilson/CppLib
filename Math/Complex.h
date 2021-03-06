/**
 * @class   Complex
 *
 * @author  Dean Wilson
 * @version 1.1
 * @date    Nov 24, 2015
 *
 * Library  MATH
 *
 * A class to represent a complex number. 
 */

#ifndef COMPLEX_H
#define COMPLEX_H

/*---------  System Includes  -----------------*/

#include <ostream>


namespace dw {
  
/*---------  Class Definition  ----------------*/

class Complex
{
public:
   /*---------  Public Methods  ------------------*/
   
   Complex(double r=0, double i=0);
   virtual ~Complex() {}
    
    Complex(const Complex& other);
    Complex& operator=(const Complex& other);
 
    Complex& operator+=(const Complex& rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator/=(const Complex& rhs);
    
    /**
     * Return the real part of the complex number.
     * 
     * @return double
     */
    double getI() const {return mI;}
    
    
    /**
     * Return the imaginary part of the complex number.
     * 
     * @return double
     */
    double getR() const {return mR;}

    
    /**
     * Get the polar form magnitude.
     * 
     * @return double
     */
    double magnitude() const;
    
    
    /**
     * Get the polar form angle in radians.
     * 
     * @return double
     */
    double angleRad() const;
    
    
    /**
     * Equality comparison operator 
     * 
     * @param complex other
     * @return bool
     */
    friend bool operator==(const Complex& lhs, const Complex& rhs);

    /**
     * Inquality comparison operator 
     * 
     * @param complex other
     * @return bool
     */
    friend bool operator!=(const Complex& lhs, const Complex& rhs);

    friend const Complex operator+(const Complex& lhs, const Complex& rhs);
    friend const Complex operator-(const Complex& lhs, const Complex& rhs);
    friend const Complex operator-(const Complex& rhs);
    friend const Complex operator*(const Complex& lhs, const Complex& rhs);
    friend const Complex operator/(const Complex& lhs, const Complex& rhs);
    friend std::ostream& operator<<(std::ostream& ostr, const Complex& complexIn);
    
private:
   /*---------  Private Methods  -----------------*/
   
   void set(double r, double i);
  
   
   /*---------  Private Data     -----------------*/
   
   double mI;
   double mR;
   double mMagnitude = 0.0;
   double mAngle = 0.0;
};

} // End namespace

#endif // COMPLEX_H
