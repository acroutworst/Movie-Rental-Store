// ------------------------------------------------ bintree.cpp -------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Binary Tree - This class will organize movies (comedy, classic, drama) so that the movies are organized
//				 by title, month/year, director, and actor first/last name.
// --------------------------------------------------------------------------------------------------------------------

#include "bintree.h"

// --------------------- BinTree() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
BinTree::BinTree() : root(NULL)
{
}

// --------------------- BinTree() -------------------------------------------
// Copy constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
BinTree::BinTree(const BinTree& tree) 
{
}

// --------------------- ~BinTree() -------------------------------------------
// Destructor
// Preconditions: Tree with one or more nodes
// Postconditions: A tree with nullified nodes
// -----------------------------------------------------------------------------
BinTree::~BinTree() 
{
	if (root != NULL)
		makeEmpty();
} 

// --------------------- Is Empty -------------------------------------------
// isEmpty: Check if tree is empty
// Preconditions: none
// Postconditions: Boolean indicating if tree is NULL 
// -----------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
	return (root == NULL);
}

// --------------------- Make Empty -------------------------------------------
// makeEmpty: make the tree empty
// Preconditions: A binary tree
// Postconditions: Method call to helper
// -----------------------------------------------------------------------------
void BinTree::makeEmpty()
{
	destroyTree(root);
}

// --------------------- Destroy Tree ------------------------------------------
// destroyTree: postorder removal of nodes
// Preconditions: A node to remove
// Postconditions: An empty tree
// -----------------------------------------------------------------------------
void BinTree::destroyTree(Node*& tree)
{
	if (tree != NULL)
	{
		destroyTree(tree->left);
		destroyTree(tree->right);

		delete tree->movie; 
		tree->movie = NULL;
		delete tree; 
		tree = NULL;
	}
}
 
// --------------------- Insert -------------------------------------------
// insert: Insert a node
// Preconditions: Insert node and amount of copies
// Postconditions: An updated tree with inserted movie node
// -----------------------------------------------------------------------------
bool BinTree::insert(Inventory* insertMovie, const int copiesIn) 
{
	
	Node* treePtr = new Node();

	treePtr->movie = insertMovie;			// Assign insertMovie node
	treePtr->movie->setMaxCopies(copiesIn); // Set max copies

	insertMovie = NULL;						// Set insert node to NULL
	treePtr->left = treePtr->right = NULL;	// Set right child of tree to NULL

	if (isEmpty())							// Check if tree is NULL
	{
		root = treePtr; 
	}
	else
	{
		Node* curr = root;				// Assign root to current 
		bool inserted = false;


		while (!inserted)								// While it's not inserted, traverse
		{
			if (*treePtr->movie == *curr->movie)		// If they are equivalent, erase new pointer
			{
				delete treePtr;
				treePtr = NULL;
				return false;
			}
			else if (*treePtr->movie < *curr->movie)	// If current is more than tree, insert in left child   
			{
				if (curr->left == NULL)
				{
					curr->left = treePtr;
					inserted = true;
				}
				else
					curr = curr->left;
			} else {									// Else assign to right child
				if (curr->right == NULL)
				{
					curr->right = treePtr;
					inserted = true;
				}
				else
					curr = curr->right;
			}
		}
	}

	return true;
} 

// --------------------- Retrieve -------------------------------------------
// Retrive data in a specific node in BST
// Preconditions: data to find, tracker to see if found
// Postconditions: data retrieved or not
// -----------------------------------------------------------------------------
bool BinTree::retrieve(const Inventory& data, Inventory*& found) const 
{
	retrieveHelper(root, data, found);

	if (found != NULL)
		return true;
	else
		return false;
} 

// --------------------- Retriver Helper -------------------------------------------
// Helper function for retrieve
// Preconditions: current node, data looking for, and tracker to see if found
// Postconditions: found data or not
// -----------------------------------------------------------------------------
void BinTree::retrieveHelper(Node* curr, const Inventory & data, Inventory*& found) const 
{
	if (curr == NULL)
		found = NULL;
	else if (data == *curr->movie)
	{
		found = curr->movie;
	}
	else if (data < *curr->movie)
		retrieveHelper(curr->left, data, found);
	else
		retrieveHelper(curr->right, data, found);
}

// --------------------- In Order Display -------------------------------------------
// Display data in BST using InOrder traversal
// Preconditions: current node to start at
// Postconditions: data displayed
// -----------------------------------------------------------------------------
void BinTree::inorderDisplay(Node * curr) const
{
	if (curr == root) 
	{
		curr->movie->displayHeader();
	}

	if (curr != NULL) 
	{
		inorderDisplay(curr->left);

		cout << right << setw(2) << curr->movie->stockIn() << "  " <<
			left << setw(3) << curr->movie->stockOut() << " ";
		curr->movie->display();

		inorderDisplay(curr->right);
	}
}

 // --------------------- Get Root -------------------------------------------
 // retrieve root of BST
 // Preconditions: none
 // Postconditions: root returned
 // -----------------------------------------------------------------------------
BinTree::Node * BinTree::getRoot() const 
{ 
	return this->root; 
}