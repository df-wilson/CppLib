#include "catch.hpp"
#include "../DataStructs/Queue.h"

#include <string>

const size_t NO_ELEMENTS    = 0;
const size_t ONE_ELEMENT    = 1;
const size_t TWO_ELEMENTS   = 2;
const size_t THREE_ELEMENTS = 3;
const size_t FOUR_ELEMENTS  = 4;

const std::string string1("String 1");
const std::string string2("String 2");
const std::string string3("String 3");

TEST_CASE("Test enqueue", "[queue]")
{
   dw::Queue<std::string> queue;
   queue.enqueue(string1);
   queue.enqueue(string2);
   REQUIRE(queue.numElements() == TWO_ELEMENTS);
   REQUIRE(queue.peek() == string1);
}

TEST_CASE("Test dequeue", "[queue]")
{
   dw::Queue<std::string> queue;
      
   // Try with no elements in the queue. Should throw an exception
   REQUIRE_THROWS_AS (queue.dequeue(), std::out_of_range);

   // Try with one element in the queue
   queue.enqueue(string1);
   std::string returnedString = queue.dequeue();
   REQUIRE(queue.numElements() == NO_ELEMENTS);
   REQUIRE(returnedString == string1);
}

TEST_CASE("Test get num elements",  "[queue]")
{
   dw::Queue<std::string> queue;
   queue.enqueue(string1);
   queue.enqueue(string2);
   REQUIRE(queue.numElements() == TWO_ELEMENTS);
}

TEST_CASE("Test peek functionality",  "[queue]")
{
   dw::Queue<std::string> queue;
      
   // Try with no elements in the queue. Should throw an exception
   REQUIRE_THROWS_AS (queue.peek(), std::out_of_range);

   // Try with one element in the queue
   queue.enqueue(string1);
   REQUIRE(queue.peek() == string1);
   
   // Try with two elements in the queue
   queue.enqueue(string2);
   queue.enqueue(string3);
   REQUIRE(queue.peek() == string1);
   
   // dequeue and enqueue then try peek again.
   queue.dequeue();
   queue.enqueue(string1);
   REQUIRE(queue.peek() == string2);
}
