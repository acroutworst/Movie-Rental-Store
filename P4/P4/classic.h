// ------------------------------------------------ classic.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Classic - This class extends the movie class and adds functionality of major actor and release date. 
// Classic is denoted as 'C'.
// --------------------------------------------------------------------------------------------------------------------


#ifndef CLASSICMOVIE_H
#define CLASSICMOVIE_H
#include <string>
#include <iomanip>
#include "movie.h"

class ClassicMovie : public Movie 
{
public:
	ClassicMovie();							// Constructor
	ClassicMovie(const ClassicMovie& );		// Copy constructor
	~ClassicMovie();						// Destructor

	void setData(istream& infile);			// Set inventory data
	virtual void setDataTwice(istream& infile); // Set additional inventory data
	
	void display() const;					// Display classic movies
	virtual void displayHeader() const;

	// Inherited funtions
	virtual bool operator==(const Inventory& ) const;
	virtual bool operator<(const Inventory& ) const;
	virtual Inventory * create();

private:
	string actorFirst, actorLast;			// Actor first and last name
	int month;								// Month of classic release
	const string GENRE;						// Genre of classic movie
};


#endif



