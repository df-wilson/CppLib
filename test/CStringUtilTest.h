/**************************  FILE HEADER  ********************************
*
* Application:    App
*
* Class:          CStringUtilTest
*
* Overview:
*
* Test class for the c string utilities.
*
**************************************************************************
*/

#ifndef CSTRING_UTIL_TEST_H
#define CSTRING_UTIL_TEST_H

/*---------  System Includes  -----------------*/

#include <iostream>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>


/*---------  Program Includes  ----------------*/

#include "../CStringUtil/CStringUtils.h"


/*---------  Forward Declarations  ------------*/


/*---------  Class Definition  ----------------*/

class CStringUtilTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE (CStringUtilTest);
    CPPUNIT_TEST (itoaTest);
    //CPPUNIT_TEST (assignmentTest);
    //CPPUNIT_TEST (inequalityOperator);
    //CPPUNIT_TEST (append);
    //CPPUNIT_TEST (reverse);
    //CPPUNIT_TEST (operatorAdd);
    CPPUNIT_TEST_SUITE_END ();


public:
   CStringUtilTest();
   virtual ~CStringUtilTest();

   void setUp();
   void tearDown();

private:
	
	int numFailures = 0;

   void itoaTest();
   void assignmentTest();
   void constructorTest();
   void equalityOperator();
   void inequalityOperator();
   void operatorAdd();
   void reverse();


};

#endif /* MYSTRINGTEST_H_ */
