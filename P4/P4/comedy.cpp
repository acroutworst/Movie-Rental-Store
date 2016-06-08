// ------------------------------------------------ comedy.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Comedy - This class is derived from movie and serves as a comedy movie 
// --------------------------------------------------------------------------------------------------------------------

#include "comedy.h"

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ComedyMovie::ComedyMovie() : Movie(), GENRE("COMEDY") 
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ComedyMovie::ComedyMovie(const ComedyMovie& comedy) 
{
	title = comedy.title;
	year = comedy.year;
	director = comedy.director;
} 

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ComedyMovie::~ComedyMovie() 
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void ComedyMovie::display() const 
{
	cout << left << setw(22) << title << " "
		<< setw(18) << director << " "
		<< setw(5) << year << endl;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void ComedyMovie::displayHeader() const
{
	cout << "IN/OUT *TITLE*                *DIRECTOR*         *YEAR*  "
		<< endl;
	cout <<
		"---------------------------------------------------------------------"
		<< endl;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void ComedyMovie::setData(istream& infile) 
{
	infile.get();
	getline(infile, director, ',');		// Read director name

	if (director.size() > 18) 
	{
		title.resize(18);
	}

	infile.get();
	getline(infile, title, ',');		// Read title

	if (title.size() > 22)
	{
		title.resize(22);
	}

	infile.get();
	infile >> year;						// Read release year
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void ComedyMovie::setDataTwice(istream& infile)
{
	infile.get();
	getline(infile, title, ',');	

	infile >> year;

}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
bool ComedyMovie::operator==(const Inventory& movieItem) const 
{
	const ComedyMovie& comedy = static_cast<const ComedyMovie&>(movieItem);	// Cast Inventory item as comedy movie

	return (title == comedy.title && year == comedy.year);
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
bool ComedyMovie::operator<(const Inventory& movieItem) const 
{
	const ComedyMovie& aComedy = static_cast<const ComedyMovie&>(movieItem); // Cast inventory item as comedy movie

	if (title < aComedy.title)
		return true;
	else if (title == aComedy.title) 
	{
		return (year < aComedy.year);
	}
	else
		return false;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Inventory * ComedyMovie::create() 
{
	return new ComedyMovie();
}
