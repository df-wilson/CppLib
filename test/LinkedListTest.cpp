//-----------------------------------------------------------------------------
//  Class: LinkedListTest
//
//  Created on: 2013-12-15
//  Author: Dean Wilson
//-----------------------------------------------------------------------------

#include <iostream>
#include <stdexcept>
#include <cppunit/Test.h>
#include <cppunit/TestAssert.h>

#include "LinkedListTest.h"
#include "../DataStructs/LinkedList.h"

using namespace std;

const size_t NO_ELEMENTS    = 0;
const size_t ONE_ELEMENT    = 1;
const size_t TWO_ELEMENTS   = 2;
const size_t THREE_ELEMENTS = 3;

CPPUNIT_TEST_SUITE_REGISTRATION(LinkedListTest);

void LinkedListTest::setUp()
{
	mList    = new dw::LinkedList<std::string>();
	mString1 = new std::string("String 1");
	mString2 = new std::string("String 2");
	mString3 = new std::string("String 3");
}

void LinkedListTest::tearDown()
{
	delete mList;
	delete mString1;
	delete mString2;
	delete mString3;
}

void LinkedListTest::addTest()
{
	CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mList->numElements());
	mList->add(*mString1);
	CPPUNIT_ASSERT_EQUAL(ONE_ELEMENT, mList->numElements());
	
	mList->add(*mString2);
	CPPUNIT_ASSERT_EQUAL(TWO_ELEMENTS, mList->numElements());
	CPPUNIT_ASSERT_EQUAL(*mString1, mList->getFirst());
	CPPUNIT_ASSERT_EQUAL(*mString2, mList->getLast());
	
	mList->add(*mString3);
	CPPUNIT_ASSERT_EQUAL(THREE_ELEMENTS, mList->numElements());
	CPPUNIT_ASSERT_EQUAL(*mString1, mList->getFirst());
	CPPUNIT_ASSERT_EQUAL(*mString3, mList->getLast());
	
}

void LinkedListTest::addToFrontTest()
{
	CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mList->numElements());
	
	mList->addToFront(*mString1);
	CPPUNIT_ASSERT_EQUAL(ONE_ELEMENT, mList->numElements());
	
	mList->addToFront(*mString2);
	CPPUNIT_ASSERT_EQUAL(TWO_ELEMENTS, mList->numElements());
	CPPUNIT_ASSERT_EQUAL(*mString2, mList->getFirst());
	CPPUNIT_ASSERT_EQUAL(*mString1, mList->getLast());
	
	mList->addToFront(*mString3);
	CPPUNIT_ASSERT_EQUAL(THREE_ELEMENTS, mList->numElements());
	CPPUNIT_ASSERT_EQUAL(*mString3, mList->getFirst());
	CPPUNIT_ASSERT_EQUAL(*mString1, mList->getLast());
	
}

void LinkedListTest::getFirstTest()
{
	CPPUNIT_ASSERT_THROW (mList->getFirst(), std::out_of_range);
	mList->add(*mString1);
	mList->add(*mString2);
	CPPUNIT_ASSERT_EQUAL(*mString1, mList->getFirst());
}

void LinkedListTest::getLastTest()
{
	CPPUNIT_ASSERT_THROW (mList->getLast(), std::out_of_range);
	mList->add(*mString1);
	mList->add(*mString2);
	CPPUNIT_ASSERT_EQUAL(*mString2, mList->getLast());
}

void LinkedListTest::getNextTest()
{
	mList->add(*mString1);
	mList->add(*mString2);
	mList->add(*mString3);
	CPPUNIT_ASSERT_EQUAL(*mString1, mList->getFirst());
	CPPUNIT_ASSERT_EQUAL(*mString2, mList->getNext());
	CPPUNIT_ASSERT_EQUAL(*mString3, mList->getNext());
	CPPUNIT_ASSERT_THROW(mList->getNext(), std::out_of_range);
}

void LinkedListTest::getPrevTest()
{
	mList->add(*mString1);
	mList->add(*mString2);
	mList->add(*mString3);
	CPPUNIT_ASSERT_EQUAL(*mString3, mList->getLast());
	CPPUNIT_ASSERT_EQUAL(*mString2, mList->getPrev());
	CPPUNIT_ASSERT_EQUAL(*mString1, mList->getPrev());
	CPPUNIT_ASSERT_THROW(mList->getPrev(), std::out_of_range);
}

void LinkedListTest::copyConstructorTest()
{
	mList->add(*mString1);
	mList->add(*mString2);
	mList->add(*mString3);
	
	dw::LinkedList<std::string> list(*mList);
	
	CPPUNIT_ASSERT_EQUAL(THREE_ELEMENTS, list.numElements()); 
	CPPUNIT_ASSERT_EQUAL(*mString1, list.getFirst());
	CPPUNIT_ASSERT_EQUAL(*mString2, list.getNext());
	CPPUNIT_ASSERT_EQUAL(*mString3, list.getNext());
	CPPUNIT_ASSERT_THROW(list.getNext(), std::out_of_range);
	
}

