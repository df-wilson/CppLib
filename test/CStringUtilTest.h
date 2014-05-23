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
    CPPUNIT_TEST_SUITE_END ();


public:

   void setUp();
   void tearDown();

private:
   void itoaTest();

};

#endif /* MYSTRINGTEST_H_ */
