//
//  inventory.cpp
//  P4
//
//  Created by USER on 6/3/16.
//  Copyright (c) 2016 Shane. All rights reserved.
//

#include "inventory.h"

Inventory::Inventory()
{
    for (int i = 0; i < GLOBAL_MAX; i++)
    {
        comedyHash[i] = NULL;
        dramaHash[i] = NULL;
        classicHash[i] = NULL;
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