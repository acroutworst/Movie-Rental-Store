// ------------------------------------------------ customer.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Customer - This class interacts with the inventory and includes the contents of a customer, 
// history of the customer, and a list of customers.
// --------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
        int custID; //customer ID
        string lastName; //customer last name
        string firstName; //customer first name
        vector<string> history; //customers borrowing history
    };
    
    vector<cust> customerList;	//list of customers
};
