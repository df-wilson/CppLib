#include "catch.hpp"
#include "../DataStructs/Stack.h"

#include <string>

const size_t NO_ELEMENTS    = 0;
const size_t ONE_ELEMENT    = 1;
const size_t TWO_ELEMENTS   = 2;
const size_t THREE_ELEMENTS = 3;
const size_t FOUR_ELEMENTS  = 4;

const std::string string1("String 1");
const std::string string2("String 2");
const std::string string3("String 3");

TEST_CASE("Test add element to stack", "[stack]")
{
   dw::Stack<std::string> stack;
   REQUIRE(stack.numElements() == NO_ELEMENTS);
   stack.push(string1);
   REQUIRE(stack.numElements() == ONE_ELEMENT);
   stack.push(string2);
   REQUIRE(stack.numElements() == TWO_ELEMENTS);
}

TEST_CASE("Test emptying the stack", "[stack]")
{
   /* Make sure it's ok to empty an already empty stack
    */
   dw::Stack<std::string> stack;
   stack.emptyStack();
   REQUIRE(stack.numElements() == NO_ELEMENTS);

   /* Test emptying a non-empty stack
    */
   stack.push(string1);
   stack.push(string2);
   stack.emptyStack();
   REQUIRE(stack.numElements() == NO_ELEMENTS);

}

TEST_CASE("Test numElements functionality for the stack", "[stack]")
{
   dw::Stack<std::string> stack;
      
   /* test that numElements works on an empty list.
    */
   REQUIRE(stack.numElements() == NO_ELEMENTS);

    /* test that num elements works when an element has been added.
     */
    stack.push(string1);
    REQUIRE(stack.numElements() == ONE_ELEMENT);
    stack.push(string2);
    REQUIRE(stack.numElements() == TWO_ELEMENTS);

    /* TBD: Test for when elements are removed.
     */

}

TEST_CASE("Test peek functionality for the stack", "[stack]")
{
   dw::Stack<std::string> stack;
   REQUIRE_THROWS_AS(stack.peek(), std::out_of_range);
   
   stack.push(string1);
   stack.push(string2);
   REQUIRE(stack.peek() == string2);
	
   // Calling peek again should return the same value.
   REQUIRE(stack.peek() == string2);
   
   // Push a new element on the stack. Peek should return a copy of that.
   stack.push(string3);
   REQUIRE(stack.peek() == string3);
   
   stack.pop();
   REQUIRE(stack.peek() == string2);
   
   // Ensure a copy is returned.
   std::string temp = stack.peek();
   temp = "Changed";
   REQUIRE(stack.peek() == string2);
}

TEST_CASE("Test pop functionality for the stack", "[stack]")
{
   dw::Stack<std::string> stack;
      
   /* Should throw exception when no elements on the stack.
    */
   REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);

   stack.push(string1);
   stack.push(string2);

   /* Should return value equal to string 2 then string 1.
    */
   REQUIRE(stack.pop() == string2);
   REQUIRE(stack.pop() == string1);

   /* No more elements so should throw assertion
    */
   REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
}
