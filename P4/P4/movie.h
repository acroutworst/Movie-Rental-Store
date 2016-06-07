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

/*class Movie
{
public:
	Movie(); //default constructor
	~Movie(); //deconstructor

	bool isMovie(int *movieID); //check if valid movie

private:
	struct movie
	{
		char Type; //Movie genre type
		int Stock; //Current stock
		string Director; //name of director
		string Title; //Title of movie
		int releaseYear; //year of release
	};

	void changeStock(int *movieID, int *newStock); //modify stock

};*/

class Movie : public Inventory {
public:
	Movie();	//constructor
	Movie(const Movie& rightSide);
	~Movie();	//destructor

	virtual void display() const;
	virtual void displayHeader() const = 0;
	virtual void setData(istream& infile);
	virtual void setData2(istream&) = 0;	//addition information to set

	virtual string getItem() const;	//return the inventory item
	string getDirector(); //returns the director
	string getTitle();	//returns the title
	int getYear();		//returns the year

						//these must be overridden in order to determin sort orders
	virtual bool operator==(const Inventory&) const = 0;
	virtual bool operator<(const Inventory&) const = 0;
	virtual Inventory* create() = 0;

protected:
	string title;		//title of movie
	string director;	//director of movie
	int year;			//year created
						//const string GENRE;

};

#endif

