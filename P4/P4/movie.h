// ------------------------------------------------ movie.h -----------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Movie - This class is used as a base class to derive comedy, drama, and classic movies. 
// The inventory keeps track of the types of movies and its inventory>
// --------------------------------------------------------------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H

#include "inventory.h"
#include <iostream>

using namespace std;


class Movie : public Inventory 
{
public:
	Movie();									// Constructor
	Movie(const Movie& );						// Copy constructor
	~Movie();									// Destructor

	// Inherited functions
	virtual void display() const;				// Pure virtual for display 
	virtual void displayHeader() const = 0;		
	virtual void setData(istream& infile);		// Set inventory data
	virtual void setDataTwice(istream&) = 0;	// Set additional inventory data
	virtual string getItem() const;				// Return the inventory item

	string getDirector();						// Return director
	string getTitle();							// Return title
	int getYear();								// Return year

	// Inherited operator overloads
	virtual bool operator==(const Inventory&) const = 0;
	virtual bool operator<(const Inventory&) const = 0;
	virtual Inventory* create() = 0;			

protected:
	string title;			// Movie title
	string director;		// Movie director
	int year;				// Released year of movie
						

};

#endif

