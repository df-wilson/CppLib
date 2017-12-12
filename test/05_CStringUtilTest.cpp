#include "catch.hpp"
#include "../CStringUtil/CStringUtils.h"
#include <iostream>

const char val1Str[] = "123456";
const char val2Str[] = "0";
const char val3Str[] = "-123456";
const char val4Str[] = "123";

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
   int val1 = 123456;
   int val2 = 0;
   int val3 = -123456;

   char val1Str[] = "123456";
   char val2Str[] = "0";
   char val3Str[] = "-123456";
  
   char *numStr = (char *)malloc(sizeof(char) * 50);
   char *numStr2 = new char[50];
  
   int ret = dw::itoa(numStr, val2, 10);
   REQUIRE(ret == 0);
   std::cout << "Return is " << ret << " string is " << numStr << std::endl;

   ret = dw::itoa(numStr, val1, 10);
   std::cout << "Return is " << ret << " string is " << numStr << std::endl;

   ret = dw::itoa(numStr, val3, 10);
   std::cout << "Return is " << ret << " string is " << numStr << std::endl;

   ret = dw::itoa(numStr, val1, 8);
   std::cout << "Return is " << ret << " string (hex) is " << numStr
             << std::endl;

   ret = dw::itoa(numStr, val3, 16);
   std::cout << "Return is " << ret << " string (hex) is" << numStr << std::endl;

   free(numStr);
   delete[] numStr2;
}

TEST_CASE("Test dw::atoi functionality", "[CStringUtil]")
{
   char val1Str[] = "123456";
   char val2Str[] = "0";
   char val3Str[] = "-123456";
   int val1 = 123456;
   int val2 = 0;
   int val3 = -123456;
   int ret = 0;
   
   ret = dw::atoi(val1Str);
   REQUIRE(ret == val1);

   ret = dw::atoi(val2Str);
   REQUIRE(ret == val2);

   ret = dw::atoi(val3Str);
   REQUIRE(ret == val3);
}
