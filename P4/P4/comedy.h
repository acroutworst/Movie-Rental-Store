// ------------------------------------------------ comedy.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Comedy - This class is derived from movie and serves as a comedy movie 
// Comedy is denoted as 'F'.
// --------------------------------------------------------------------------------------------------------------------

#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H

#include "movie.h"
#include <iomanip>
#include <string>

class ComedyMovie : public Movie 
{
public:
	ComedyMovie();						// Constructor
	ComedyMovie(const ComedyMovie&);	// Copy constructor
	~ComedyMovie();						// Destructor

	// Pure virtual functions
	virtual void display() const;						
	virtual void displayHeader() const;
	virtual void setData(istream&);
	virtual void setDataTwice(istream&);

	// Virtual Overloaded operators
	virtual bool operator==(const Inventory&) const;
	virtual bool operator<(const Inventory&) const;

	virtual Inventory * create(); 

private:
	const string GENRE; // genre
};



#endif