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
	ClassicMovie();
	ClassicMovie(const ClassicMovie& );
	~ClassicMovie();

	void setData(istream& infile);
	virtual void setDataTwice(istream& infile);
	void display() const;
	virtual void displayHeader() const;
	virtual bool operator==(const Inventory& ) const;
	virtual bool operator<(const Inventory& ) const;
	virtual Inventory * create();

private:
	string actorFName, actorLName;
	int month;
	const string GENRE;
};


#endif



