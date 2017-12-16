/**
 * A collection of math utilities.
 *
 * @author  Dean Wilson
 * @version 1.0
 * @date    March 3, 2014
 *
 * Library  MATH
 *
 */

#ifndef DW_MATH_UTIL_H
#define DW_MATH_UTIL_H

/*---------  System Includes  -----------------*/
#include <cmath>

namespace dw {

const double PI = 3.141592653589793238;
   
/**
 * Compare two double values to detemine if the difference is within the specified
 * tolerance.
 *
 * @param value The value to check to see if it is within zero and the tolerance value
 * @param tolerance The tolerance value. Must be >= zero. Ex. 0.001
 * @return true if the value is almost zero, otherwise false.
 */
bool
isAlmostZero(double value, double tolerance);

/**
 * Compare two double values to detemine if the difference is within the specified
 * tolerance.
 *
 * @param valOneIn First value to compare
 * @param valTwoIn Second Value to compare
 * @param tolerance The allowable difference between the to values for them still to be considered equal
 * @return true if the value is almost zero, otherwise false.
 */
bool
isDoubleAlmostEqual(double valOneIn, double valTwoIn, double tolerance);

/**
 * Compare two float values to detemine if the difference is within the specified
 * tolerance.
 *
 * @param valOneIn First value to compare
 * @param valTwoIn Second Value to compare
 * @param tolerance The allowable difference between the to values for them still to be considered equal
 * @return true if the value is almost zero, otherwise false.
 */
bool
isFloatAlmostEqual(float valOneIn, float valTwoIn, float tolerance);

/**
* Converts radians to degrees.
* 
* @param  radians the angle in radians
* @return the value in degrees
*/
double
radiansToDegrees(double radians);

/**
* Converts radians to degrees.
* 
* @param degrees the angle in degrees
* @return the angle in radians
*/
double
degreesToRadians(double degrees);

} // End namespace

#endif
