#include "catch.hpp"
#include "../CStringUtil/CStringUtils.h"
#include <iostream>

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
  
   int ret = itoa(numStr, val2, 10);
   REQUIRE(ret == 0);
   std::cout << "Return is " << ret << " string is " << numStr << std::endl;

   ret = itoa(numStr, val1, 10);
   std::cout << "Return is " << ret << " string is " << numStr << std::endl;

   ret = itoa(numStr, val3, 10);
   std::cout << "Return is " << ret << " string is " << numStr << std::endl;

   ret = itoa(numStr, val1, 8);
   std::cout << "Return is " << ret << " string (hex) is " << numStr
             << std::endl;

   ret = itoa(numStr, val3, 16);
   std::cout << "Return is " << ret << " string (hex) is" << numStr << std::endl;

   free(numStr);
   delete[] numStr2;
}

TEST_CASE("Test atoi functionality", "[CStringUtil]")
{
   char val1Str[] = "123456";
   char val2Str[] = "0";
   char val3Str[] = "-123456";
   int val1 = 123456;
   int val2 = 0;
   int val3 = -123456;
   int ret = 0;
   
   ret = atoi(val1Str);
   REQUIRE(ret == val1);

   ret = atoi(val2Str);
   REQUIRE(ret == val2);

   ret = atoi(val3Str);
   REQUIRE(ret == val3);
}
