// ------------------------------------------------ borrow.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Borrow - This class will handle borrowed movies
// --------------------------------------------------------------------------------------------------------------------

#include "borrow.h"

// --------------------- Borrow() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Borrow::Borrow() : Transaction() 
{
	transType = "Borrow";
} 

// --------------------- Borrow() -------------------------------------------
// Copy constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Borrow::Borrow(const Borrow& borrow) 
{
	transType = borrow.transType;
	mediaType = borrow.mediaType;
	anItem = borrow.anItem;
} 

// --------------------- ~Borrow() -------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Borrow::~Borrow() 
{
} 

// --------------------- Set Data -------------------------------------------
// Modify data based on transaction
// Preconditions: type of media, item being borrowed, and customer involved
//                in transaction
// Postconditions: transaction processed
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

// --------------------- Display -------------------------------------------
// Display content of borrow transaction
// Preconditions: mediaType and transactionType to display
// Postconditions: formatted output
// -----------------------------------------------------------------------------
void Borrow::display() const 
{
	cout << mediaType << " " << transType << " ";
}

// --------------------- Borrow -------------------------------------------
// Create a borrow transaction
// Preconditions: Transaction class
// Postconditions: borrow transaction created
// -----------------------------------------------------------------------------
Transaction * Borrow::create() 
{
	return new Borrow();
}