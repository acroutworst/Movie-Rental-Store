//
//  customer.h
//  P4
//
//  Created by USER on 6/3/16.
//  Copyright (c) 2016 Shane. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "inventory.h"

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
