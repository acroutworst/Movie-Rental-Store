// ------------------------------------------------ drama.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Drama - This class is derived from movie and serves as a drama movie 
// --------------------------------------------------------------------------------------------------------------------

#include "drama.h"

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
DramaMovie::DramaMovie() : Movie(), GENRE("DRAMA") 
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
DramaMovie::DramaMovie(const DramaMovie& drama) 
{
	title = drama.title;
	director = drama.director;
	year = drama.year;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
DramaMovie::~DramaMovie() 
{
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void DramaMovie::display() const
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
void DramaMovie::displayHeader() const 
{
	cout << "IN/OUT  TITLE                  DIRECTOR           YEAR  " << endl;
	cout << "---------------------------------------------------------------------" << endl;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void DramaMovie::setData(istream& infile) 
{
	infile.get();
	getline(infile, director, ',');		// Read director 

	infile.get();
	getline(infile, title, ',');		// Read title 

	infile.get();
	infile >> year;						// Read release year from file

} 

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void DramaMovie::setDataTwice(istream& infile) 
{
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
bool DramaMovie::operator==(const Inventory& inv) const 
{
	const DramaMovie& aDrama = static_cast<const DramaMovie&>(inv); // Cast inventory as drama movie

	return (title == aDrama.title && director == aDrama.director);
} 

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
bool DramaMovie::operator<(const Inventory& inv) const
{
	const DramaMovie& aDrama = static_cast<const DramaMovie&>(inv); // Cast inventory as comedy movie

	if (director < aDrama.director) 
	{
		return true;
	}
	else if (director == aDrama.director)
	{
		return (title < aDrama.title);
	}
	else
		return false;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Inventory * DramaMovie::create() 
{
	return new DramaMovie();
}