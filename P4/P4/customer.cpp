// ------------------------------------------------ customer.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Customer - This class interacts with the inventory and includes the contents of a customer, 
// history of the customer, and a list of customers.
// --------------------------------------------------------------------------------------------------------------------

#include "customer.h"

// --------------------- Customer() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Customer::Customer() : id(-1), firstName(""), lastName("") 
{
	transactionHistory.reserve(10);
}

// --------------------- Customer() -------------------------------------------
// Constructor with read file in param
// Preconditions: Input file
// Postconditions: Call method to read data from input
// -----------------------------------------------------------------------------
Customer::Customer(istream& infile)
{
	setData(infile);
}

// --------------------- Customer() -------------------------------------------
// Copy constructor
// Preconditions: none
// Postconditions: A copy of the customer object
// -----------------------------------------------------------------------------
Customer::Customer(const Customer& cust)
{
	id = cust.id;
	firstName = cust.firstName;
	lastName = cust.lastName;
}

// --------------------- Inventory() -------------------------------------------
// Destructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Customer::~Customer()
{
}

// --------------------- Set Data -------------------------------------------
// setData: Read in data from file
// Preconditions: Customer file data
// Postconditions: A string with id, first and last names
// -----------------------------------------------------------------------------
void Customer::setData(istream& infile) 
{
	infile >> id;

	if (infile.eof()) return;

	infile.get();
	infile >> lastName;

	infile.get();
	infile >> firstName;
}

// --------------------- Display Customer History -------------------------------------------
// displayCustomerHistory: helper for display
// Preconditions: none
// Postconditions: An output displaying customer history
// -----------------------------------------------------------------------------
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

// --------------------- Add Transaction -------------------------------------------
// addTransaction: Add transaction to stack
// Preconditions: Transaction object and vector of transaction history
// Postconditions: Vector of transaction history with added transaction
// -----------------------------------------------------------------------------
void Customer::addTransaction(Transaction trans)
{
	transactionHistory.push_back(trans);
}

// --------------------- Display -------------------------------------------
// display: display customer history
// Preconditions: none
// Postconditions: Call to display customer history
// -----------------------------------------------------------------------------
void Customer::display() const 
{
	displayCustomerHistory();
}

// --------------------- Customer ID -------------------------------------------
// getCustomerID: return customer ID
// Preconditions: none
// Postconditions: integer ID
// -----------------------------------------------------------------------------
int Customer::getCustomerID() const 
{ 
	return id; 
}

// --------------------- First Name -------------------------------------------
// getFirstName: return first name of customer 
// Preconditions: none
// Postconditions: String of customer name
// -----------------------------------------------------------------------------
string Customer::getFirstName() const 
{ 
	return firstName; 
}

// --------------------- Last Name -------------------------------------------
// getLastName: return last name of customer
// Preconditions: none
// Postconditions: string of customer name
// -----------------------------------------------------------------------------
string Customer::getLastName() const 
{ 
	return lastName; 
}

// --------------------- Operator== -------------------------------------------
// operator==: Check if current customer equals passed customer
// Preconditions: A param with customer object
// Postconditions: Boolean; true if a match, false if not
// -----------------------------------------------------------------------------
bool Customer::operator==(const Customer& cust) const 
{
	return (id == cust.id);
} 

// --------------------- Operator!= -------------------------------------------
// operator!=: Check to see if current cust. is not equal to passed cust.
// Preconditions: Param with customer object
// Postconditions: Boolean; true if not a match, false if it is a match
// -----------------------------------------------------------------------------
bool Customer::operator!=(const Customer& cust) const 
{
	return (id != cust.id);
}
