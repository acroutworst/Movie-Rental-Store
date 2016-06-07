// ------------------------------------------------ customer.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Customer - This class interacts with the inventory and includes the contents of a customer, 
// history of the customer, and a list of customers.
// --------------------------------------------------------------------------------------------------------------------



#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include "movie.h"
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"

using namespace std;

class Customer 
{
public:
	Customer();
	Customer(istream&);
	Customer(const Customer&);
	virtual ~Customer();

	void setData(istream& infile);

	void displayCustomerHistory() const;
	void addTransaction(Transaction);
	virtual void display() const;
	int getCustomerID() const;
	string getFirstName() const;
	string getLastName() const;
	virtual bool operator==(const Customer& ) const;
	virtual bool operator!=(const Customer& ) const;

private:
	int id;
	string firstName;
	string lastName;
	vector<Transaction> transactionHistory;

};

#endif

