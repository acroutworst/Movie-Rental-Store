//
//  inventory.h
//  P4
//
//  Created by USER on 6/3/16.
//  Copyright (c) 2016 Shane. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int GLOBAL_MAX = 100;

class Inventory
{
public:
    
    Inventory (); 		      // Default constructor
    ~Inventory (); 		      // Default destructor
    void buildHash(string movieArray[]); // Build hash of movies
    void borrow(int movieID, int custID); // Change stock by intaking movie and customer
    void returnMovie(int movieID, int custID); // Return contents of movie
    void addStock(int movieID);       // Add stock by movie info
    //Movie accessor;	      // Access a movie
    //Customer accessor; 	      // Access a customer
    void buildComedy();	      // Build comedy hash
    void buildDrama(); 	     // Build drama hash
    void buildClassic();          // build classic hash
    
private:
    
    int comedyHash[GLOBAL_MAX]; 	    //array hash table for inventory information
    int dramaHash[GLOBAL_MAX]; 		     //array hash table for inventory information
    int classicHash[GLOBAL_MAX]; 		     //array hash table for inventory information
};