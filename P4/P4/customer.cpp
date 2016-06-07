// ------------------------------------------------ customer.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Customer - This class interacts with the inventory and includes the contents of a customer, 
// history of the customer, and a list of customers.
// --------------------------------------------------------------------------------------------------------------------

#include "customer.h"


Customer::Customer() : id(-1), firstName(""), lastName("") 
{
	transactionHistory.reserve(10);
}

Customer::Customer(istream& infile)
{
	setData(infile);
}

Customer::Customer(const Customer& cust)
{
	id = cust.id;
	firstName = cust.firstName;
	lastName = cust.lastName;
}

Customer::~Customer()
{
	for (int i = 0; i < (int)transactionHistory.size(); i++) 
	{
		delete transactionHistory[i];
		transactionHistory[i] = NULL;		
	}
}

void Customer::setData(istream& infile) 
{
	infile >> id;

	if (infile.eof()) return;

	infile.get();
	infile >> lastName;

	infile.get();
	infile >> firstName;
}

void Customer::displayCustomerHistory() const
{
	cout << " **** Customer: " << id << " " << lastName << ", " << firstName << endl;
	int size = transactionHistory.size();

	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			transactionHistory[i].display();
			transactionHistory[i].getItem()->display();
		}
		cout << endl;
	} else
		cout << "No Transactions for Customer" << endl;
	cout << endl;
}

void Customer::addTransaction(Transaction trans)
{
	transactionHistory.push_back(trans);
}

void Customer::display() const 
{
	displayCustomerHistory();
}

int Customer::getCustomerID() const 
{ 
	return id; 
}

string Customer::getFirstName() const 
{ 
	return firstName; 
}

string Customer::getLastName() const 
{ 
	return lastName; 
}

bool Customer::operator==(const Customer& cust) const 
{
	return (id == cust.id);
} 

bool Customer::operator!=(const Customer& cust) const 
{
	return (id != cust.id);
}
