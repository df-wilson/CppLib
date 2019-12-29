/**
 * @class   Stack
 * @brief   A basic stack.
 * @author  Dean Wilson
 * @version 1.1
 * @date    December 12, 2013
 *
 * Library  DataStructs
 * 
 * Implements a basic stack. The stack is usable by any object type as well
 * as basic types. When an object is added to the stack a new copy is created.
 */

#ifndef STACK_H_
#define STACK_H_

/*---------  Program Includes  ----------------*/

#include "LinkedList.h"

/*---------  System Includes  -----------------*/


namespace dw {

/*---------  Forward Declarations   -----------*/

/*---------  Class Definition  ----------------*/

template<typename T>
class Stack
{

public:

   /*---------  Public Methods  ------------------*/

   /**
    * Default Constructor
    */
   Stack()
   {
      mLinkedList = new LinkedList<T> ();
   }

   /**
    * Destructor
    */
   virtual ~Stack()
   {
      delete mLinkedList;
   }

   /**
    * Removes all elements from the stack.
    */
   void emptyStack()
   {
      mLinkedList->emptyList();
   }

   /**
    * Get the number of elements in the stack.
    *
    * @return the number of objects on the stack.
    */
   size_t numElements() const
   {
      return mLinkedList->numElements();
   }

   /**
    * Look at the object at the top of the stack, but do not remove it.
    * The returned object is read-only.
    *
    * @exception std::out_of_range
    *
    * @return  the address of the object at the top of the stack
    */
   const T& peek() const
   {
      try
      {
         return mLinkedList->getLast();
      }
      catch (const std::out_of_range& e)
      {
         throw std::out_of_range("Stack is empty");
      }
   }

   /**
    * Removes the object on the top of the stack and returns it.
    *
    * @exception std::logic_error
    * @exception std::out_of_range
    *
    * @return the object on the top of the stack
    */
   T pop() const
   {
      try
      {
         return mLinkedList->popLastElement();
      }
      catch (const std::out_of_range& e)
      {
         throw std::out_of_range("Stack is empty");
      }
      catch (const std::logic_error)
      {
         throw std::logic_error("Logic error in the code");
      }
   }

   /**
    * Add an object onto the stack.
    *
    * @param T  IN  The object to push onto the stack
    */
   void push(T object)
   {
      mLinkedList->add(object);
   }

private:

   /*---------  Private Attributes  --------------*/

   LinkedList<T> *mLinkedList;
};

} // End namespace dw

#endif /* STACK_H_ */