void LinkedListTest::assignmentTest()
{
	mList->add(*mString1);
	mList->add(*mString2);
	mList->add(*mString3);
	
	dw::LinkedList<std::string> list = *mList;
	
	CPPUNIT_ASSERT_EQUAL(THREE_ELEMENTS, list.numElements()); 
	CPPUNIT_ASSERT_EQUAL(*mString1, list.getFirst());
	CPPUNIT_ASSERT_EQUAL(*mString2, list.getNext());
	CPPUNIT_ASSERT_EQUAL(*mString3, list.getNext());
	CPPUNIT_ASSERT_THROW(list.getNext(), std::out_of_range);
	
}


void LinkedListTest::numElementsTest()
{
	/* test that numElements works on an empty list.
	*/
	CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mList->numElements());

	/* test that num elements works when an element has been added.
	*/
	mList->add(*mString1);
	CPPUNIT_ASSERT_EQUAL(ONE_ELEMENT, mList->numElements());
	mList->add(*mString2);
	CPPUNIT_ASSERT_EQUAL(TWO_ELEMENTS, mList->numElements());
	mList->add(*mString3);
	CPPUNIT_ASSERT_EQUAL(THREE_ELEMENTS, mList->numElements());

	mList->popLastElement();
	CPPUNIT_ASSERT_EQUAL(TWO_ELEMENTS, mList->numElements());
	mList->removeFirstElement();
	CPPUNIT_ASSERT_EQUAL(ONE_ELEMENT, mList->numElements());
}

void LinkedListTest::popLastElementTest()
{
	CPPUNIT_ASSERT_THROW(mList->popLastElement(), std::out_of_range);

	mList->add(*mString1);

	std::string tempString;

	try
	{
		tempString = mList->popLastElement();
	}
	catch(const std::out_of_range& e)
	{
		CPPUNIT_FAIL("An out of range error when removing an element from \
							an empty list");
	}
	catch(const std::logic_error& e)
	{
		CPPUNIT_FAIL("A logic error occurred when removing an element from \
							an empty list");
	}

	CPPUNIT_ASSERT_EQUAL(tempString, *mString1);

	/* Test that a new string was passed back not the address of the original
	*/
	*mString1 = "New value";
	CPPUNIT_ASSERT(tempString != *mString1);

}

/**
* @brief Test the removeFirstElement functionality.
* 
* @return void
*/
void LinkedListTest::removeFirstElement()
{
 	try
 	{
 		mList->removeFirstElement();
 	}
 	catch (const std::logic_error& e)
 	{
 		CPPUNIT_FAIL("A logic error occurred when removing an element from an empty list");
 	}

 	// Test removing an element from the front of a list with 1 element.
 	mList->add(*mString1);

 	try
 	{
 		mList->removeFirstElement();
 	}
 	catch (const std::logic_error& e)
 	{
 		CPPUNIT_FAIL("A logic error occurred when removing an element from a list of one element");
 	}

 	CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mList->numElements());
//
// 	// Test removing the first element when there are more than one element in the list.
 	//mList->add(*mString1);
// 	mList->add(*mString2);
//
// 	try
// 	{
// 		mList->removeFirstElement();
// 	}
// 	catch (const std::logic_error& e)
// 	{
// 		CPPUNIT_FAIL("A logic error occurred when removing an element from a list with two elements");
// 	}
//
// 	CPPUNIT_ASSERT_EQUAL(ONE_ELEMENT, mList->numElements());
// 	CPPUNIT_ASSERT_EQUAL(*mString2, mList->getFirst());
//
// 	// Test that removing an element from a list that had elements but is now
// 	// empty works correctly
// 	try
// 	{
// 		mList->removeFirstElement();
// 	}
// 	catch (const std::logic_error& e)
// 	{
// 		CPPUNIT_FAIL("A logic error occurred when removing an element from an empty list");
// 	}
}

void LinkedListTest::removeLastElement()
{
	try
	{
		mList->removeLastElement();
	}
	catch (const std::logic_error& e)
	{
		CPPUNIT_FAIL("A logic error occurred when removing an element from an empty list");
	}

	// Test removing an element when there is only one in the list
	try
	{
		mList->removeLastElement();
	}
	catch (const std::logic_error& e)
	{
		CPPUNIT_FAIL("A logic error occurred when removing an element from a list with two elements");
	}

	CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mList->numElements());

	// Test removing the last element when there are more than one element in the list.
	mList->add(*mString1);
	mList->add(*mString2);

	try
	{
		mList->removeLastElement();
	}
	catch (const std::logic_error& e)
	{
		CPPUNIT_FAIL("A logic error occurred when removing an element from a" \
						"list with two elements");
	}

	CPPUNIT_ASSERT_EQUAL(ONE_ELEMENT, mList->numElements());
	CPPUNIT_ASSERT_EQUAL(*mString1, mList->getFirst());

	// Test that removing an element from a list that had elements but is now
	// empty works correctly
	try
	{
		mList->removeLastElement();
	}
	catch (const std::logic_error& e)
	{
		CPPUNIT_FAIL("A logic error occurred when removing an element from \
							an empty list");
	}
}

