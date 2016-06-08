// ------------------------------------------------ returnMovie.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Return Movie - This class will handle returned movies
// --------------------------------------------------------------------------------------------------------------------

#include "returnMovie.h"

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ReturnMovie::ReturnMovie() : Transaction() 
{
	transType = "Return";
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ReturnMovie::ReturnMovie(const ReturnMovie& movie) 
{
	mediaType = movie.mediaType;
	transType = movie.transType;
	anItem = movie.anItem;
} 

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ReturnMovie::~ReturnMovie() 
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
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

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void ReturnMovie::display() const 
{
	cout << mediaType << " " << transType << " ";
} 

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Transaction * ReturnMovie::create() 
{
	return new ReturnMovie();
} 