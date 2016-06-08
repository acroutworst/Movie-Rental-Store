// ------------------------------------------------ history.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// History - This class will handle the history of the customer transactions 
// --------------------------------------------------------------------------------------------------------------------


#include "history.h"
#include "customer.h"

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
History::History() : Transaction()
{
	transType = "History";
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
History::History(const History& hist) {
	transType = hist.transType;
	mediaType = hist.mediaType;
	anItem = hist.anItem;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
History::~History() 
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
bool History::setData(string media, Inventory * item, Customer * cust) 
{
	cust->displayCustomerHistory(); // Print customer history
	return false;
}

 // --------------------- Inventory() -------------------------------------------
 // Default constructor
 // Preconditions: none
 // Postconditions: none
 // -----------------------------------------------------------------------------
Transaction * History::create() 
{
	return new History();
}