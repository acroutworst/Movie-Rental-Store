// ------------------------------------------------ customer.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Customer - This class interacts with the inventory and includes the contents of a customer, 
// history of the customer, and a list of customers.
// --------------------------------------------------------------------------------------------------------------------

#include "customer.h"

//----------------------------------------------------------------------------
// Constructor
// default constructor for customer class. sets the stock on creation.
//
Customer::Customer() : id(-1), firstName(""), lastName("") {
	transactionHistory.reserve(10);	//sets a reserved size of the vector
}//end constructor

 //----------------------------------------------------------------------------
 // Constructory
 // constructor from istream
 // @pre infile must be valid
 // @param infile istream reading from
 // 
Customer::Customer(istream& infile) {
	setData(infile);
}//end constructor

 //----------------------------------------------------------------------------
 // Copy Constructor
 // copies rightSide's information to a newly created Customer object
 // @pre infile must be valid
 // @param rightSide Customer object copying data from
 //
Customer::Customer(const Customer& rightSide) {
	id = rightSide.id;
	firstName = rightSide.firstName;
	lastName = rightSide.lastName;
} //end copy Constructor

  //----------------------------------------------------------------------------
  // Destructor
  // Deallocates dynammically allocated memory back to the heap
  //
Customer::~Customer() {
	for (int i = 0; i < (int)transactionHistory.size(); i++) {
		//delete transactionHistory[i];
		//transactionHistory[i];		
		//I don't know if I need this
	}//end for
}//end destructor

 //----------------------------------------------------------------------------
 // Set Data
 // sets customer information from istream object
 // @pre infile must be valid
 // @param infile instream object reading data from
 //
void Customer::setData(istream& infile) {
	infile >> id;
	if (infile.eof()) return;
	infile.get();
	infile >> lastName;

	infile.get();
	infile >> firstName;
}//end setData

 //----------------------------------------------------------------------------
 // Display Customer History
 // outputs the history vector for specified customer
 //
void Customer::displayCustomerHistory() const {
	cout << " **** Customer: " << id << " " << lastName << ", " << firstName
		<< endl;
	int size = transactionHistory.size();
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			transactionHistory[i].display();
			transactionHistory[i].getItem()->display();
		}//end for
		cout << endl;
	}//end if
	else
		cout << "No Transactions for Customer" << endl;
	cout << endl;
} //end displayCustomerHistory

  //----------------------------------------------------------------------------
  // Add Transaction
  // adds a transaction to the transaction history of a Customer
  // @param trans transaction item adding
  //
void Customer::addTransaction(Transaction trans) {
	transactionHistory.push_back(trans);
}//end addTransaction

 //----------------------------------------------------------------------------
 // Display
 // displays the customer along with their history
 //
void Customer::display() const {
	displayCustomerHistory();
}//end display

 //----------------------------------------------------------------------------
 // Get Customer ID
 // returns the ide of a customer
 // @return id
 //
int Customer::getCustomerID() const { return id; }//end getCustomerID

												  //----------------------------------------------------------------------------
												  // Get First Name
												  // returns first name of customer
												  // @return firstName
												  //
string Customer::getFirstName() const { return firstName; }//end getFirstName

														   //----------------------------------------------------------------------------
														   // Get Last Name
														   // returns last name of a customer
														   // @return lastName
														   //
string Customer::getLastName() const { return lastName; }//end getLastName

														 //----------------------------------------------------------------------------
														 // Operator == 
														 // overloaded == operator that tests equality between two customer objects
														 // @param rightSide right side of equality test
														 // @return true if equal, false otherwise
														 //
bool Customer::operator==(const Customer& rightSide) const {
	return (id == rightSide.id);
} //end operator==

  //----------------------------------------------------------------------------
  // Operator !=
  // overloaded != operator that tests inequality between two customer objects
  // @param rightSide right side of inequality test
  // @return true if inequal, false otherwise
  //
bool Customer::operator!=(const Customer& rightSide) const {
	return (id != rightSide.id);
}//end operator!=


/*#include "customer.h"

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
}*/