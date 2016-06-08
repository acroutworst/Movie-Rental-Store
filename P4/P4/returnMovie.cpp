// ------------------------------------------------ returnMovie.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Return Movie - This class will handle returned movies
// --------------------------------------------------------------------------------------------------------------------

#include "returnMovie.h"

// --------------------- ReturnMovie() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ReturnMovie::ReturnMovie() : Transaction() 
{
	transType = "Return";
}

// --------------------- ReturnMovie() -------------------------------------------
// Copy constructor
// Preconditions: Constant reference to movie object
// Postconditions: set mediatype, transaction type, and item
// -----------------------------------------------------------------------------
ReturnMovie::ReturnMovie(const ReturnMovie& movie) 
{
	mediaType = movie.mediaType;
	transType = movie.transType;
	anItem = movie.anItem;
} 

// --------------------- ~ReturnMovie() -------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ReturnMovie::~ReturnMovie() 
{
}

// --------------------- Set Data -------------------------------------------
// Modify inventory when a customer returns movie
// Preconditions: type of media, item in inventory, and customer
// Postconditions: stock increased
// -----------------------------------------------------------------------------
bool ReturnMovie::setData(string media, Inventory * item, Customer * cust)
{
	if (item != NULL)		// If inventory item is not null,
	{
		mediaType = media;	// Assign media type
		anItem = item;		// Assign ite

		if (mediaType != "")
			anItem->increaseStock(); // and Increase stock by 1
	}

	return true;
}

// --------------------- Display -------------------------------------------
// Display type of media and type of transaction during return
// Preconditions: none
// Postconditions: output of return transaction
// -----------------------------------------------------------------------------
void ReturnMovie::display() const 
{
	cout << mediaType << " " << transType << " ";
} 

// --------------------- Create -------------------------------------------
// Create return movie object in Transaction
// Preconditions: none
// Postconditions: return movie object created
// -----------------------------------------------------------------------------
Transaction * ReturnMovie::create() 
{
	return new ReturnMovie();
} 