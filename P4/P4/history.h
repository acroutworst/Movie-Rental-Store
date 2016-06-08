// ------------------------------------------------ history.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// History - This class will handle the history of the customer transactions 
// --------------------------------------------------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"

class Customer;	// Customer instance

class History : public Transaction 
{
public:
	History();												// Constructor
	History(const History& rightSide);						// Copy constructor
	~History();												// Destructor

	// Pure virtual functions 
	virtual bool setData(string, Inventory *, Customer *);
	virtual Transaction * create();

};


#endif