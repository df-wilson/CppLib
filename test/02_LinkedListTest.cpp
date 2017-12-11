#include "catch.hpp"
#include "../DataStructs/LinkedList.h"

#include <string>

using namespace std;

const size_t NO_ELEMENTS    = 0;
const size_t ONE_ELEMENT    = 1;
const size_t TWO_ELEMENTS   = 2;
const size_t THREE_ELEMENTS = 3;
const size_t FOUR_ELEMENTS  = 4;

const string string1("String 1");
const string string2("String 2");
const string string3("String 3");

TEST_CASE("Test add element to linked list", "[linked-list]")
{
   dw::LinkedList<std::string> list;
   REQUIRE(list.numElements() == NO_ELEMENTS);
   
   list.add(string1);
   REQUIRE(list.numElements() == ONE_ELEMENT);

   list.add(string2);
   REQUIRE(list.numElements() == TWO_ELEMENTS);
   REQUIRE(list.getFirst() == string1);
   REQUIRE(list.getLast() == string2);

   list.add(string3);
   REQUIRE(list.numElements() == THREE_ELEMENTS);
   REQUIRE(list.getFirst() == string1);
   REQUIRE(list.getLast() == string3);
   
   string* newString = new string("New String");
   list.add(*newString);
   delete newString;
   newString = nullptr;
   
   REQUIRE(list.numElements() == FOUR_ELEMENTS);
   REQUIRE(list.getFirst() == string1);
   REQUIRE(list.getLast() == "New String");
}

TEST_CASE("Test add element to front", "[linked-list]")
{
   dw::LinkedList<std::string> list;
   REQUIRE(list.numElements() == NO_ELEMENTS);
	
	list.addToFront(string1);
	REQUIRE(list.numElements() == ONE_ELEMENT);
   
   list.addToFront(string2);
   REQUIRE(list.numElements() == TWO_ELEMENTS);
   REQUIRE(list.getFirst() == string2);
   REQUIRE(list.getLast() == string1);

   list.addToFront(string3);
   REQUIRE(list.numElements() == THREE_ELEMENTS);
   REQUIRE(list.getFirst() == string3);
   REQUIRE(list.getLast() == string1);
   
   string* newString = new string("New String");
   list.addToFront(*newString);
   delete newString;
   newString = nullptr;
   
   REQUIRE(list.numElements() == FOUR_ELEMENTS);
   REQUIRE(list.getFirst() == "New String");
   REQUIRE(list.getLast() == string1);
}

TEST_CASE("Test get number of elements", "[linked-list]")
{
	/* test that numElements works on an empty list.
	*/
   dw::LinkedList<std::string> list;
	REQUIRE(list.numElements() == NO_ELEMENTS);

	/* test that num elements works when an element has been added.
	*/
	list.add(string1);
	REQUIRE(list.numElements() == ONE_ELEMENT);
	list.add(string2);
	REQUIRE(list.numElements() == TWO_ELEMENTS);
	list.add(string3);
	REQUIRE(list.numElements() == THREE_ELEMENTS);

	list.popLastElement();
	REQUIRE(list.numElements() == TWO_ELEMENTS);
	list.removeFirstElement();
	REQUIRE(list.numElements() == ONE_ELEMENT);
}

TEST_CASE("Test get first", "[linked-list]")
{
   dw::LinkedList<std::string> list;
   REQUIRE_THROWS_AS(list.getFirst(), std::out_of_range);

   list.add(string1);
   list.add(string2);
   REQUIRE(list.getFirst() == string1);
}

TEST_CASE("Test get last", "[linked-list]")
{
   dw::LinkedList<std::string> list;
   REQUIRE_THROWS_AS(list.getLast(), std::out_of_range);

   list.add(string1);
   list.add(string2);
   REQUIRE(list.getLast() == string2);
}

TEST_CASE("Test get next",  "[linked-list]")
{
   dw::LinkedList<std::string> list;
   REQUIRE_THROWS_AS(list.getNext(), std::logic_error);

   list.add(string1);
   list.add(string2);
   list.add(string3);
   
   REQUIRE(list.getFirst() == string1);
   REQUIRE(list.getNext() == string2);
   REQUIRE(list.getNext() == string3);
   REQUIRE_THROWS_AS(list.getNext(), std::out_of_range);
}

TEST_CASE("Test get previous", "[linked-list]")
{
   dw::LinkedList<std::string> list;
   REQUIRE_THROWS_AS(list.getPrev(), std::logic_error);

   list.add(string1);
   list.add(string2);
   list.add(string3);
   
   REQUIRE(list.getLast() == string3);
   REQUIRE(list.getPrev() == string2);
   REQUIRE(list.getPrev() == string1);
   REQUIRE_THROWS_AS(list.getPrev(), std::out_of_range);
}

TEST_CASE("Test copy constructor", "[linked-list]")
{
   dw::LinkedList<std::string> list1;
   list1.add(string1);
   list1.add(string2);
   list1.add(string3);

   dw::LinkedList<std::string> list2(list1);

   REQUIRE(list2.numElements() == THREE_ELEMENTS); 
   REQUIRE(list2.getFirst() == string1);
   REQUIRE(list2.getNext() == string2);
   REQUIRE(list2.getNext() == string3);
   REQUIRE_THROWS_AS(list2.getNext(), std::out_of_range);
}

TEST_CASE("Test assignment operator", "[linked-list]")
{
   dw::LinkedList<std::string> list1;
   
   list1.add(string1);
   list1.add(string2);
   list1.add(string3);

   dw::LinkedList<std::string> list2 = list1;

   REQUIRE(list2.numElements() == THREE_ELEMENTS); 
   REQUIRE(list2.getFirst() == string1);
   REQUIRE(list2.getNext() == string2);
   REQUIRE(list2.getNext() == string3);
   REQUIRE_THROWS_AS(list2.getNext(), std::out_of_range);
}

TEST_CASE("Test pop last element", "[linked-list]")
{
   dw::LinkedList<std::string> list;
   REQUIRE_THROWS_AS(list.popLastElement(), std::out_of_range);

   list.add(string1);
   std::string tempString = list.popLastElement();
   REQUIRE(string1 == tempString);
}

TEST_CASE("Test remove first element", "[linked-list]")
{
   dw::LinkedList<std::string> list;
   REQUIRE_NOTHROW(list.removeFirstElement());

   // Test removing an element from the front of a list with 1 element.
   list.add(string1);
   REQUIRE(list.numElements() == ONE_ELEMENT);
   
   list.removeFirstElement();
   REQUIRE(list.numElements() == NO_ELEMENTS);
}

TEST_CASE("Test remove last element", "[linked-list]")
{
   dw::LinkedList<std::string> list;
   REQUIRE_NOTHROW(list.removeLastElement());

   // Test removing an element when there is only one in the list
   list.add(string1);
   REQUIRE(list.numElements() == ONE_ELEMENT);
   
   list.removeLastElement();
   REQUIRE(list.numElements() == NO_ELEMENTS);

   // Test removing the last element when there are more than one element in the list.
   list.add(string1);
   list.add(string2);
   list.removeLastElement();
   REQUIRE(list.numElements() == ONE_ELEMENT);
   REQUIRE(list.getFirst() == string1);

   list.removeLastElement();
   REQUIRE(list.numElements() == NO_ELEMENTS);

   // Test that removing an element from a list that had elements but is now
   // empty works correctly
   REQUIRE_NOTHROW(list.removeLastElement());
}
