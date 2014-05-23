/**************************  FILE HEADER  ********************************
*
* Application:    UTIL library test
*
* Class:          QueueTest
*
* Overview:
*
* Cpp unit test class to test the queue module.
*
**************************************************************************
*/

#include <iostream>
#include <stdexcept>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../DataStructs/Queue.h"

#ifndef QUEUETEST_H
#define QUEUETEST_H

class QueueTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE (QueueTest);
    CPPUNIT_TEST (enqueueTest);
    CPPUNIT_TEST (dequeueTest);
    CPPUNIT_TEST (numElementsTest);
    CPPUNIT_TEST (peekTest);
    CPPUNIT_TEST_SUITE_END ();
	 
public:
	QueueTest();
    virtual ~QueueTest();
	 
	void dequeueTest();
	void enqueueTest();
	void numElementsTest();
	void peekTest();
	void setUp();
	void tearDown();
	
private:
	
	dw::Queue<std::string> *mQueue;
	std::string* mString1;
	std::string* mString2;
	
	QueueTest(QueueTest& src);
	QueueTest& operator=(QueueTest &src);
};

#endif // QUEUETEST_H
