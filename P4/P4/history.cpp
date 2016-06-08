// ------------------------------------------------ history.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// History - This class will handle the history of the customer transactions 
// --------------------------------------------------------------------------------------------------------------------


#include "history.h"
#include "customer.h"

// --------------------- History() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
History::History() : Transaction()
{
	transType = "History";
}

// --------------------- History() -------------------------------------------
// Copy constructor
// Preconditions: History object
// Postconditions: Copied object of history
// -----------------------------------------------------------------------------
History::History(const History& hist) {
	transType = hist.transType;
	mediaType = hist.mediaType;
	anItem = hist.anItem;
}

// --------------------- ~History() -------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
History::~History() 
{
}

// --------------------- Set Data -------------------------------------------
// Output customer borrowing history
// Preconditions: type of media, item in inventory, and customer
// Postconditions: output of customer's history
// -----------------------------------------------------------------------------
bool History::setData(string media, Inventory * item, Customer * cust) 
{
	cust->displayCustomerHistory(); // Print customer history
	return false;
}

// --------------------- Create -------------------------------------------
// Create drama movie object in Transaction
// Preconditions: none
// Postconditions: history object created
// -----------------------------------------------------------------------------
Transaction * History::create() 
{
	return new History();
}