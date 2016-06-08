// ------------------------------------------------ classic.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Classic - This class extends the movie class and adds functionality of major actor and release date. 
// Classic is denoted as 'C'.
// --------------------------------------------------------------------------------------------------------------------

#include "classic.h"


// --------------------- ClassicMovie() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: Nullified actor first and last names, month, 
//					and genre is default as Classic
// -----------------------------------------------------------------------------
ClassicMovie::ClassicMovie() 
	: Movie(), actorFirst(""), actorLast(""), month(0), GENRE("CLASSIC") 
{
}

// --------------------- ClassicMovie() -------------------------------------------
// Copy constructor
// Preconditions: classic movie object
// Postconditions: A copied object of the classic movie
// -----------------------------------------------------------------------------
ClassicMovie::ClassicMovie(const ClassicMovie& classic) 
{
	director = classic.director;
	title = classic.title;
	actorFirst = classic.actorFirst;
	actorLast = classic.actorLast;
	month = classic.month;
	year = classic.year;
}

// --------------------- ClassicMovie() -------------------------------------------
// Destructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ClassicMovie::~ClassicMovie()
{
}

// --------------------- setData() -------------------------------------------
// Read in data from movie file
// Preconditions: file with info, valid and invalid
// Postconditions: movies will be read in and invalid data will not be kept
// -----------------------------------------------------------------------------
void ClassicMovie::setData(istream& infile) 
{
	infile.get();
	getline(infile, director, ',');

	if (director.size() > 18) {
		title.resize(18);
	}

	infile.get();
	getline(infile, title, ',');

	if (title.size() > 22) {
		title.resize(22);
	}

	infile.get();
	infile >> actorFirst >> actorLast;
	infile >> month >> year;
}

// --------------------- setDataTwice() -------------------------------------------
// Safety function to help read in data
// Preconditions: file with info, valid and invalid
// Postconditions: movies will be read in and invalid data will not be kept
// -----------------------------------------------------------------------------
void ClassicMovie::setDataTwice(istream& infile) 
{
	infile >> month;
	infile >> year;
	infile >> actorFirst;
	infile >> actorLast;

}

// --------------------- display() -------------------------------------------
// Display movie
// Preconditions: movie data to output
// Postconditions: properly formatted output, if no info in data types, will not
// output
// -----------------------------------------------------------------------------
void ClassicMovie::display() const 
{
	cout << left << setw(22) << title << " "
		<< setw(18) << director << " "
		<< setw(3) << month << " "
		<< setw(5) << year << " "
		<< actorFirst << " " << actorLast << endl;
}

// --------------------- displayHeader() -------------------------------------------
// Helper function to display the column headers for movies
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void ClassicMovie::displayHeader() const
{
	cout << "IN/OUT *TITLE*                *DIRECTOR*         *MO**YEAR* " <<
		"*ACTOR* " << endl;
	cout <<
		"---------------------------------------------------------------------"
		<< endl;
}

// --------------------- operator== -------------------------------------------
// Comparison operator to compare movies
// Preconditions: inventory built
// Postconditions: boolean result of equal (true) or not (false)
// -----------------------------------------------------------------------------
bool ClassicMovie::operator==(const Inventory& inv) const 
{

	const ClassicMovie& aClassic = static_cast<const ClassicMovie&>(inv);

	return (year == aClassic.year && month == aClassic.month
		&& actorFirst == aClassic.actorFirst &&
		actorLast == aClassic.actorLast);
}

// --------------------- operator< -------------------------------------------
// Comparison operator to determine sorting
// Preconditions: inventory built
// Postconditions: boolean result of less than (true) or greater than (false)
// -----------------------------------------------------------------------------
bool ClassicMovie::operator<(const Inventory& inv) const
{
	const ClassicMovie& aClassic = static_cast<const ClassicMovie&>
		(inv);

	if (year < aClassic.year)
		return true;
	else if (year == aClassic.year)
	{
		if (actorFirst < aClassic.actorFirst)
		{
			return true;
		}
		else if (actorFirst == aClassic.actorFirst)
		{
			return (actorLast < aClassic.actorLast);
		}
		else
			return false;
	}
	else
		return false;
}

// --------------------- create() -------------------------------------------
// Create a classic movie object
// Preconditions: none
// Postconditions: classic movie object created
// -----------------------------------------------------------------------------
Inventory * ClassicMovie::create() 
{
	return new ClassicMovie();
}