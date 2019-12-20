/**
 * @class   LinkedList
 * @brief   Implements a linked list.
 * @author  Dean Wilson 
 * @version 1.2
 * @date    January 14, 2014
 *
 * Library  DataStruct
 * 
 * Provides a linked list container. New copies of the data created and
 * added to the list. The original copy can be deleted after it has been
 * added to the list. Changes to the original will not change the version
 * stored on the list.
 * Note: This class is not thread safe.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*---------  Program Includes  ----------------*/


/*---------  System Includes  -----------------*/

#include <cstddef>
#include <string>
#include <stdexcept>

/*---------  Class Definition  ----------------*/
namespace dw {

template <typename T>
class LinkedList
{
public:
	
	/*---------  Public Methods  ------------------*/

	/**
	* Default Constructor
	*/
	LinkedList() :mHead(nullptr),
	              mCurrent(mHead),
	              mTail(mHead)
	{

	}

	/**
	* Copy Constructor. A new list is created and the data from the original
	* list is copied to this one.
	* 
	* @param linkedListIn The list to assign to this one.
	*/
	LinkedList(const LinkedList<T>& linkedListIn)
	{
		copy(linkedListIn);
	}

	/**
	 * Assignment operator.
	 * 
	 * @param linkedListIn The list to assign to this one.
	 * @return LinkedList< T >&
	 */
	LinkedList<T>& operator=(const LinkedList<T>& linkedListIn)
	{
		if(this != linkedListIn)
		{
			copy(linkedListIn);
		}
		
		return *this;
	}

	/**
	* Destructor
	*/
	~LinkedList()
	{
		//Delete any nodes that have been added.
		emptyList();
	}

	/**
	* Add an object to the end of the list. A new version of the object is
	* created and stored on the list.
	*
	* @param data  IN  the data to store in the list.
	*/
	void add(const T& data)
	{
		Elem* elem = new Elem;

		if(mHead == nullptr)
		{
			mHead = elem;
		}

		elem->data = data;
		elem->next = nullptr;
		elem->prev = mTail;

		// Update the current end of the list to point to the new element, then set
		// the tail to point to the new element which is now the end of the list.
		if(mTail != nullptr)
		{
			mTail->next = elem;
		}
		mTail = elem;
	}

	/**
	* Add a new element to the front of the queue 
	* 
	* @param data the data to add to the list
	* @return void
	*/
	void addToFront(const T& data)
	{
		if(mHead == nullptr)
		{
			add(data);
		}
		else
		{
			Elem* elem = new Elem;
			elem->data = data;
			
			Elem* temp = mHead;
			temp->prev = elem;
			
			mHead = elem;
			mHead->prev = nullptr;
			mHead->next = temp;
		}
	}
	
	/**
	* Removes all of the elements from the list.
	* @return void
	*/
	void emptyList()
	{
		Elem* lTemp = mHead;
		Elem* lNext = nullptr;

		while (lTemp != nullptr)
		{
			lNext = lTemp->next;
			delete lTemp;
			lTemp = lNext;
		}

		mHead    = nullptr;
		mTail    = nullptr;
		mCurrent = nullptr;
	}

	/**
	* Return a reference to the first element the list. The element is not removed
	* from the list.
	*
	* @exception std::out_of_range
	*
	* @returns   the first element in the list.
	*/
	T& getFirst()
	{
		if(mHead == nullptr)
		{
			throw std::out_of_range("List is empty");
		}

		/* Set mNext to point to the start of the list.
		*/
		mCurrent = mHead;

		return mHead->data;
	}

	/**
	* Return a reference to the data of the last element of the list. The element is 
	* not removed from the list.
	*
	* @exception std::out_of_range
	*
	* @returns   the last element in the list.
	*/
	T& getLast()
	{
		if(mTail == nullptr)
		{
			throw std::out_of_range("List is empty");
		}

		/* Set mCurrent to point to the end of the list.
		*/
		mCurrent = mTail;

		return mCurrent->data;
	}

