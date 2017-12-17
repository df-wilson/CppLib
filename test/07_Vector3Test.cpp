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

TEST_CASE("Test Vector3 constructors" "[vector]")
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

TEST_CASE("Test Vector3 get and set", "[vector]")
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

TEST_CASE("Test Vector3 length", "[vector]")
{
   const float LENGTH_RESULT = 4.115;
   
   dw::Vector3<float> floatVector(TEST_2_FLOAT_X, TEST_2_FLOAT_Y, TEST_2_FLOAT_Z);
   
   float length = floatVector.length();
   REQUIRE(length == Approx(length));

   auto zeroVector = dw::Vector3<int>(0,0,0);
   int intLength = zeroVector.length();
   REQUIRE(intLength == 0);
}

TEST_CASE("Test Vector3 add", "[vector]")
{
   dw::Vector3<int> testIntVector1(TEST_INT_X, TEST_INT_Y, TEST_INT_Z);
   dw::Vector3<int> testIntVector2(TEST_2_INT_X, TEST_2_INT_Y, TEST_2_INT_Z);
   dw::Vector3<int> result = testIntVector1 + testIntVector2;
   REQUIRE(result.x() == TEST_INT_X + TEST_2_INT_X);
   REQUIRE(result.y() == TEST_INT_Y + TEST_2_INT_Y);
   REQUIRE(result.z() == TEST_INT_Z + TEST_2_INT_Z);
}

TEST_CASE("Test Vector3 negate", "[vector]")
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

TEST_CASE("Test Vector3 subtract", "[vector]")
{
   dw::Vector3<int> testIntVector1(TEST_INT_X, TEST_INT_Y, TEST_INT_Z);
   dw::Vector3<int> testIntVector2(TEST_2_INT_X, TEST_2_INT_Y, TEST_2_INT_Z);
   dw::Vector3<int> result = testIntVector1 - testIntVector2;
   REQUIRE(result.x() == TEST_INT_X - TEST_2_INT_X);
   REQUIRE(result.y() == TEST_INT_Y - TEST_2_INT_Y);
   REQUIRE(result.z() == TEST_INT_Z - TEST_2_INT_Z);
}

TEST_CASE("Test Vector3 operator<<", "[vector]")
{
   dw::Vector3<int> intVector(TEST_INT_X, TEST_INT_Y, TEST_INT_Z);
   std::string contents;
   std::ostringstream stream;
   stream << intVector;
   REQUIRE(stream.str() == "1 2 3");
}

TEST_CASE("Test Vector3 dot product", "[vector]")
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

TEST_CASE("Test Vector3 angle betwee vectors", "[vector]")
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
