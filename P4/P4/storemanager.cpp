// ------------------------------------------------ storemanager.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// StoreManager - This class keeps track of all transactions by the customer base
// --------------------------------------------------------------------------------------------------------------------

#include "storemanager.h"

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
StoreManager::StoreManager() : name("") 
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
StoreManager::StoreManager(string _Name) : name(_Name)
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------								   
StoreManager::StoreManager(const StoreManager& manager) 
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
StoreManager::~StoreManager() 
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
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

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void StoreManager::createInventory(istream& infile)
{
	char ch = ' ';

	for (;;)
	{
		infile >> ch;

		if (infile.eof()) break;

		Inventory * addedMovie = factory.createMovie(ch, infile); 

		if (addedMovie != NULL)					// If created movie is not null,
		{
			addedMovie->setData(infile);		// Read input file into inventory item

			bool inserted = inventoryList[factory.convertToSubscript(ch)].insert(addedMovie, 10); // Insert addedMovie

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

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void StoreManager::display() 
{
	displayCustomerBase();
	displayInventory();
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
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

// --------------------- Inventory() -------------------------------------------
// Default constructor
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

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
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

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
string StoreManager::getBusinessName() const
{
	return name;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Customer StoreManager::getCustomer(const int IDNumber) const
{
	return customerList[IDNumber]; // Return customer
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
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
									cout << "ERROR: Invalid Movie Request!" << tempItem->getItem() << endl; // Print error message
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
								cout << "ERROR: " << movCh << " not Found!" << endl; // If empty, show not found message

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

							cout << "ERROR: Invalid Code " << medCh << endl; 

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
				cout << "ERROR: Invalid Action Code " << actCh << endl;

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