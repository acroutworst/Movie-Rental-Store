// ------------------------------------------------ inventory.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Inventory - This class will handle transactions by customers and contains the hash function to store movie library
// --------------------------------------------------------------------------------------------------------------------

#include "inventory.h"

Inventory::Inventory()
{
    for (int i = 0; i < GLOBAL_MAX; i++)
    {
        movieHash[i] = NULL;
    }
}

Inventory::~Inventory ()
{
    
}

void Inventory::buildHash(string movieArray[])
{
    
}
void Inventory::borrow(int movieID, int custID)
{
    
}

void Inventory::returnMovie(int movieID, int custID)
{
    
}

void Inventory::addStock(int movieID)
{
    
}