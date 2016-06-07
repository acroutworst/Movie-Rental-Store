// ------------------------------------------------ movie.h -----------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Movie - This class is used as a base class to derive comedy, drama, and classic movies. 
// The inventory keeps track of the types of movies and its inventory>
// --------------------------------------------------------------------------------------------------------------------
#ifndef _MOVIE_H_
#define _MOVIE_H_

#include "inventory.h"
#include <iostream>

using namespace std;


class Movie : public Inventory 
{
public:
	Movie();	
	Movie(const Movie& );
	~Movie();	

	virtual void display() const;
	virtual void displayHeader() const = 0;
	virtual void setData(istream& infile);
	virtual void setData2(istream&) = 0;	

	virtual string getItem() const;	
	string getDirector();
	string getTitle();	
	int getYear();		

	virtual bool operator==(const Inventory&) const = 0;
	virtual bool operator<(const Inventory&) const = 0;
	virtual Inventory* create() = 0;

protected:
	string title;		
	string director;	
	int year;			
						

};

#endif

