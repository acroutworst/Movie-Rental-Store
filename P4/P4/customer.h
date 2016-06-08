// ------------------------------------------------ customer.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Customer - This class interacts with the inventory and includes the contents of a customer, 
// history of the customer, and a list of customers.
// --------------------------------------------------------------------------------------------------------------------



#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "movie.h"
#include <string>
#include <vector>
#include "transaction.h"
#include <iostream>

using namespace std;

class Customer 
{
public:
	Customer();								// Constructor
	Customer(istream&);						// Constructor with read in
	Customer(const Customer&);				// Copy constructor
	virtual ~Customer();					// Destructor

	// Inherited functions
	virtual void display() const;
	virtual bool operator==(const Customer&) const;
	virtual bool operator!=(const Customer&) const;

	void setData(istream& infile);			// Set inventory data
	void displayCustomerHistory() const;	// Display list of customer history
	void addTransaction(Transaction);		// Process a transaction
				
	int getCustomerID() const;				// Return customer ID
	string getFirstName() const;			// Return first name of customer 
	string getLastName() const;				// Return last name of customer


private:
	int id;									// ID of customer
	string firstName;						// First name of customer
	string lastName;						// Last name of customer
	vector<Transaction> transactionHistory; // Transaction history

};

#endif

