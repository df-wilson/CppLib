#ifndef LINKEDLISTTEST_H_
#define LINKEDLISTTEST_H_

/**************************  FILE HEADER  ********************************
*
* Application:    Practice Cpp
*
* Class:          LinkedListTest
*
* Overview:
*
* Cpp unit test class to test the linked list module.
*
**************************************************************************
*/

#include <iostream>
#include <string>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../DataStructs/LinkedList.h"

class LinkedListTest: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE (LinkedListTest);
    CPPUNIT_TEST (copyConstructorTest);
    CPPUNIT_TEST (assignmentTest);
    CPPUNIT_TEST (numElementsTest);
    CPPUNIT_TEST (addTest);
    CPPUNIT_TEST (addToFrontTest);
    CPPUNIT_TEST (getFirstTest);
    CPPUNIT_TEST (getNextTest);
    CPPUNIT_TEST (getLastTest);
    CPPUNIT_TEST (getPrevTest);
    CPPUNIT_TEST (removeFirstElement);
    CPPUNIT_TEST (removeLastElement);
    CPPUNIT_TEST (popLastElementTest);
    CPPUNIT_TEST_SUITE_END ();

public:
    void setUp();
    void tearDown();

private:
    void addTest();
	 void addToFrontTest();
    void copyConstructorTest();
    void assignmentTest();
    void getFirstTest();
    void getLastTest();
    void getNextTest();
    void getPrevTest();
    void numElementsTest();
    void popLastElementTest();
	 void removeFirstElement();
    void removeLastElement();

    dw::LinkedList<std::string>* mList;
    std::string*             mString1;
    std::string*             mString2;
    std::string*             mString3;
};

#endif /* LINKEDLISTTEST_H_ */
