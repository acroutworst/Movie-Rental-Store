// ------------------------------------------------ borrow.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Borrow - This class will handle borrowed movies
// --------------------------------------------------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"
#include <iostream>
#include <string>

class Customer; // Customer instance

class Borrow : public Transaction 
{
public:
	Borrow();					// Constructor
	Borrow(const Borrow&);		// Copy constructor
	~Borrow();					// Destructor

	// Pure virtual functions
	virtual bool setData(string, Inventory *, Customer *);
	virtual void display() const;

	virtual Transaction * create();	// Return Borrow object

};


#endif
