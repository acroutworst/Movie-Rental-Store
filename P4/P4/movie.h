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
    
	Movie();	
	Movie(const Movie& );
	~Movie();

	virtual void display() const; //display movie
	virtual void displayHeader() const = 0; //header for display function
	virtual void setData(istream& infile); //read in data
    virtual void setData2(istream&) = 0; //pure virtual version of setData

	virtual string getItem() const;	//retrieve item
	string getDirector(); //retrieve director
	string getTitle();	//retrive title
	int getYear();	//retrive year

    //pure virtual comparison operators
	virtual bool operator==(const Inventory&) const = 0;
	virtual bool operator<(const Inventory&) const = 0;
    
protected:
	string title;			// Movie title
	string director;		// Movie director
	int year;				// Released year of movie
						

};

#endif

