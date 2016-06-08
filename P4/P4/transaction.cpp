// ------------------------------------------------ transaction.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Transaction - A transaction is used as a base class for other transaction types
// --------------------------------------------------------------------------------------------------------------------

#include "transaction.h"

// --------------------- Transaction() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: Transaction type initiated, mediatype and anItem set to NULL
// -----------------------------------------------------------------------------
Transaction::Transaction() : transType("Transaction"), mediaType(""), anItem(NULL)
{
}

// --------------------- Transaction() -------------------------------------------
// Copy constructor
// Preconditions: const reference to a transaction
// Postconditions: copied transaction type, media type, and item
// -----------------------------------------------------------------------------
Transaction::Transaction(const Transaction& trans)
{
	transType = trans.transType;
	mediaType = trans.mediaType;
	anItem = trans.anItem;
} 

// --------------------- ~Transaction() -------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Transaction::~Transaction() 
{
}

// --------------------- Set Data -------------------------------------------
// Set data for transaction
// Preconditions: type of media, item in inventory, and customer
// Postconditions: transaction data set
// -----------------------------------------------------------------------------
bool Transaction::setData(string media, Inventory * item, Customer * cust) {
	mediaType = media;
	anItem = item;

	return true;
}	

// --------------------- Display -------------------------------------------
// Display transaction information
// Preconditions: none
// Postconditions: Output of media type and transaction type
// -----------------------------------------------------------------------------
void Transaction::display() const
{
	cout << mediaType << " " << transType << ": ";
}

// --------------------- Get Media Type -------------------------------------------
// Return media type of transaction
// Preconditions: none
// Postconditions: media type returned
// -----------------------------------------------------------------------------
string Transaction::getMediaType() 
{
	return mediaType;
}

// --------------------- Get Transaction Type -------------------------------------------
// Return type of transaction
// Preconditions: none
// Postconditions: type of transaction returned
// -----------------------------------------------------------------------------
string Transaction::getTransactionType() 
{
	return transType;
}

// --------------------- Get Item -------------------------------------------
// Return item used in transaction
// Preconditions: none
// Postconditions: item returned
// -----------------------------------------------------------------------------
Inventory * Transaction::getItem() const
{
	return anItem;
}

 // --------------------- Create -------------------------------------------
 // Create a transaction within the entire transaction class
 // Preconditions: none
 // Postconditions: Transaction created
 // -----------------------------------------------------------------------------
Transaction * Transaction::create()
{
	return new Transaction();
}
