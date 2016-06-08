// ------------------------------------------------ storemanager.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// StoreManager - This class keeps track of all transactions by the customer base
// --------------------------------------------------------------------------------------------------------------------

#include "storemanager.h"

// --------------------- StoreManager() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: name set to NULL
// -----------------------------------------------------------------------------
StoreManager::StoreManager() : name("") 
{
}

// --------------------- StoreManager() -------------------------------------------
// Copy constructor
// Preconditions: name of store or manager
// Postconditions: set name to copied name
// -----------------------------------------------------------------------------
StoreManager::StoreManager(string _Name) : name(_Name)
{
}

// --------------------- StoreManager() -------------------------------------------
// Copy constructor
// Preconditions: const reference to store manager
// Postconditions: none
// -----------------------------------------------------------------------------								   
StoreManager::StoreManager(const StoreManager& manager) 
{
}

// --------------------- ~StoreManager() -------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
StoreManager::~StoreManager() 
{
}

// --------------------- Create Customers -------------------------------------------
// Create list of customers for store
// Preconditions: file with customers
// Postconditions: customer list built up with data from file
// -----------------------------------------------------------------------------
void StoreManager::createCustomers(istream& infile)
{
	for (;;)
	{
		Customer* cust = new Customer();		// Customer pointer
		cust->setData(infile);					// Read in data from customer file 

		if (infile.eof())						// If end of file,
		{
			delete cust;						// delete pointer,
			cust = NULL;						// set to null, and break.
			break;
		}

		customerList[cust->getCustomerID()] = *cust; // Assign customer pointer to customer list
		delete cust;								 // Delete pointer and set to null
		cust = NULL;
	}
}

// --------------------- Create Inventory -------------------------------------------
// Create inventory by reading in data from file
// Preconditions: file with valid/invalid data
// Postconditions: inventory built for store
// -----------------------------------------------------------------------------
void StoreManager::createInventory(istream& infile)
{
	char ch = ' ';
	//char tempcomma = ' '; //temp comma to read in stock also
	//int stockValue = 0;

	for (;;)
	{
		infile >> ch;
		//infile >> tempcomma;
		//infile >> stockValue;

		if (infile.eof()) break;

		Inventory * addedMovie = factory.createMovie(ch, infile); 

		if (addedMovie != NULL)					// If created movie is not null,
		{
			addedMovie->setData(infile);		// Read input file into inventory item

			bool inserted = inventoryList[factory.convertToSubscript(ch)].insert(addedMovie, stockValue); // Insert addedMovie

			if (!inserted)						// If not inserted, 
			{
				delete addedMovie;				// delete addedMovie and print error message
				cout << "Not Inserted" << endl;
			}
		}
		addedMovie = NULL;						// Delete pointer and set to null
		delete addedMovie;
	}
}

// --------------------- Display -------------------------------------------
// Outputs customer list and inventory list
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void StoreManager::display() 
{
	displayCustomerBase();
	displayInventory();
}

// --------------------- Display Inventory -------------------------------------------
// Display inventory of store
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void StoreManager::displayInventory() const
{
	if (name != "")							// If not null, print inventory info
	{
		cout << "--------------------------------------------------------------" << endl;
		cout << "Inventory for " << name << endl;
		cout << "--------------------------------------------------------------" << endl;
	}

	for (int i = 0; i < MAXINVENTORY; i++)	// If not greater than max,
	{
		if (!inventoryList[i].isEmpty())	// and not empty,
		{

			inventoryList[i].inorderDisplay(inventoryList[i].getRoot());	// Print inorder traversal
			cout << endl;
		}
	}
}

// --------------------- Display Customer Base -------------------------------------------
// Display customer base of store
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void StoreManager::displayCustomerBase() const
{
	for (int i = 0; i < MAXCUSTOMERS; i++) // If not max,
	{
		if (lookUpCustomer(i)) 
		{
			getCustomer(i).display();	   // display customer 
		}
	}
}

// --------------------- Look Up Customer -------------------------------------------
// Locate customer in customer list
// Preconditions: ID number of customer to look for
// Postconditions: true if found, false if unable to find
// -----------------------------------------------------------------------------
bool StoreManager::lookUpCustomer(int IDNumber) const 
{
	if (customerList[IDNumber].getCustomerID() == -1) // If the IDs do not match up,
	{
		return false;								  // return false.
	}
	else											  // Else true
		return true;
} 

