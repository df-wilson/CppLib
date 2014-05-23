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

CStringUtilTest::CStringUtilTest()
{

}

CStringUtilTest::~CStringUtilTest()
{

}


void CStringUtilTest::setUp()
{
	cout << endl << "In StringTest::setUp. Displayed values are between pipes. |<value>|" << endl;
}


void CStringUtilTest::tearDown()
{
}


/**************************  FUNCTION HEADER  ****************************
*
* Private Function: constructorTest
*
**************************************************************************
*/
void CStringUtilTest::constructorTest()
{
	// Test default constructor
   //dw::String* lString = new dw::String();
   //std::cout << "After default constructor string value is: |" << *lString << "|" << std::endl;
   //CPPUNIT_ASSERT(*lString == "");
   //delete lString;

	// Test constructor with char*
   //lString = new dw::String(HELLO_STRING);
   //std::cout << "After constructor with char* string value is: |" << *lString << "|" << std::endl;
   //CPPUNIT_ASSERT(*lString == HELLO_STRING);

	// Test constructor with std::string
   //std::string lCppString(HELLO_STRING);
   //dw::String lCppStringTest(lCppString);
   //std::cout << "After constructor with std::string default value is |" << lCppStringTest << "|" << std::endl;
   //CPPUNIT_ASSERT(lCppStringTest == HELLO_STRING);
	
	// Test copy constructor
   //dw::String lCopyString(*lString);
   //std::cout << "After copy constructor (pointer) string value is: |" << lCopyString << "|" << std::endl;
   //CPPUNIT_ASSERT(lCopyString == HELLO_STRING);

   //dw::String lCopyString2(lString);
   //std::cout << "After copy constructor string value is: |" << lCopyString2 << "|" << std::endl;
   //CPPUNIT_ASSERT(lCopyString2 == HELLO_STRING);

   //delete lString;
}


/**************************  FUNCTION HEADER  ****************************
*
* Private Function: assignmentTest
*
**************************************************************************
*/
void CStringUtilTest::assignmentTest()
{
   //dw::String lString = HELLO_STRING;
   //CPPUNIT_ASSERT(lString == HELLO_STRING);

   //dw::String* lDynamicString = new dw::String();
   //*lDynamicString = HELLO_STRING;
   //CPPUNIT_ASSERT(*lDynamicString == HELLO_STRING);

   //*lDynamicString = SENTENCE_STRING;
   //CPPUNIT_ASSERT(*lDynamicString == SENTENCE_STRING);

   //*lDynamicString = lString;
   //CPPUNIT_ASSERT(*lDynamicString == HELLO_STRING);

   //std::string lStdString(SENTENCE_STRING);
   //*lDynamicString = lStdString;
   //CPPUNIT_ASSERT(*lDynamicString == SENTENCE_STRING);

   //delete lDynamicString;

}

/**************************  FUNCTION HEADER  ****************************
*
* Private Function: inequalityOperator
*
**************************************************************************
*/
void CStringUtilTest::inequalityOperator()
{
   //dw::String lString = HELLO_STRING;
   //CPPUNIT_ASSERT(lString != SENTENCE_STRING);

   //dw::String* lDynamicString = new dw::String();
   //*lDynamicString = HELLO_STRING;
   //CPPUNIT_ASSERT(*lDynamicString != SENTENCE_STRING);

   //*lDynamicString = SENTENCE_STRING;
   //CPPUNIT_ASSERT(*lDynamicString != HELLO_STRING);

   //*lDynamicString = lString;
   //CPPUNIT_ASSERT(*lDynamicString != SENTENCE_STRING);

   //std::string lStdString(SENTENCE_STRING);
   //*lDynamicString = lStdString;
   //CPPUNIT_ASSERT(*lDynamicString != HELLO_STRING);

   //delete lDynamicString;
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

/**************************  FUNCTION HEADER  ****************************
*
* Private Function: operatorAdd
*
**************************************************************************
*/
void CStringUtilTest::operatorAdd()
{
    //dw::String lString1(HELLO_STRING);
    //dw::String lString2(SENTENCE_STRING);

    //dw::String lString3 = lString1 + lString2;

    //std::cout << "Operator + | " << lString3 << " |"<< std::endl;
}

/**************************  FUNCTION HEADER  ****************************
*
* Private Function: equalityOperator
*
**************************************************************************
*/
void CStringUtilTest::equalityOperator()
{
}

/**************************  FUNCTION HEADER  ****************************
*
* Private Function: reverse
*
**************************************************************************
*/
void CStringUtilTest::reverse()
{
   //dw::String lString2(SENTENCE_STRING);
   //lString2.reverse();
   //std::cout << lString2 << std::endl;
}
