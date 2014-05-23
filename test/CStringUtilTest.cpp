#include <cassert>
#include <iostream>
#include <string>

#include "CStringUtilTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CStringUtilTest);

const char* HELLO_STRING = "Hello";
const char* SENTENCE_STRING = "This is a longer string.";
const char* COMBINED_STRING = "HelloThis is a longer string.";
const char* REVERSE_STRING  = "gnirts regnol a si sihT";

using namespace std;

void CStringUtilTest::setUp()
{
}


void CStringUtilTest::tearDown()
{
}


/**************************  FUNCTION HEADER  ****************************
*
* Private Function: append
*
**************************************************************************
*/
void CStringUtilTest::itoaTest()
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

	ret = atoi(val1Str);
	std::cout << " int val is " << ret << std::endl;

	ret = atoi(val2Str);
	std::cout << " int val is " << ret << std::endl;

	ret = atoi(val3Str);
	std::cout << " int val is " << ret << std::endl;
  
	free(numStr);
	delete[] numStr2;
}
