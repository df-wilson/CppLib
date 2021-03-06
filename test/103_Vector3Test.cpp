#include "catch.hpp"

#include "../Math/mathutil.h"
#include "../Math/Vector3.h"

#include <sstream>

const int DEFAULT_INT = 0;
const int TEST_INT_X = 1;
const int TEST_INT_Y = 2;
const int TEST_INT_Z = 3;
const int TEST_2_INT_X = 11111;
const int TEST_2_INT_Y = 22222;
const int TEST_2_INT_Z = 33333;
const int TEST_3_INT_X = -11111;
const int TEST_3_INT_Y = -22222;
const int TEST_3_INT_Z = -33333;

const float TEST_FLOAT_X = 1.5f;
const float TEST_FLOAT_Y = 10.23f;
const float TEST_FLOAT_Z = 33.333f;
const float TEST_2_FLOAT_X = 1.1f;
const float TEST_2_FLOAT_Y = 2.2f;
const float TEST_2_FLOAT_Z = 3.3f;
const float TEST_FLOAT_DELTA = 0.001;

TEST_CASE("Vector3: Test Vector3 constructors", "Math")
{
   // Test the default constructor initializes values to 0
   dw::Vector3<int> defaultIntVector;

   REQUIRE(defaultIntVector.x() == DEFAULT_INT);
   REQUIRE(defaultIntVector.y() == DEFAULT_INT);
   REQUIRE(defaultIntVector.z() == DEFAULT_INT);

   // Test the constructor used when assigning init values
   dw::Vector3<float> floatVector(TEST_FLOAT_X, TEST_FLOAT_Y, TEST_FLOAT_Z);
   REQUIRE(floatVector.x() == Approx(TEST_FLOAT_X));
   REQUIRE(floatVector.y() == Approx(TEST_FLOAT_Y));
   REQUIRE(floatVector.z() == Approx(TEST_FLOAT_Z));

   // Test the copy constructor
   dw::Vector3<float> copiedFloatVector(floatVector);
   REQUIRE(copiedFloatVector.x() == Approx(TEST_FLOAT_X));
   REQUIRE(copiedFloatVector.y() == Approx(TEST_FLOAT_Y));
   REQUIRE(copiedFloatVector.z() == Approx(TEST_FLOAT_Z));

   // Test the assignment operator
   dw::Vector3<float> assignedFloatVector = floatVector;
   REQUIRE(copiedFloatVector.x() == Approx(TEST_FLOAT_X));
   REQUIRE(copiedFloatVector.y() == Approx(TEST_FLOAT_Y));
   REQUIRE(copiedFloatVector.z() == Approx(TEST_FLOAT_Z));

   assignedFloatVector = dw::Vector3<float>(TEST_2_FLOAT_X, TEST_2_FLOAT_Y, TEST_2_FLOAT_Z);
   REQUIRE(assignedFloatVector.x() == Approx(TEST_2_FLOAT_X));
   REQUIRE(assignedFloatVector.y() == Approx(TEST_2_FLOAT_Y));
   REQUIRE(assignedFloatVector.z() == Approx(TEST_2_FLOAT_Z));
}

TEST_CASE("Vector3: Test Vector3 get and set", "Math")
{
   dw::Vector3<int> intVector;
   intVector.x(TEST_INT_X);
   intVector.y(TEST_INT_Y);
   intVector.z(TEST_INT_Z);

   // Get the values and ensure they're the same as were set.
   REQUIRE(intVector.x() == TEST_INT_X);
   REQUIRE(intVector.y() == TEST_INT_Y);
   REQUIRE(intVector.z() == TEST_INT_Z);

   
   intVector.set(TEST_2_INT_X, TEST_2_INT_Y, TEST_2_INT_Z);
   REQUIRE(TEST_2_INT_X == intVector.x());
   REQUIRE(TEST_2_INT_Y == intVector.y());
   REQUIRE(TEST_2_INT_Z == intVector.z());
   
   intVector.x(TEST_3_INT_X);
   intVector.y(TEST_3_INT_Y);
   intVector.z(TEST_3_INT_Z);
   REQUIRE(intVector.x() == TEST_3_INT_X);
   REQUIRE(intVector.y() == TEST_3_INT_Y);
   REQUIRE(intVector.z() == TEST_3_INT_Z);
}

TEST_CASE("Vector3: Test length", "Math")
{
   const float LENGTH_RESULT = 4.115;
   
   dw::Vector3<float> floatVector(TEST_2_FLOAT_X, TEST_2_FLOAT_Y, TEST_2_FLOAT_Z);
   
   float length = floatVector.length();
   REQUIRE(length == Approx(length));

   auto zeroVector = dw::Vector3<int>(0,0,0);
   int intLength = zeroVector.length();
   REQUIRE(intLength == 0);
}

