#include "BinarySearchTreeTest.h"
CPPUNIT_TEST_SUITE_REGISTRATION(BinarySearchTreeTest);

using std::cout;
using std::endl;

BinarySearchTreeTest::BinarySearchTreeTest()
{
	mIntTree.add(20);
	mIntTree.add(30);
	mIntTree.add(40);
	mIntTree.add(15);
	mIntTree.add(35);
	mIntTree.add(25);
	mIntTree.add(5);
	mIntTree.add(2);
	mIntTree.add(7);
	mIntTree.add(17);

	mStringTree.add("Test");
	mStringTree.add("Find");
	mStringTree.add("Finds");
	mStringTree.add("Finder");
	mStringTree.add("Finding");
	mStringTree.add("Clock");
	mStringTree.add("clock");
	mStringTree.add("Walk");
	mStringTree.add("Hope");
	mStringTree.add("Dream");
	mStringTree.add("Then");
	mStringTree.add("Wind");
	mStringTree.add("saw");
	mStringTree.add("wind");
	mStringTree.add("Over");
	mStringTree.add("Care");
}

BinarySearchTreeTest::~BinarySearchTreeTest()
{

}

void BinarySearchTreeTest::setUp()
{
    CppUnit::TestFixture::setUp();
}

void BinarySearchTreeTest::tearDown()
{
    CppUnit::TestFixture::tearDown();
}

void BinarySearchTreeTest::addTest()
{
	bool isAdded = false;

	isAdded = mTree.add(20);
	CPPUNIT_ASSERT_EQUAL(true, isAdded);
	isAdded = mTree.add(30);
	CPPUNIT_ASSERT_EQUAL(true, isAdded);
	isAdded = mTree.add(40);
	CPPUNIT_ASSERT_EQUAL(true, isAdded);
	isAdded = mTree.add(15);
	CPPUNIT_ASSERT_EQUAL(true, isAdded);
	isAdded = mTree.add(35);
	CPPUNIT_ASSERT_EQUAL(true, isAdded);
	isAdded = mTree.add(25);
	CPPUNIT_ASSERT_EQUAL(true, isAdded);
	isAdded = mTree.add(5);
	CPPUNIT_ASSERT_EQUAL(true, isAdded);
	isAdded = mTree.add(2);
	CPPUNIT_ASSERT_EQUAL(true, isAdded);
	isAdded = mTree.add(7);
	CPPUNIT_ASSERT_EQUAL(true, isAdded);
	isAdded = mTree.add(17);
	CPPUNIT_ASSERT_EQUAL(true, isAdded);

	// Attempt to add a duplicate value to the tree.
	isAdded = mTree.add(2);
	CPPUNIT_ASSERT_EQUAL(false, isAdded);


}

void BinarySearchTreeTest::assignmentTest()
{

}

void BinarySearchTreeTest::copyConstructorTest()
{

}

void BinarySearchTreeTest::equalitytest()
{

}

void BinarySearchTreeTest::emptyTest() {
    mIntTree.empty();
    CPPUNIT_ASSERT_EQUAL(0, mIntTree.size());
}

void BinarySearchTreeTest::getMaxTest()
{
	int val = 0;

	try
	{
		val = mIntTree.getMax();
	}
	catch (const std::runtime_error& e)
	{
		cout << "Error occurred: " << e.what() << endl;
	}

	CPPUNIT_ASSERT_EQUAL(40, val);

	CPPUNIT_ASSERT_THROW(mEmptyTree.getMax(), std::runtime_error);

}

void BinarySearchTreeTest::getMinTest()
{
	int minValue = 0;

	try
	{
		minValue = mIntTree.getMin();
	}
	catch (const std::runtime_error& e)
	{
		std::cout << "Error occurred: " << e.what();
	}

	CPPUNIT_ASSERT_EQUAL(2, minValue);

	CPPUNIT_ASSERT_THROW(mEmptyTree.getMin(), std::runtime_error);
}

void BinarySearchTreeTest::inordertest()
{
	cout << endl;
	mEmptyTree.inorderPrint();
	mIntTree.inorderPrint();
	mStringTree.inorderPrint();

}

void BinarySearchTreeTest::postOrderTest()
{
	cout << endl;
	mEmptyTree.postorderPrint();
	mIntTree.postorderPrint();
	mStringTree.postorderPrint();
}

void BinarySearchTreeTest::preorderTest()
{
	cout << endl;
	mEmptyTree.preorderPrint();
	mIntTree.preorderPrint();
	mStringTree.preorderPrint();
}

void BinarySearchTreeTest::removeTest()
{

}

void BinarySearchTreeTest::searchTest()
{
	bool isFound = 0;

	// Search an empty tree. Should return false
	isFound = mEmptyTree.search(2);
	CPPUNIT_ASSERT_EQUAL(false, isFound);

	// Search for a value in the tree
	isFound = mIntTree.search(2);
	CPPUNIT_ASSERT_EQUAL(true, isFound);

	// Search for a value not in the tree
	isFound = mIntTree.search(1);
	CPPUNIT_ASSERT_EQUAL(false, isFound);

	// Search for a value in the tree
	isFound = mStringTree.search("Dream");
	CPPUNIT_ASSERT_EQUAL(true, isFound);

	// Search for a value not in the tree
	isFound = mStringTree.search("Dreaming");
	CPPUNIT_ASSERT_EQUAL(false, isFound);

}

