// ------------------------------------------------ bintree.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Binary Tree - This class will organize movies (comedy, classic, drama) so that the movies are organized
//				 by title, month/year, director, and actor first/last name.
// --------------------------------------------------------------------------------------------------------------------

#ifndef BINTREE_H
#define BINTREE_H

#include "movie.h"
#include "inventory.h"
#include <iostream>
#include <iomanip>

using namespace std;

class BinTree
{
	friend ostream& operator<<(ostream& output, BinTree& tree); // Overloaded output stream 
	struct Node;												// Reference to the node structure

public:
	BinTree();													// Constructor
	BinTree(const BinTree&);									// Copy constructor
	~BinTree();													// Destructor

	bool insert(Inventory* insertMovie, const int copiesIn);	// Insert node
	bool isEmpty() const;										// Check if tree is empty
	void makeEmpty();											// Remove all contents of tree
	bool retrieve(const Inventory& data, Inventory*& found) const;	// Retrieve value from tree
	void inorderDisplay(Node * curr) const;					// Display in-order traversal
	Node * getRoot() const;										// Get root

	// Helpers
	void retrieveHelper(Node* curr, const Inventory & data, Inventory*& found) const; // Helper for retrieve

private:

	struct Node
	{
		Inventory* movie;							// Inventory item pointer
		Node* left, *right;							// Left / right pointers  
	};
	Node *root;										// Root node

	// Helpers
	void inOrderDisplayHelper(Node* curr) const;    // Helper for display
	void destroyTree(Node*& tree);					// Helper for makeEmpty
};
#endif