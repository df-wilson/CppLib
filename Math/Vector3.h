/**
 * @class   Vector3
 * @brief   A 3D vector.
 * @author  Dean Wilson
 * @version 1.0
 * @date    March 3, 2014
 * Library  Math
 *
 * Math 3D vector implementation. Contains values x,y,z.
 * Can be used with ints, floats, etc, or classes that implement math operators
 * such as +, -, *, /, <, >, =.
 */

#ifndef VECTOR3_H
#define VECTOR3_H

/*---------  System Includes  -----------------*/
#include <cmath>
#include <iostream>

/*---------  Program Includes  ----------------*/
#include "mathutil.h"

/*---------  Class Definition  ----------------*/

namespace dw {

const double ZERO_TOLERANCE = 0.001;

template <typename T>
class Vector3 final
{
public:
   /*---------  Public Methods  ------------------*/

   /**
    * Constructors, Assignement operators, and destructor
    */
   Vector3() { mX = {}; mY = {}; mZ = {}; }
   Vector3(T x, T y, T z) : mX(x), mY(y), mZ(z) {}
   Vector3(const Vector3& rhs) = default;
   Vector3(Vector3&& rhs) = default;

   Vector3& operator=(const Vector3& rhs) = default;
   Vector3& operator=(Vector3&& rhs) = default;

   ~Vector3() = default;

   /**
    * Getters
    */
   T x() const { return mX; }
   T y() const { return mY; }
   T z() const { return mZ; }

   /**
    * Setters
    */
   void x(T x) { mX = x; }
   void y(T y) { mY = y; }
   void z(T z) { mZ = z; }

   /**
    * Sets the x, y and z values.
    *
    * @param x The x value
    * @param y The x value
    * @param z The x value
    * @return void
    */
   void set(T x, T y, T z) 
   {
       mX = x;
       mY = y;
       mZ = z;
   }

   /**
    * @brief Returns the length of the vector
    *
    * @return The length of the vector in the same units as the input parameters.
    */
   T length() const 
   {
      T length = sqrt((mX * mX) + (mY * mY) + (mZ * mZ));
      return length;
   }

   /**
    * @brief Implements the negate operator and returns the result.
    * The original object is not modified.
    *
    * @return A vector3 that is the negated version of this Vector3.
    */
   Vector3<T> operator-() const 
   {
       return Vector3(-mX, -mY, -mZ);
   }

private:
   /*---------  Private Methods  -----------------*/

   /*---------  Private Attributes  --------------*/
   T mX;
   T mY;
   T mZ;

};

/*---------  Non Class functions  ----------------*/

/**
 * @brief Finds the dot product of two vectors.
 *
 * @param v1 The first vector
 * @param v2 The second vector
 * @return The dot product of the two vectors.
 */
template<typename T>
double dotProduct(const Vector3<T>& v1, const Vector3<T>& v2) 
{
    return v1.x() * v2.x() +
           v1.y() * v2.y() +
           v1.z() * v2.z();
}

/**
 * @brief Implements the addition operator for Vector3 types. Returns a Vector3
 * that contains the result of v1 + v3 using standard vector addition.
 *
 * @param v1 The first vector
 * @param v2 The second vector
 * @return The dot product of the two vectors.
 */
template<typename T>
Vector3<T> operator+ (const Vector3<T>& v1, const Vector3<T>& v2) 
{
    T x = v1.x() + v2.x();
    T y = v1.y() + v2.y();
    T z = v1.z() + v2.z();

    return Vector3<T>(x, y, z);
}

/**
 * @brief Implements subtraction operator for Vector3 types. Returns a vector3
 * that contains the result of v1 - v2 using standard vector subtraction.
 *
 * @param v1 The first vector
 * @param v2 The second vector
 * @return Another vector that contains the result of v1 - v2.
 */
template<typename T>
Vector3<T> operator- (const Vector3<T>& v1, const Vector3<T> v2) 
{
    T x = v1.x() - v2.x();
    T y = v1.y() - v2.y();
    T z = v1.z() - v2.z();

    return Vector3<T>(x,y,z);
}

/**
 * @brief Implements the ostream operator. Output is in the form x y z
 *
 * @param streamOut The output stream
 * @param vector The vector to output
 * @return The output stream.
 */
template<typename T>
std::ostream& operator<<(std::ostream&  streamOut,
                         const Vector3<T>&  vector)
{
    streamOut << vector.x()
    << " " << vector.y()
    << " " << vector.z();

    return streamOut;
}

/**
* @brief Find the angle between two vectors in radians.
* 
* @param v1 The first vector.
* @param v2 The second vector
* @return the angle between the two vectors
*/
template <typename T>
double angleBetweenVectorsRadians(const Vector3<T>& v1, const Vector3<T>& v2) 
{
    float angleRadians = 0.0;
    float dotProductResult = dotProduct(v1, v2);

    if(isAlmostZero(v1.length(), ZERO_TOLERANCE)   ||
       isAlmostZero(v2.length(), ZERO_TOLERANCE))
    {
        angleRadians = 0.0;
    }
    else
    {
        float lCos = dotProductResult / (v1.length() * v2.length());
        angleRadians = acos(lCos);
    }

    return angleRadians;
}

/**
 * Check if two vectors are orthogonal.
 * 
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return true if the two vectors are orthogonal, false otherwise.
 */
template <typename T>
bool areOrthogonal(const Vector3<T>& v1, const Vector3<T>& v2)
{
   T dp = dotProduct(v1,v2);
 
   return isAlmostZero(dp, ZERO_TOLERANCE);
}

template <typename T>
bool areParallel(const Vector3<T>& v1, const Vector3<T>& v2)
{
   if(isAlmostZero(v1.length(), ZERO_TOLERANCE) ||
      isAlmostZero(v2.length(), ZERO_TOLERANCE))
   {
        return true;
   }
   
   T angleRadians = angleBetweenVectorsRadians(v1, v2);
   
   if(isAlmostZero(angleRadians, ZERO_TOLERANCE)           ||
      isAlmostZero(angleRadians - dw::PI, ZERO_TOLERANCE))
   {
      return true;
   }
   
   return false;
}

} // namespace dw

#endif // VECTOR3_H
