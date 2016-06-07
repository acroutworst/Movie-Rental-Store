// ------------------------------------------------ main.cpp ----------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Main - This program is intended to initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt), and then
// process an arbitrary sequence of commands from a third file(data4commands.txt).
// --------------------------------------------------------------------------------------------------------------------

#include "classic.h"
#include "movie.h"
#include "customer.h"
#include "storemanager.h"
#include <iostream>
#include <fstream>

int main() {

	StoreManager storeManager("MOVIE: Buy My Stuff");

	ifstream infile1("data4movies.txt");		// Read in text files
	ifstream infile2("data4customers.txt");
	ifstream infile3("data4commands.txt");

	if (!infile1 || !infile2 || !infile3)		// Perform error checking on files
	{
		cout << "File could not be opened" << endl;
		return 1;
	}

	storeManager.createCustomers(infile2);		// Create customers through method call from storemanager
	storeManager.createInventory(infile1);		// Pass through the movies text file and build the store inventory
	storeManager.processTransactions(infile3);	// Process all transactions by commands file

	return 0;
}
