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

//----------------------------------------------------------------------------
// Class: Customer
// holds necessary information about customer base of store. Objects are 
// created from text file and stored in array inside of store.
//
//----------------------------------------------------------------------------
// 
//

class Customer {
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
	virtual bool operator==(const Customer& rightSide) const;
	virtual bool operator!=(const Customer& rightSide) const;
private:
	int id;
	string firstName;
	string lastName;
	vector<Transaction> transactionHistory;

};

#endif



/*#include "inventory.h"
#include <vector>

using namespace std;

const int GLOBALMAXCUST = 10000;

class Customer
{
public:
    Customer (); //default constructor
    ~Customer (); //deconstructor
    
    void buildCustomerList(ifstream&); //read information from file, build customerList
    void displayHistory(int custID); //display customer borrowing history
    void addHistory(string movieName); //add movie to customer’s borrowing history
    bool isCustomer(int custID); //check if valid customer
    
private:
    struct cust
    {
        //int custID; //customer ID
        string lastName; //customer last name
        string firstName; //customer first name
        vector<string> history; //customers borrowing history
    };

	Customer *customerHash = new Customer[GLOBALMAXCUST]; //customer hash table, can handle digits 0000-9999 per instructions
};*/
