/**
 * @class   Queue
 * @brief   Implements a queue.
 * @author  Dean Wilson
 * @version 1.2
 * @date    January 14, 2014
 *
 * Library  DataStructs
 *
 * Implements a basic queue. The queue is usable by any object type as well
 * as basic types. When an object is added to the queue a new copy is created.
 * When a queue is destroyed, the memory for any remaining entries is freed.
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

/*---------  Program Includes  ----------------*/
#include "LinkedList.h"

/*---------  System Includes  -----------------*/
#include <cstddef>
#include <stdexcept>


namespace dw {

template <typename T>
class Queue 
{
public:
   /*---------  Public Methods  ------------------*/
	
   /**
    * @brief Default Constructor
    */
	Queue()
	{
		mLinkedList = new LinkedList<T>();
	}
	
	/**
	 * @brief Destructor
	 * 
	 */
	virtual ~Queue()
	{
		delete mLinkedList;
	}

	/**
	 * @brief Removes the first element in the queue and returns it.
	 * 
	 * @return The first element of the queue.
	 *
	 * @throw std::out_of_range
	 * @throw std::std::logic_error
	 */
	T dequeue()
	{
		T temp;
		try
		{
			temp = mLinkedList->popFirstElement();
		}
		catch (const std::out_of_range& e)
		{
			throw std::out_of_range("Queue is empty");
		}
		catch (const std::logic_error& e)
		{
			throw std::logic_error("Logic error in the code");
		}
		
		return temp;
	}

	/**
	 * @brief Add a new element to the back of the queue
	 * 
	 * @param data The data to add to the queue
	 * 
	 * @return void
	 */
	void enqueue(const T& dataIn)
	{
		mLinkedList->add(dataIn);
	}

	/**
	 * @brief Return the number of elements in the queue.
	 * 
	 * @return Number of elements in the queue.
	 */
	size_t numElements() const
	{
		return mLinkedList->numElements();
	}
	
	/**
	 * @brief Look at the object at the front of the queue, but do not remove it.
    * The returned object is read-only.
	 * 
	 * @return Read only address of the element at the front of the queue
	 *
	 * @throw std::out_of_range
	 */
	const T& peek() const
	{
		try {
			return mLinkedList->getFirst();
		}
		catch (std::out_of_range& e)
		{
			throw std::out_of_range("Queue is empty");
		}
	}
	
private:
	
   /*---------  Private Attributes  --------------*/
	
	LinkedList<T> *mLinkedList;

};

} // End namepace dw

#endif // QUEUE_H
