/*---------  Program Includes  ----------------*/
#include "mathutil.h"

/*---------  System Includes  -----------------*/
#include <cmath>

namespace dw {

bool
isAlmostZero(double value, double tolerance) 
{
    bool result = 0;
    
    if(fabs(value) <= tolerance) {
        result = true;
    }
    else {
        result = false;
    }

    return result;
}

bool
isDoubleAlmostEqual(double valOneIn, double valTwoIn, double tolerance) 
{
   if(fabs(valOneIn - valTwoIn) < tolerance) {
      return true;
   } else {
      return false;
   }
}

bool
isFloatAlmostEqual(float valOneIn, float valTwoIn, float tolerance) 
{
   return isDoubleAlmostEqual(valOneIn, valTwoIn, tolerance);
}

double
radiansToDegrees(double radians)
{
   return radians * 180.0 / dw::PI;
}

} // End namespace