TEST_CASE("Vector3: Test add", "Math")
{
   dw::Vector3<int> testIntVector1(TEST_INT_X, TEST_INT_Y, TEST_INT_Z);
   dw::Vector3<int> testIntVector2(TEST_2_INT_X, TEST_2_INT_Y, TEST_2_INT_Z);
   dw::Vector3<int> result = testIntVector1 + testIntVector2;
   REQUIRE(result.x() == TEST_INT_X + TEST_2_INT_X);
   REQUIRE(result.y() == TEST_INT_Y + TEST_2_INT_Y);
   REQUIRE(result.z() == TEST_INT_Z + TEST_2_INT_Z);
}

TEST_CASE("Vector3: Test negate", "Math")
{
   dw::Vector3<int> intVector(TEST_INT_X, TEST_INT_Y, TEST_INT_Z);
   dw::Vector3<int> result = -intVector;
   REQUIRE(-TEST_INT_X == result.x());
   REQUIRE(-TEST_INT_Y == result.y());
   REQUIRE(-TEST_INT_Z == result.z());

   result = -result;
   REQUIRE(TEST_INT_X == result.x());
   REQUIRE(TEST_INT_Y == result.y());
   REQUIRE(TEST_INT_Z == result.z());

   dw::Vector3<int> zeroVector(0,0,0);
   result = zeroVector;
   result = -zeroVector;
   REQUIRE(0 == result.x());
   REQUIRE(0 == result.y());
   REQUIRE(0 == result.z());
}

TEST_CASE("Vector3: Test subtract", "Math")
{
   dw::Vector3<int> testIntVector1(TEST_INT_X, TEST_INT_Y, TEST_INT_Z);
   dw::Vector3<int> testIntVector2(TEST_2_INT_X, TEST_2_INT_Y, TEST_2_INT_Z);
   dw::Vector3<int> result = testIntVector1 - testIntVector2;
   REQUIRE(result.x() == TEST_INT_X - TEST_2_INT_X);
   REQUIRE(result.y() == TEST_INT_Y - TEST_2_INT_Y);
   REQUIRE(result.z() == TEST_INT_Z - TEST_2_INT_Z);
}

TEST_CASE("Vector3: Test scalar test", "Math")
{
   dw::Vector3<double> vector2(1.671, -1.012, -0.318);
   
   dw::Vector3<double> vector4 = vector2 * 7.41;
  
   REQUIRE(vector4.x() == Approx(12.3821).margin(0.0001));
   REQUIRE(vector4.y() == Approx(-7.4989).margin(0.0001));
   REQUIRE(vector4.z() == Approx(-2.3564).margin(0.0001));
}

TEST_CASE("Vector3: Test operator<<", "Math")
{
   dw::Vector3<int> intVector(TEST_INT_X, TEST_INT_Y, TEST_INT_Z);
   std::string contents;
   std::ostringstream stream;
   stream << intVector;
   REQUIRE(stream.str() == "1 2 3");
}

TEST_CASE("Vector3: Test operator==", "Math")
{
   dw::Vector3<int> vector1(1,2,3);
   dw::Vector3<int> vector2(1,2,3);
   dw::Vector3<int> vector3(1,2,2);
   
   REQUIRE(vector1 == vector2);
   REQUIRE(!(vector1 == vector3));
   
   dw::Vector3<double> vector4(1.234, 2.234, 3.234);
   dw::Vector3<double> vector5(1.234, 2.234, 3.234);
   dw::Vector3<double> vector6(1.234, 2.236, 3.234);
   
   REQUIRE(vector4 == vector5);
   REQUIRE(!(vector4 == vector6));
}

TEST_CASE("Vector3: Test unit vector", "Math")
{
   dw::Vector3<double> vector1(5.581, -2.136, 0);
   dw::Vector3<double> unitVector = vector1.unitVector();
   REQUIRE(unitVector.x() == Approx(0.9339).margin(0.0001));
   REQUIRE(unitVector.y() == Approx(-0.3574).margin(0.0001));
   REQUIRE(unitVector.z() == Approx(0.0).margin(0.0001));
    
    dw::Vector3<double> vector2(1.996, 3.108, -4.554);
   unitVector = vector2.unitVector();
   REQUIRE(unitVector.x() == Approx(0.3404).margin(0.0001));
   REQUIRE(unitVector.y() == Approx(0.53).margin(0.0001));
   REQUIRE(unitVector.z() == Approx(-0.7766).margin(0.0001));
    
}

