#include "StackTest.h"

const size_t NO_ELEMENTS  = 0;
const size_t ONE_ELEMENT  = 1;
const size_t TWO_ELEMENTS = 2;

CPPUNIT_TEST_SUITE_REGISTRATION(StackTest);

//-----------------------------------------------------------------------------
// Public Function StackTest
//-----------------------------------------------------------------------------
StackTest::StackTest()
{
}

//-----------------------------------------------------------------------------
// Public Function ~StackTest
//-----------------------------------------------------------------------------
StackTest::~StackTest()
{
}

//-----------------------------------------------------------------------------
// Public Function setUp
//-----------------------------------------------------------------------------
void StackTest::setUp()
{
    mStack   = new dw::Stack<std::string>();
    mString1 = new std::string("String 1");
    mString2 = new std::string("String 2");
}

//-----------------------------------------------------------------------------
// Public Function tearDown
//-----------------------------------------------------------------------------
void StackTest::tearDown()
{
    delete mStack;
    delete mString1;
    delete mString2;
}

//-----------------------------------------------------------------------------
// Public Function addElementTest
//-----------------------------------------------------------------------------
void StackTest::addElementTest()
{
    CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mStack->numElements());
    mStack->push(*mString1);
    CPPUNIT_ASSERT_EQUAL(ONE_ELEMENT, mStack->numElements());
    mStack->push(*mString2);
    CPPUNIT_ASSERT_EQUAL(TWO_ELEMENTS, mStack->numElements());
}

//-----------------------------------------------------------------------------
// Public Function copyConstructorTest
//-----------------------------------------------------------------------------
void StackTest::copyConstructorTest()
{

}

//-----------------------------------------------------------------------------
// Public Function emptyStackTest
//-----------------------------------------------------------------------------
void StackTest::emptyStackTest()
{
   /* Make sure it's ok to empty an already empty stack
    */
   mStack->emptyStack();
   CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mStack->numElements());

   /* Test emptying a non-empty stack
    */
   mStack->push(*mString1);
   mStack->push(*mString2);
   mStack->emptyStack();
   CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mStack->numElements());

}

//-----------------------------------------------------------------------------
// Public Function numElementsTest
//-----------------------------------------------------------------------------
void StackTest::numElementsTest()
{
    /* test that numElements works on an empty list.
     */
    CPPUNIT_ASSERT_EQUAL(NO_ELEMENTS, mStack->numElements());

    /* test that num elements works when an element has been added.
     */
    mStack->push(*mString1);
    CPPUNIT_ASSERT_EQUAL(ONE_ELEMENT, mStack->numElements());
    mStack->push(*mString2);
    CPPUNIT_ASSERT_EQUAL(TWO_ELEMENTS, mStack->numElements());

    /* TBD: Test for when elements are removed.
     */

}

//-----------------------------------------------------------------------------
// Public Function peekTest
//-----------------------------------------------------------------------------
void StackTest::peekTest()
{
   CPPUNIT_ASSERT_THROW (mStack->peek(), std::out_of_range);
   mStack->push(*mString1);
   mStack->push(*mString2);
   CPPUNIT_ASSERT_EQUAL(*mString2, mStack->peek());
	
	std::string testString = mStack->peek();
}

//-----------------------------------------------------------------------------
// Public Function popTest
//-----------------------------------------------------------------------------
void StackTest::popTest()
{
   /* Should throw exception when no elements on the stack.
    */
   CPPUNIT_ASSERT_THROW (mStack->pop(), std::out_of_range);

   mStack->push(*mString1);
   mStack->push(*mString2);

   /* Should return value equal to string 2 then string 1.
    */
   CPPUNIT_ASSERT_EQUAL(*mString2, mStack->pop());
   CPPUNIT_ASSERT_EQUAL(*mString1, mStack->pop());

   /* No more elements so should throw assertion
    */
   CPPUNIT_ASSERT_THROW (mStack->pop(), std::out_of_range);
}
