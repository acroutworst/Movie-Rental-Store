// ------------------------------------------------ returnMovie.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Return Movie - This class will handle returned movies
// --------------------------------------------------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

class Customer;		// Customer instance

class ReturnMovie : public Transaction
{
public:
	ReturnMovie();						// Constructor
	ReturnMovie(const ReturnMovie&);	// Copy constructor
	virtual ~ReturnMovie();				// Destructor

	// Pure virtual functions
	virtual bool setData(string, Inventory *, Customer *);
	virtual void display() const;

	virtual Transaction * create();		// Return ReturnMovie object
};

#endif