// ------------------------------------------------ drama.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Drama - This class is derived from movie and serves as a drama movie 
// --------------------------------------------------------------------------------------------------------------------

#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "movie.h"
#include <iomanip>

using namespace std;

class DramaMovie : public Movie 
{
public:
	DramaMovie();					// Constructor
	DramaMovie(const DramaMovie&);  // Copy constructor
	~DramaMovie();					// Destructor

	// Pure virtual functions
	virtual void display() const;
	virtual void displayHeader() const;
	virtual void setData(istream&);
	virtual void setDataTwice(istream&);

	// Inherited overloaded operators
	virtual bool operator==(const Inventory&) const;
	virtual bool operator<(const Inventory&) const;

	virtual Inventory * create(); 

private:
	const string GENRE;	// genre selection
};


#endif