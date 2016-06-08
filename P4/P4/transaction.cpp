// ------------------------------------------------ transaction.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Transaction - A transaction is used as a base class for other transaction types
// --------------------------------------------------------------------------------------------------------------------

#include "transaction.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor
//
Transaction::Transaction() : transType("Transaction"), mediaType(""), anItem(NULL)
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Transaction::Transaction(const Transaction& trans)
{
	transType = trans.transType;
	mediaType = trans.mediaType;
	anItem = trans.anItem;
} 

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Transaction::~Transaction() 
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
bool Transaction::setData(string media, Inventory * item, Customer * cust) {
	mediaType = media;
	anItem = item;

	return true;
}	

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void Transaction::display() const
{
	cout << mediaType << " " << transType << ": ";
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
string Transaction::getMediaType() 
{
	return mediaType;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
string Transaction::getTransactionType() 
{
	return transType;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Inventory * Transaction::getItem() const
{
	return anItem;
}

 // --------------------- Inventory() -------------------------------------------
 // Default constructor
 // Preconditions: none
 // Postconditions: none
 // -----------------------------------------------------------------------------
Transaction * Transaction::create()
{
	return new Transaction();
}
