// ------------------------------------------------ customer.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Customer - This class interacts with the inventory and includes the contents of a customer, 
// history of the customer, and a list of customers.
// --------------------------------------------------------------------------------------------------------------------

#include "customer.h"

Customer::Customer()
{
	for (int i = 0; i < GLOBALMAXCUST; i++)
	{
		customerHash[i].firstName = NULL;
		customerHash[i].lastName = NULL;
		customerHash[i].history = NULL;
	}
}

Customer::~Customer()
{
    
}

void Customer::buildCustomerList(ifstream&)
{
    
}

void Customer::displayHistory(int custID)
{
  
}

void Customer::addHistory(string movieName) //add movie to customer’s borrowing history
{
    
}

bool Customer::isCustomer(int custID) //check if valid customer
{
    return true;
}