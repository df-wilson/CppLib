#ifndef BINARY_SEARCH_TREE_TEST_H
#define BINARY_SEARCH_TREE_TEST_H

#include <string>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../DataStructs/BinarySearchTree.h"

class BinarySearchTreeTest : public CPPUNIT_NS::TestFixture
{
public:
    BinarySearchTreeTest();
    ~BinarySearchTreeTest();
    void setUp();
    void tearDown();

private:

	dw::BinarySearchTree<int> mTree;
	dw::BinarySearchTree<int> mIntTree;
	dw::BinarySearchTree<int> mEmptyTree;
	dw::BinarySearchTree<std::string> mStringTree;

	void addTest();
	void assignmentTest();
	void copyConstructorTest();
   void emptyTest();
	void getMaxTest();
	void getMinTest();
	void inordertest();
	void preorderTest();
	void equalitytest();
	void postOrderTest();
	void removeTest();
	void searchTest();

	CPPUNIT_TEST_SUITE (BinarySearchTreeTest);
	CPPUNIT_TEST(addTest);
	CPPUNIT_TEST(assignmentTest);
	CPPUNIT_TEST(copyConstructorTest);
   CPPUNIT_TEST(emptyTest);
	CPPUNIT_TEST(getMaxTest);
	CPPUNIT_TEST(getMinTest);
	CPPUNIT_TEST(inordertest);
	CPPUNIT_TEST(preorderTest);
	CPPUNIT_TEST(equalitytest);
	CPPUNIT_TEST(postOrderTest);
	CPPUNIT_TEST(removeTest);
	CPPUNIT_TEST(searchTest);
	CPPUNIT_TEST_SUITE_END();
};

#endif // BINARY_SEARCH_TREE_TEST_H
