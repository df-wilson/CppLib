/**************************  FILE HEADER  ********************************
*
* Application:    App
*
* Class:          Name
* Methods
* Public:
*
* Private:
*
*
* Overview:
*
* Test class for the stack
*
**************************************************************************
*/

#ifndef STACKTEST_H_
#define STACKTEST_H_


/*---------  System Includes  -----------------*/

#include <cstddef>
#include <iostream>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>


/*---------  Program Includes  ----------------*/

#include "../DataStructs/Stack.h"


/*---------  Forward Declarations  ------------*/


/*---------  Class Definition  ----------------*/

class StackTest : public CPPUNIT_NS::TestFixture
{

    CPPUNIT_TEST_SUITE (StackTest);
    CPPUNIT_TEST (numElementsTest);
    CPPUNIT_TEST (addElementTest);
    CPPUNIT_TEST (emptyStackTest);
    CPPUNIT_TEST (peekTest);
    CPPUNIT_TEST (copyConstructorTest);
    CPPUNIT_TEST (popTest);
    CPPUNIT_TEST_SUITE_END ();

public:
    StackTest();
    virtual ~StackTest();
    void setUp();
    void tearDown();


private:
    void addElementTest();
    void copyConstructorTest();
    void emptyStackTest();
    void numElementsTest();
    void peekTest();
    void popTest();

    dw::Stack<std::string>* mStack;
    std::string*        mString1;
    std::string*        mString2;
};

#endif /* STACKTEST_H_ */