	/**
	* Returns a const reference to the data of the next element in the list. To traverse
	* all items in the list from the first one, call getFirstElement. Ensure that there is a next
	* element before calling this method.
	*
	* @exception std::out_of_range
	* @exception std::logic_error
	*
	* @return    the next element in the list. This is for read-only access.
	*/
	T& getNext()
	{
		if(mCurrent == nullptr)
		{
			throw std::logic_error("Unexpected null");
		}

		mCurrent = mCurrent->next;

		if(mCurrent == nullptr)
		{
			throw std::out_of_range("Already at end of list");
		}

		return mCurrent->data;
	}

	/**
	* Returns a reference to the next element in the list. To traverse all items 
	* in the list from the first one, call getFirstElement. Ensure that there is a next
	* element before calling this method.
	*
	* @exception std::out_of_range
	* @exception std::logic_error
	*
	* @return    the previous element in the list. This is for read-only access.
	*/
	T& getPrev()
	{
		if(mCurrent == mHead)
		{
			throw std::out_of_range("Already at start of list");
		}

		mCurrent = mCurrent->prev;

		if(mCurrent == nullptr)
		{
			throw std::logic_error("Unexpected null value");
		}

		return mCurrent->data;
	}

	/**
	* @return the current number of elements in the list.
	*/
	size_t numElements() const
	{
		size_t length = 0;
		Elem*  elem   = mHead;

		while (elem != nullptr)
		{
			length++;
			elem = elem->next;
		}

		return length;
	}

	/**
	* Returns a copy of the first element in the list then removes it from the list.
	*
	* @exception std::logic_error
	* @exception std::out_of_range
	*
	* @return the last element of the list.
	*
	*/
	T popFirstElement()
	{
		int lNumElements = numElements();
		
		if(lNumElements == 0)
		{
			// If there are no elements in the list mHead and mTail should both
			// be null. If not throw an exception. Since there are no elements
			// don't try and remove one, just return.
			if(mHead != nullptr)
			{
				throw std::logic_error("There are no elements in the list but mHead is not null");
			}
			if(mTail != nullptr)
			{
				throw std::logic_error("There are no elements in the list but mTail is not null");
			}

			// There are no elements in the list so throw out_of_range
			throw std::out_of_range("No Elements in the list");
		}
		else
		{
			// There is at least one element in the list. Ensure mHead and mTail
			// are not null. If they are throw an exception otherwise remove the
			// last element.
			if(mHead == nullptr)
			{
				throw std::logic_error("There are elements in the list but mHead is null");
			}
			if(mTail == nullptr)
			{
				throw std::logic_error("there are elements in the list but mTail is null");
			}
			
			T temp = mHead->data;
			removeFirstElement();
			return temp;
		}
	}
	
	/**
	* Returns a copy of the last element in the list then removes it from the list.
	*
	* @exception std::logic_error
	* @exception std::out_of_range
	*
	* @return the last element of the list.
	*
	*/
	T popLastElement()
	{
		int lNumElements = numElements();

		if(lNumElements == 0)
		{
			/* If there are no elements in the list mHead and mTail should both
			* be null. If not throw an exception. Since there are no elements
			* don't try and remove one, just return.
			*/
			if(mHead != nullptr)
			{
				throw std::logic_error("There are no elements in the list but mHead is not null");
			}
			if(mTail != nullptr)
			{
				throw std::logic_error("There are no elements in the list but mTail is not null");
			}

			/* There are no elements in the list so throw out_of_range
			*/
			throw std::out_of_range("No Elements in the list");
		}
		else
		{
			/* There is at least one element in the list. Ensure mHead and mTail
			* are not null. If they are throw an exception otherwise remove the
			* last element.
			*/
			if(mHead == nullptr)
			{
				throw std::logic_error("There are elements in the list but mHead is null");
			}
			if(mTail == nullptr)
			{
				throw std::logic_error("there are elements in the list but mTail is null");
			}

			T lTemp = mTail->data;
			removeLastElement();

			return lTemp;
		}
	}

