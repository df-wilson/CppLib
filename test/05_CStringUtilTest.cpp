#include "catch.hpp"
#include "../CStringUtil/CStringUtils.h"
#include <iostream>

const char val1Str[] = "123456";
const char val2Str[] = "0";
const char val3Str[] = "-123456";
const char val4Str[] = "123";

const char val1OctStr[] = "361100";
const char val3HexStr[] = "-1E240";

const int val1 = 123456;
const int val2 = 0;
const int val3 = -123456;


TEST_CASE("Test strlen functionality", "[CStringUtil]")
{
   int size = dw::strlen(val1Str);
   REQUIRE(size == 6);
   
   size = dw::strlen(val2Str);
   REQUIRE(size == 1);
   
   size = dw::strlen(val3Str);
   REQUIRE(size == 7);
   
   size = dw::strlen("");
   REQUIRE(size == 0);
}

TEST_CASE("Test strncmp functionality", "[CStringUtil]")
{

   int result = dw::strncmp(val1Str, val1Str, dw::strlen(val1Str));
   REQUIRE(result == 0);
   
   result = dw::strncmp(val1Str, val3Str, dw::strlen(val3Str));
   REQUIRE(result == 1);
   
   result = dw::strncmp(val3Str, val1Str, dw::strlen(val3Str));
   REQUIRE(result == -1);
   
   result = dw::strncmp(val1Str, val4Str, dw::strlen(val1Str));
   REQUIRE(result == 1);
   
   result = dw::strncmp(val1Str, val4Str, dw::strlen(val4Str));
   REQUIRE(result == 0);
   
   result = dw::strncmp(val1Str, val4Str, 0);
   REQUIRE(result == 0);
}

TEST_CASE("Test itoa functionality", "[CStringUtil]")
{
   char *numStr = new char[50];
  
   int ret = dw::itoa(numStr, val2, 10);
   REQUIRE(ret == 0);
   REQUIRE(dw::strncmp(numStr, val2Str, dw::strlen(val2Str)) == 0);


   ret = dw::itoa(numStr, val1, 10);
   REQUIRE(ret == 0);
   REQUIRE(dw::strncmp(numStr, val1Str, dw::strlen(val1Str)) == 0);

   ret = dw::itoa(numStr, val3, 10);
   REQUIRE(ret == 0);
   REQUIRE(dw::strncmp(numStr, val3Str, dw::strlen(val3Str)) == 0);

   ret = dw::itoa(numStr, val1, 8);
   REQUIRE(ret == 0);
   REQUIRE(dw::strncmp(numStr, val1OctStr, dw::strlen(val1OctStr)) == 0);

   ret = dw::itoa(numStr, val3, 16);
   REQUIRE(ret == 0);
   REQUIRE(dw::strncmp(numStr, val3HexStr, dw::strlen(val3HexStr)) == 0);

   delete[] numStr;
}

TEST_CASE("Test atoi functionality", "[CStringUtil]")
{
   int ret = 0;
   
   ret = dw::atoi(val1Str);
   REQUIRE(ret == val1);

   ret = dw::atoi(val2Str);
   REQUIRE(ret == val2);

   ret = dw::atoi(val3Str);
   REQUIRE(ret == val3);
}

TEST_CASE("Test isCharOneOf functionality", "[CStringUtil]")
{
   REQUIRE(dw::isCharOneOf('a', val1Str) == false);
   REQUIRE(dw::isCharOneOf('2', val1Str) == true);
   REQUIRE(dw::isCharOneOf('-', val3HexStr) == true);
   REQUIRE(dw::isCharOneOf('E', val3HexStr) == true);
   REQUIRE(dw::isCharOneOf('e', val3HexStr) == false);
}

