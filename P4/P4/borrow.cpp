// ------------------------------------------------ borrow.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Borrow - This class will handle borrowed movies
// --------------------------------------------------------------------------------------------------------------------

#include "borrow.h"

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Borrow::Borrow() : Transaction() 
{
	transType = "Borrow";
} 

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Borrow::Borrow(const Borrow& borrow) 
{
	transType = borrow.transType;
	mediaType = borrow.mediaType;
	anItem = borrow.anItem;
} 

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Borrow::~Borrow() 
{
} 

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
bool Borrow::setData(string media, Inventory * item, Customer * cust) 
{
	if (item != NULL)				// If borrowed,
	{
		mediaType = media;			// Assign media type
		anItem = item;				// Assign inventory item

		if (mediaType != "")
		{
			anItem->decreaseStock(); // and Decrease stock by 1
		}

	}
	return true;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void Borrow::display() const 
{
	cout << mediaType << " " << transType << " ";
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Transaction * Borrow::create() 
{
	return new Borrow();
}