	/**
	* Removes the first element from the list and frees any memory allocated to
	* it. Does not throw and exception if there are no elements on the list.
	* 
	* @return void
	*/
	void removeFirstElement()
	{
		int lNumElements = numElements();
		
		if(lNumElements == 0)
		{
			/* If there are no elements in the list mHead and mTail should both
			* be null. If not throw an exception. Since there are no elements
			* don't try and remove one, just return.
			*/
			if(mHead != nullptr)
			{
				throw std::logic_error("There are no elements in the list but mHead is not null");
			}
			if(mTail != nullptr)
			{
				throw std::logic_error("There are no elements in the list but mTail is not null");
			}
		}
		else
		{
			if(mHead == nullptr)
			{
				throw std::logic_error("There are elements in the list but mHead is null");
			}
			
			Elem* elem = mHead;

			mHead = mHead->next;

			if(mHead != nullptr)
			{
				mHead->prev = nullptr;
			}
			delete elem;
			elem = nullptr;
		}
	}

	/**
	* Removes the last element from the list and frees any memory allocated to it. Does not
	* throw an exception if there are no elements in the list.
	* 
	* @exception std::logic_error Thrown if the list is empty, but the head and tail are not null.
	*/
	void removeLastElement()
	{
		int lNumElements = numElements();

		if(lNumElements == 0)
		{
			/* If there are no elements in the list mHead and mTail should both
			* be null. If not throw an exception. Since there are no elements
			* don't try and remove one, just return.
			*/
			if(mHead != nullptr)
			{
				throw std::logic_error("There are no elements in the list but mHead is not null");
			}
			if(mTail != nullptr)
			{
				throw std::logic_error("There are no elements in the list but mTail is not null");
			}
		}
		else
		{
			/* There is at least one element in the list. Ensure mHead and mTail
			* are not null. If they are throw an exception otherwise remove the
			* last element.
			*/
			if(mHead == nullptr)
			{
				throw std::logic_error("There are elements in the list but mHead is null");
			}
			if(mTail == nullptr)
			{
				throw std::logic_error("there are elements in the list but mTail is null");
			}

			Elem* lTemp = mTail;

			mTail = mTail->prev;

			/* If there is only one element in the list mTail now points to
			* null so don't try and set its next value which is now invalid.
			*/
			if(mTail != nullptr)
			{
				mTail->next = nullptr;
			}

			/* If mTail is null, then mHead should be as well since the list is now
			* empty.
			*/
			if(mTail == nullptr)
			{
				mHead = nullptr;
			}

			delete lTemp;
			lTemp = nullptr;
		}
	}

private:

   /*---------  Private Methods  -----------------*/
	
	void copy(const LinkedList<T>& linkedListIn)
	{
		mCurrent = nullptr;
		mHead    = nullptr;
		mTail    = nullptr;

		emptyList();
		
		// Create a pointer to the first data element in the list.
		Elem* elemToCopy = linkedListIn.mHead;

		// If the list to copy is not empty create the first node in the list and
		// set the head pointer to it.
		if(linkedListIn.mHead != nullptr)
		{
			// The new element of the new linked list.
			Elem* newElem = new Elem();
			newElem->data = linkedListIn.mHead->data;
			newElem->prev = nullptr;
			newElem->next = nullptr;

			mHead = newElem;
			mTail = mHead;

			if(linkedListIn.mCurrent == linkedListIn.mHead)
			{
				mCurrent = newElem;
			}

			// Create a new node for each additional element in the list that is being copied.
			elemToCopy = linkedListIn.mHead->next;

			while(elemToCopy != nullptr)
			{
				newElem = new Elem();
				newElem->data = elemToCopy->data;
				newElem->next = nullptr;
				newElem->prev = mTail;

				// Update the current end of the list to point to the new element, then set
				// the tail to point to the new element which is now the end of the list.
				mTail->next = newElem;
				mTail = newElem;

				if(linkedListIn.mCurrent == elemToCopy)
				{
					mCurrent = newElem;
				}

				elemToCopy = elemToCopy->next;
			}
		}
	}
	
   /*---------  Private Attributes  --------------*/
	
	/**
	* Stores one element of data as well as pointers to the next and previous
	* elements in the list.
	*/
	struct Elem
	{
		T     data;
		Elem* next;
		Elem* prev;
	};

	Elem* mHead;
	Elem* mCurrent;
	Elem* mTail;
};

} // End namespace dw

#endif // LINKEDLIST_H
