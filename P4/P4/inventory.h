// ------------------------------------------------ inventory.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Inventory - This class will handle transactions by customers and contains the hash function to store movie library
// --------------------------------------------------------------------------------------------------------------------


#ifndef INVENTORY_H
#define INVENTORY_H

#include <iomanip>

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Inventory
{
public:
	Inventory();								// Constructor
	Inventory(const Inventory&);				// Copy constructor
	virtual ~Inventory();					    // Destructor
	
	virtual void setData(istream&) = 0;			// Set inventory data
	virtual void setDataTwice(istream&) = 0;	// Set additional inventory data
	virtual void display() const = 0;			// Display data
	virtual void displayHeader() const = 0;
	virtual string getItem() const = 0;			// Return the inventory item

	void setMaxCopies(const int);
	void increaseStock();						// Increase by 1
	void decreaseStock();						// Decrease by 1
	int stockIn();								// Return current stock
	int stockOut();								// Return borrowed stock

	virtual bool operator==(const Inventory&) const = 0;
	virtual bool operator<(const Inventory&) const = 0;
	virtual Inventory* create() = 0;			// Create instance of inventory

private:
	int stockNumber;
	int maxStock;
};

#endif