// --------------------- Get Business Name -------------------------------------------
// Get Business name of store
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
string StoreManager::getBusinessName() const
{
	return name;
}

// --------------------- Get Customer -------------------------------------------
// Get Customer name based on ID
// Preconditions: Customer ID
// Postconditions: none
// -----------------------------------------------------------------------------
Customer StoreManager::getCustomer(const int IDNumber) const
{
	return customerList[IDNumber]; // Return customer
}

// --------------------- Process Transactions -------------------------------------------
// Process Transaction: borrow, return
// Preconditions: File with transactions to process
// Postconditions: Modified stock, inventory, etc
// -----------------------------------------------------------------------------
void StoreManager::processTransactions(istream& infile)
{
	char actCh = ' ';
	char movCh = ' ';
	char medCh = ' ';
	char EOL = '\n';

	int custID = 0;
	bool found = false;
	string mediaType = "";

	Inventory * itemLoc = NULL;
	Customer * tempCust = NULL;
	Inventory *  tempItem = NULL;

	for (;;)
	{
		infile >> actCh;
		if (infile.eof()) break;

		if (actCh == 'I')						// If char is I, print inventory
		{
			displayInventory();
			actCh = ' ';
		}
		else if (infile.get() == EOL)
			actCh = ' ';
		else
		{
			Transaction * processedTran = factory.createTransaction(actCh, infile); // Create transaction

			if (processedTran != NULL)
			{
				infile >> custID;

				if (infile.eof()) break;

				if (lookUpCustomer(custID))						// If customer exists,
				{
					tempCust = &customerList[custID];			// Create a customer list

					bool isHistory = processedTran->setData(mediaType, itemLoc, tempCust); // Read transaction input data

					if (infile.get() != EOL && isHistory)		// If not EOL and history
					{
						infile >> medCh;

						mediaType = factory.getMediaType(medCh); // Get media type


						if (mediaType != "")					// If not empty
						{

							infile >> movCh;

							tempItem = factory.createMovie(movCh, infile); // Create movie 

							if (tempItem != NULL)				// If item is not null, 
							{
								tempItem->setDataTwice(infile);	// get additional info

								found = inventoryList[factory.convertToSubscript(movCh)].retrieve(*tempItem, itemLoc); // Inventory list

								if (found == false)				// If movie not found,
								{
									cout << "Error: Invalid Movie Request" << tempItem->getItem() << endl; // Print error message
								}

								delete tempItem;				// delete item and set to null
								tempItem = NULL;

								bool found2 = processedTran->setData(mediaType, itemLoc, tempCust); // Read transaction data

								if ((found && found2) && mediaType != "") // If movie and media type is not empty
								{
									customerList[custID].addTransaction(*processedTran); // Process transaction
								}

								delete processedTran;	// Delete processed transaction and set to null
								processedTran = NULL;
							} else {
								cout << "Error: " << movCh << " not Found" << endl; // If empty, show not found message

								if (processedTran != NULL)
									delete processedTran;
								processedTran = NULL;
							}

							string temp;

							getline(infile, temp, EOL);

							delete tempItem;
							tempItem = NULL;

						} else {
							string temp;
							getline(infile, temp, EOL);

							cout << "Error: Invalid Code " << medCh << endl; 

							if (processedTran != NULL)
								delete processedTran;
							processedTran = NULL;
						}
					} else {
						if (processedTran != NULL)
							delete processedTran;
						processedTran = NULL;
					}
				} else {
					cout << "Error: Invalid Customer ID " << custID << endl;

					if (processedTran != NULL)
						delete processedTran;
					processedTran = NULL;

					string temp;
					getline(infile, temp, EOL);
				}
			} else {
				cout << "Error: Invalid Action Code " << actCh << endl;

				if (processedTran != NULL)
					delete processedTran;
				processedTran = NULL;
			}
		}

		found = false; // Set pointers to null
		custID = 0;
		itemLoc = NULL;
		tempCust = NULL;
		tempItem = NULL;
	}
}