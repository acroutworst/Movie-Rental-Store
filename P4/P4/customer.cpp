// ------------------------------------------------ customer.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Customer - This class interacts with the inventory and includes the contents of a customer, 
// history of the customer, and a list of customers.
// --------------------------------------------------------------------------------------------------------------------

#include "customer.h"

// --------------------- Customer() ---------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// ----------------------------------------------------------------------------
Customer::Customer()
{
	for (int i = 0; i < GLOBALMAXCUST; i++)
	{
		customerHash[i].firstName = NULL;
		customerHash[i].lastName = NULL;
		customerHash[i].history = NULL;
	}
}

// --------------------- ~Customer() ---------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// ----------------------------------------------------------------------------
Customer::~Customer()
{
    
}

// --------------------- buildCustomerList() ---------------------------------------------
// Read in data from file and add to hash table
// Preconditions: file with data
// Postconditions: invalid data will not be included in hash table, otherwise has table
//                 will be built
// ----------------------------------------------------------------------------
void Customer::buildCustomerList(ifstream&)
{
    
}

// --------------------- displayHistory() ---------------------------------------------
// Display customer's borrowing history
// Preconditions: customer ID for which to display history
// Postconditions: history of specific customer displayed
// ----------------------------------------------------------------------------
void Customer::displayHistory(int custID)
{
  
}

// --------------------- addHistory() ---------------------------------------------
// Add a movie to a customer's borrowing history
// Preconditions: name of movie customer borrowed
// Postconditions: Customer's history vector will have new movie added
// ----------------------------------------------------------------------------
void Customer::addHistory(string movieName) //add movie to customer’s borrowing history
{
    
}

// --------------------- isCustomer() ---------------------------------------------
// Check if customer exists
// Preconditions: customer ID
// Postconditions: true if valid customer, false if not
// ----------------------------------------------------------------------------
bool Customer::isCustomer(int custID) //check if valid customer
{
    return true;
}