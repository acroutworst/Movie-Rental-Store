// ------------------------------------------------ storemanager.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// StoreManager - This class keeps track of all transactions by the customer base
// --------------------------------------------------------------------------------------------------------------------

#ifndef STOREMANAGER_H
#define STOREMANAGER_H
// Static definitions
#define MAXCUSTOMERS 10000
#define MAXINVENTORY 53

#include <iostream>
#include <fstream>
#include <vector>
#include "customer.h"
#include "hash.h"
#include "bintree.h"


using namespace std;

class StoreManager 
{
public:
	StoreManager();							// Constructor
	StoreManager(string);					// Constructor w/ name
	StoreManager(const StoreManager&);		// Copy constructor
	~StoreManager();						// Destructor

	bool lookUpCustomer(int) const;			// Search for customer
	string getBusinessName() const;			// Return name
	Customer getCustomer(const int) const;  // Return customer

	// Main functions
	void createCustomers(istream&);			// Create customer based on input stream
	void createInventory(istream&);			// Create inventory item based on input stream
	void processTransactions(istream&);		// Process transactions based on input stream

	void display();							
	void displayInventory() const;			// Display inventory list
	void displayCustomerBase() const;		// Display customers

private:
	Customer customerList[MAXCUSTOMERS];	// List of customers
	BinTree inventoryList[MAXINVENTORY];	// List of inventory
	vector<Transaction> storeTransactionHistory; // Transaction history
	Hash factory;

	string name;
};

#endif