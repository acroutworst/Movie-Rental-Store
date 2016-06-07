// ------------------------------------------------ inventory.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Inventory - This class will handle transactions by customers and contains the hash function to store movie library
// --------------------------------------------------------------------------------------------------------------------

#include "inventory.h"

// --------------------- Inventory() ---------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// ----------------------------------------------------------------------------
Inventory::Inventory()
{
    for (int i = 0; i < GLOBAL_MAX; i++)
    {
        movieLibrary[i] = NULL;
    }
}

// --------------------- ~Inventory() ---------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// ----------------------------------------------------------------------------
Inventory::~Inventory ()
{
    
}

// --------------------- buildHash() ---------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// ----------------------------------------------------------------------------
void Inventory::buildHash(string movieArray[])
{
    
}

// --------------------- borrow() ---------------------------------------------
// Process customer borrowing movie transaction
// Preconditions: movie ID and customer ID
// Postconditions: stock modified and customer's borrowing history modified
// ----------------------------------------------------------------------------
void Inventory::borrow(int movieID, int custID)
{
    
}

// --------------------- returnMovie() ---------------------------------------------
// Process customer returning movie transaction
// Preconditions: movie ID and customer ID
// Postconditions: stock modified and customer's borrowing history modified
// ----------------------------------------------------------------------------
void Inventory::returnMovie(int movieID, int custID)
{
    
}

// --------------------- addStock() ---------------------------------------------
// Add stock of movie to store's inventory
// Preconditions: ID of movie to add to stock
// Postconditions: modified stock
// ----------------------------------------------------------------------------
void Inventory::addStock(int movieID)
{
    
}