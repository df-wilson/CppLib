#include "catch.hpp"
#include "../DataStructs/BinarySearchTree.h"
using namespace std;
using namespace dw;

BinarySearchTree<int> emptyTree;
BinarySearchTree<int> intTree;
BinarySearchTree<string> stringTree;

TEST_CASE("Add item test.", "[BST]")
{
   bool isAdded = intTree.add(20);
   REQUIRE(isAdded == true);
   isAdded = intTree.add(30);
   REQUIRE(isAdded == true);
   isAdded = intTree.add(40);
   REQUIRE(isAdded == true);
   isAdded = intTree.add(15);
   REQUIRE(isAdded == true);
   isAdded = intTree.add(35);
   REQUIRE(isAdded == true);
   isAdded = intTree.add(25);
   REQUIRE(isAdded == true);
   isAdded = intTree.add(5);
   REQUIRE(isAdded == true);
   isAdded = intTree.add(2);
   REQUIRE(isAdded == true);
   isAdded = intTree.add(7);
   REQUIRE(isAdded == true);
   isAdded = intTree.add(17);
   REQUIRE(isAdded == true);

   // Attempt to add a duplicate value to the intTree.
   isAdded = intTree.add(2);
   REQUIRE(isAdded == false);
   
   stringTree.add("Test");
   stringTree.add("Find");
   stringTree.add("Finds");
   stringTree.add("Finder");
   stringTree.add("Finding");
   stringTree.add("Clock");
   stringTree.add("clock");
   stringTree.add("Walk");
   stringTree.add("Hope");
   stringTree.add("Dream");
   stringTree.add("Then");
   stringTree.add("Wind");
   stringTree.add("saw");
   stringTree.add("wind");
   stringTree.add("Over");
   stringTree.add("Care");
   
   // Attempt to add a duplicate value to the stringTree.
   isAdded = stringTree.add("Clock");
   REQUIRE(isAdded == false);
}

TEST_CASE("Empty test", "[BST]")
{
   BinarySearchTree<int> tree;
   REQUIRE(tree.size() == 0);
   
   tree.add(45);
   tree.add(5);
   tree.add(15);
   REQUIRE(tree.size() == 3);
   
   tree.empty();
   REQUIRE(tree.size() == 0);
}

TEST_CASE("Get maximum value", "[BST]")
{   
   REQUIRE_THROWS_AS(emptyTree.getMax(), std::runtime_error);

   int    val = 0;
   string stringVal("");

   try
   {
      val = intTree.getMax();
   }
   catch (const std::runtime_error& e)
   {
      cout << "Error occurred: " << e.what() << endl;
   }

   REQUIRE(val == 40);
   
   try
   {
      stringVal = stringTree.getMax();
   }
   catch (const std::runtime_error& e)
   {
      cout << "Error occurred: " << e.what() << endl;
   }

   REQUIRE(stringVal == "wind");
}

TEST_CASE("Get minimum value", "[BST]")
{
   REQUIRE_THROWS_AS(emptyTree.getMin(), std::runtime_error);

   int    val = 0;
   string stringVal("");

   try
   {
      val = intTree.getMin();
   }
   catch (const std::runtime_error& e)
   {
      cout << "Error occurred: " << e.what() << endl;
   }

   REQUIRE(val == 2);
   
   try
   {
      stringVal = stringTree.getMin();
   }
   catch (const std::runtime_error& e)
   {
      cout << "Error occurred: " << e.what() << endl;
   }

   REQUIRE(stringVal == "Care");
}

TEST_CASE("In order test", "[BST]")
{
   emptyTree.inorderPrint();
   intTree.inorderPrint();
   stringTree.inorderPrint();
}

TEST_CASE("Post order test", "[BST]")
{
   emptyTree.postorderPrint();
   intTree.postorderPrint();
   stringTree.postorderPrint();
}

TEST_CASE("Pre order test", "[BST]")
{
   emptyTree.preorderPrint();
   intTree.preorderPrint();
   stringTree.preorderPrint();
}

TEST_CASE("Search test", "[BST]")
{
   bool isFound = 0;

   // Search an empty tree. Should return false
   isFound = emptyTree.search(2);
   REQUIRE(false == isFound);

   // Search for a value in the tree
   isFound = intTree.search(2);
   REQUIRE(true == isFound);

   // Search for a value not in the tree
   isFound = intTree.search(1);
   REQUIRE(false == isFound);

   // Search for a value in the tree
   isFound = stringTree.search("Dream");
   REQUIRE(true == isFound);

   // Search for a value not in the tree
   isFound = stringTree.search("Dreaming");
   REQUIRE(false == isFound);
}

