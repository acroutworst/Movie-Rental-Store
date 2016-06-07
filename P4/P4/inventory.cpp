// ------------------------------------------------ inventory.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Inventory - This class will handle transactions by customers and contains the hash function to store movie library
// --------------------------------------------------------------------------------------------------------------------

#include "inventory.h"

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Inventory::Inventory() : stockNumber(-1), maxStock(0) 
{
} 

// --------------------- ~Inventory() ---------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// --------------------------------------------------------------------------------
Inventory::~Inventory() 
{
} 

// --------------------- SetMaxCopies ---------------------------------------------
// SetMaxCopies: For an inventory item, the max copies (10)
// is produced
// Preconditions: Max copies
// Postconditions: Stock set to 10
// --------------------------------------------------------------------------------
void Inventory::setMaxCopies(const int maxCopies)
{
	maxStock = maxCopies;

	if (stockNumber < 0)
		stockNumber = maxCopies;
}

// --------------------- Increase Stock -------------------------------------------
// increaseStock: Increase the number of stock 
// Preconditions: Stock is not below 0; there is some stock.
//				  Stock is not at its max stock
// Postconditions: Stock is incremented by 1
// --------------------------------------------------------------------------------
void Inventory::increaseStock()
{
	if (stockNumber != maxStock)
		stockNumber++;
}	

// --------------------- Decrease Stock -------------------------------------------
// decreaseStock: Decrease the number of stock 
// Preconditions: Stock is not 0; there is some stock.
// Postconditions: Stock is decremented by 1
// --------------------------------------------------------------------------------
void Inventory::decreaseStock()
{
	if (stockNumber != 0)
		stockNumber--;
}

 // --------------------- Stock In -------------------------------------------------
 // stockIn: Get curret stock 
 // Preconditions: Stock is not less than 0 and greater than the max copies
 // Postconditions: Number of stock
 // --------------------------------------------------------------------------------
int Inventory::stockIn()
{
	return stockNumber;
}

// --------------------- Stock Out -------------------------------------------------
// stockOut: Get number of borrowed items 
// Preconditions: Stock is not less than 0 and greater than the max copies
// Postconditions: Number of borrowed stock
// --------------------------------------------------------------------------------
int Inventory::stockOut() 
{
	return maxStock - stockNumber;
}
