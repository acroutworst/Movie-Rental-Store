// ------------------------------------------------ transaction.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Transaction - A transaction is used as a base class for other transaction types
// --------------------------------------------------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "movie.h"
#include "inventory.h"
#include <string>

class Customer; // Customer instance

class Transaction
{
public:
	Transaction();								// Constructor
	Transaction(const Transaction&);			// Copy constructor
	virtual ~Transaction();						// Destructor

	string getMediaType();						// Get media type
	string getTransactionType();				// Get transaction type
	Inventory * getItem() const;				// Get inventory item

	// Pure virtual Functions
	virtual bool setData(string media, Inventory * item, Customer * aCustomer);	
	virtual void display() const;// display
	virtual Transaction * create();

protected:
	string transType;							// Transaction type
	string mediaType;							// Media type
	Inventory * anItem;							// Inventory item

};

#endif