TEST_CASE("Vector3: Test dot product", "Math")
{
   dw::Vector3<double> vector1(-5.955, -4.904, -1.874);
   dw::Vector3<double> vector2(-4.496, -8.755, 7.103);
   double result = dw::dotProduct(vector1, vector2);
   REQUIRE(result == Approx(56.397));

   dw::Vector3<double> vector3(7.887, 4.138, 0.0);
   dw::Vector3<double> vector4(-8.802, 6.776, 0.0);
   result = dw::dotProduct(vector3, vector4);
   REQUIRE(result == Approx(-41.382));
}

TEST_CASE("Vector3: Test angle between vectors", "Math")
{
   dw::Vector3<double> vector1(7.35, 0.221, 5.188);
   dw::Vector3<double> vector2(2.751, 8.259, 3.985);
   double angleRadians = dw::angleBetweenVectorsRadians(vector1, vector2);
   REQUIRE(angleRadians == Approx(1.052));
   
   dw::Vector3<double> vector3(3.183, -7.627, 0.0);
   dw::Vector3<double> vector4(-2.668, 5.319, 0.0);
   angleRadians = dw::angleBetweenVectorsRadians(vector3, vector4);
   REQUIRE(angleRadians == Approx(3.072));
}

TEST_CASE("Vector3: Test areOrthogonal", "Math")
{
   dw::Vector3<double> vector1(-7.579, -7.88, 0.0);
   dw::Vector3<double> vector2(22.737, 23.64, 0.0);

   dw::Vector3<double> vector3(-2.029, 9.97, 4.172);
   dw::Vector3<double> vector4(-9.231, -6.639, -7.245);

   dw::Vector3<double> vector5(-2.328, -7.284, -1.214);
   dw::Vector3<double> vector6(-1.821, 1.072, -2.94);
   
   dw::Vector3<double> vector7(2.118, 4.827, 0.0);
   dw::Vector3<double> vector8(0.0, 0.0, 0.0);

   REQUIRE(areOrthogonal(vector1, vector2) == false);
   REQUIRE(areOrthogonal(vector3, vector4) == false);
   REQUIRE(areOrthogonal(vector5, vector6) == true);
   REQUIRE(areOrthogonal(vector7, vector8) == true);
}

TEST_CASE("Vector3: Test areParallel", "Math")
{
   dw::Vector3<double> vector1(-7.579, -7.88, 0.0);
   dw::Vector3<double> vector2(22.737, 23.64, 0.0);

   dw::Vector3<double> vector3(-2.029, 9.97, 4.172);
   dw::Vector3<double> vector4(-9.231, -6.639, -7.245);

   dw::Vector3<double> vector5(-2.328, -7.284, -1.214);
   dw::Vector3<double> vector6(-1.821, 1.072, -2.94);
   
   dw::Vector3<double> vector7(2.118, 4.827, 0.0);
   dw::Vector3<double> vector8(0.0, 0.0, 0.0);

   REQUIRE(areParallel(vector1, vector2) == true);
   REQUIRE(areParallel(vector3, vector4) == false);
   REQUIRE(areParallel(vector5, vector6) == false);
   REQUIRE(areParallel(vector7, vector8) == true);
}

TEST_CASE("Vector3: Test cross product", "Math")
{
   dw::Vector3<double> vector1(8.462, 7.893, -8.187);
   dw::Vector3<double> vector2(6.984, -5.975, 4.778);
   dw::Vector3<double> answer1(-11.205 , -97.609, -105.685);
   
   dw::Vector3<int> vector3(1, -1, 2);
   dw::Vector3<int> vector4(2, 3, -4);
   dw::Vector3<int> answer2(-2 , 8, 5);

   dw::Vector3<double> vector5(2, 4, -5);
   dw::Vector3<double> vector6(-3, -2, 1);
   dw::Vector3<double> answer3(-6 , 13, 8);

   dw::Vector3<double> vector7(2.118, 4.827, 0.0);
   dw::Vector3<double> vector8(0.0, 0.0, 0.0);
   dw::Vector3<double> answer4(0.0 ,0.0, 0.0);
   
   REQUIRE(dw::crossProduct(vector1, vector2) == answer1);
   REQUIRE(dw::crossProduct(vector3, vector4) == answer2);
   REQUIRE(dw::crossProduct(vector5, vector6) == answer3);
   REQUIRE(dw::crossProduct(vector7, vector8) == answer4);
}
