#include "QueueTest.h"

const size_t NO_ELEMENTS  = 0;
const size_t ONE_ELEMENT  = 1;
const size_t TWO_ELEMENTS = 2;


CPPUNIT_TEST_SUITE_REGISTRATION(QueueTest);

//-----------------------------------------------------------------------------
// Public Constructor
//-----------------------------------------------------------------------------
QueueTest::QueueTest()
{
}

//-----------------------------------------------------------------------------
// Public Destructor
//-----------------------------------------------------------------------------
QueueTest::~QueueTest()
{
}

//-----------------------------------------------------------------------------
// Public Function: dequeueTest 
//-----------------------------------------------------------------------------
void QueueTest::dequeueTest()
{
	// Try with no elements in the queue. Should throw an exception
   CPPUNIT_ASSERT_THROW (mQueue->dequeue(), std::out_of_range);
	
	// Try with one element in the queue
   mQueue->enqueue(*mString1);
	mQueue->dequeue();
	//CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mQueue->numElements());
}

//-----------------------------------------------------------------------------
// Public Function: enqueueTest 
//-----------------------------------------------------------------------------
void QueueTest::enqueueTest()
{
   mQueue->enqueue(*mString1);
   mQueue->enqueue(*mString2);
   CPPUNIT_ASSERT_EQUAL(TWO_ELEMENTS, mQueue->numElements());
   CPPUNIT_ASSERT_EQUAL(*mString1, mQueue->peek());
}

//-----------------------------------------------------------------------------
// Public Function: numElements
//-----------------------------------------------------------------------------
void QueueTest::numElementsTest()
{
	CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mQueue->numElements());
	
   mQueue->enqueue(*mString1);
   mQueue->enqueue(*mString2);
   CPPUNIT_ASSERT_EQUAL(TWO_ELEMENTS, mQueue->numElements());
}

//-----------------------------------------------------------------------------
// Public Function: peekTest
//-----------------------------------------------------------------------------
void QueueTest::peekTest()
{
	// Try with no elements in the queue. Should throw an exception
   CPPUNIT_ASSERT_THROW (mQueue->peek(), std::out_of_range);
	
	// Try with one element in the queue
   mQueue->enqueue(*mString1);
   CPPUNIT_ASSERT_EQUAL(*mString1, mQueue->peek());
	
	// Try with two elements in the queue
   mQueue->enqueue(*mString1);
   mQueue->enqueue(*mString2);
   CPPUNIT_ASSERT_EQUAL(*mString1, mQueue->peek());
	
}

//-----------------------------------------------------------------------------
// Public Function: setUp
//-----------------------------------------------------------------------------
void QueueTest::setUp()
{
	mQueue = new dw::Queue<std::string>();
	mString1 = new std::string("String 1");
	mString2 = new std::string("String 2");

}

//-----------------------------------------------------------------------------
// Public Function: tearDown
//-----------------------------------------------------------------------------
void QueueTest::tearDown()
{
	delete mQueue;
	delete mString1;
	delete mString2;
}
