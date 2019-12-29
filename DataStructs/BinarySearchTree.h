/**
* @class   BinarySearchTree
* @brief   Implements a binary search tree.
* @author  Dean Wilson
* @version 1.2
* @date    January 27, 2014
*
* Library  UTIL
*
* Provides a binary search tree. New copies of the data created and
* added to the tree. The original copy can be deleted after it has been
* added to the tree. Changes to the original will not change the version
* stored on the tree.
*
* The element type to be stored in the tree must be comparable using the < operator.
*
* Note: This class is not thread safe.
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <memory>

using std::shared_ptr;
using std::make_shared;

namespace dw {

template <typename T>
class BinarySearchTree
{
public:

	/**
	 * @brief Add data to the tree. All data in the tree must be unique.
	 *
	 * @param data The data to be added to the tree.
	 * @return true if data was added to the tree, false if data is already in the tree.
	 */
	bool add(const T& data)
	{
		bool isSuccessful = add(mRoot, data);

		if(isSuccessful) {
			mSize++;
		}

		return isSuccessful;
	}

	void remove(const T& data)
	{
		bool isSuccessful = false;
		if(isSuccessful) {
			mSize--;
		}
	}

	void empty() {
		empty(mRoot, nullptr);
	}

	/**
	 * @brief Get the maximum value stored in the tree.
	 *
	 * @throw runtime_error If the tree is empty.
	 * @return T& The maximum value stored in the tree.
	 */
	T& getMax()
	{
		shared_ptr<Node> temp = mRoot;

		if(temp == nullptr)
		{
		throw std::runtime_error("Tree is empty");
		}

		while(temp->right != nullptr) {
		temp = temp->right;
		}

		return temp->data;
	}

	/**
	 * @brief Get the minimum value stored in the tree
	 *
	 * @throw runtime_error if the tree is empty
	 * @return T& The maximum value stored in the tree.
	 */
	T& getMin()
	{
		shared_ptr<Node> temp = mRoot;
		if(temp == nullptr)
		{
		throw std::runtime_error("Tree is empty");
		}

		while(temp->left != nullptr)
		{
		temp = temp->left;
		}

		return temp->data;
	}

	void inorderPrint() const
	{
		inorderPrint(mRoot);
		std::cout << std::endl;
	}

	void preorderPrint() const
	{
		preorderPrint(mRoot);
		std::cout << std::endl;
	}

	void postorderPrint() const
	{
		postorderPrint(mRoot);
		std::cout << std::endl;
	}

	/**
	 * @brief Search the tree to see if it contains the specified data
	 *
	 * @param data The data to search the tree for.
	 * @return true if found otherwise false
	 */
	bool search(const T& data) const
	{
		return search(mRoot, data);
	}

	/**
	 * @brief Get the number of items in the tree.
	 *
	 * @return The number of items in the tree.
	 */
	int size() const {
		return mSize;
	}

private:
	typedef struct Node_
	{
		T     data;
		shared_ptr<Node_> parent;
		shared_ptr<Node_> left;
		shared_ptr<Node_> right;
	} Node;

	shared_ptr<Node> mRoot;
	int mSize = 0;

	bool add(shared_ptr<Node>& node, const T& data)
	{
		bool isSuccesful = false;

		if(node == nullptr)
		{
		// A place for the data was found in the tree. Create a node and return true.
		node = createNode (data);
		isSuccesful = true;
		}
		else if(node->data == data)
		{
		// Duplicate data found. Since no duplicates allowed, return false.
		isSuccesful = false;
		}
		else if(data < node->data)
		{
		// Keep traversing the tree.
		isSuccesful = add(node->left, data);
		}
		else
		{
		// Keep traversing the tree
		isSuccesful =  add(node->right, data);
		}

		return isSuccesful;
	}

	shared_ptr<Node> createNode(const T& data)
	{
		//shared_ptr<Node> node(new Node);
		shared_ptr<Node> node = make_shared<Node>();
		node->data = data;
		node->left = nullptr;
		node->right = nullptr;

		return node;
	}

	void empty(shared_ptr<Node> node, shared_ptr<Node>parent)
	{
		if(node->left) {
			empty(node->left, node);
		}

		if(node->right) {
			empty(node->right, node);
		}

		// Remove the parent if it exists. If there is no parent then it is the root node so
		// remove the root node and set mRoot to nullptr.
		if(parent != nullptr) {
			if(node->data < parent->data) {
				parent->left = nullptr;
			}
			else {
				parent->right = nullptr;
			}
		}
		else {
			mRoot = nullptr;
		}

		mSize--;
	}

	void inorderPrint(const shared_ptr<Node> node) const
	{
		if(node != nullptr)
		{
		if(node->left)	inorderPrint(node->left);
		std::cout << node->data << " ";
		if(node->right) inorderPrint(node->right);
		}
	}

	void preorderPrint(const shared_ptr<Node> node) const
	{
		if(node != nullptr)
		{
		std::cout << node->data << " ";
		if(node->left)	preorderPrint(node->left);
		if(node->right) preorderPrint(node->right);
		}
	}

	void postorderPrint(const shared_ptr<Node> node) const
	{
		if(node != nullptr)
		{
		if(node->left)	postorderPrint(node->left);
		if(node->right) postorderPrint(node->right);
		std::cout << node->data << " ";
		}
	}

	bool search(const shared_ptr<Node> node, const T& data) const
	{
		bool isFound = false;

		if(node == nullptr)
		{
		isFound = false;
		}

		else if(data < node->data)
		{
		isFound = search(node->left, data);
		}
		else if(data > node->data)
		{
		isFound = search(node->right, data);
		}
		else
		{
		isFound = true;
		}

		return isFound;
	}
};

} // End namespace

#endif // BTREE_H
