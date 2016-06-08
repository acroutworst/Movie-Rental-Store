// ------------------------------------------------ comedy.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Comedy - This class is derived from movie and serves as a comedy movie 
// --------------------------------------------------------------------------------------------------------------------

#include "comedy.h"

// --------------------- ComedyMovie() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ComedyMovie::ComedyMovie() : Movie(), GENRE("COMEDY") 
{
}

// --------------------- ComedyMovie() -------------------------------------------
// Copy constructor
// Preconditions: ComedyMovie object
// Postconditions: Copied object of comedy movie
// -----------------------------------------------------------------------------
ComedyMovie::ComedyMovie(const ComedyMovie& comedy) 
{
	title = comedy.title;
	year = comedy.year;
	director = comedy.director;
} 

// --------------------- ~ComedyMovie() -------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
ComedyMovie::~ComedyMovie() 
{
}

// --------------------- Display -------------------------------------------
// Output Comedy movie details
// Preconditions: Movie with valid information to display
// Postconditions: Properly formatted output of a comedy movie
// -----------------------------------------------------------------------------
void ComedyMovie::display() const 
{
	cout << left << setw(22) << title << " "
		<< setw(18) << director << " "
		<< setw(5) << year << endl;
}

// --------------------- Display Header -------------------------------------------
// Helper function to display header of comedy movies
// Preconditions: none
// Postconditions: Header of comedy movies outputted
// -----------------------------------------------------------------------------
void ComedyMovie::displayHeader() const
{
	cout << "IN/OUT  TITLE                  DIRECTOR           YEAR  "
		<< endl;
	cout <<
		"---------------------------------------------------------------------"
		<< endl;
}

// --------------------- Set Data -------------------------------------------
// Read in file data to build comedy movie objects
// Preconditions: file with valid and invalid data
// Postconditions: Comedy movies read in
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

// --------------------- Set Data Twice -------------------------------------------
// Read in file data to build comedy movie objects, handles exceptions to 
// differently formatted years on comedies
// Preconditions: file with valid and invalid date
// Postconditions: Comedy movies read in
// -----------------------------------------------------------------------------
void ComedyMovie::setDataTwice(istream& infile)
{
	infile.get();
	getline(infile, title, ',');	

	infile >> year;

}

// --------------------- Operator== -------------------------------------------
// Comparison operator: compares comedy movies to see if same or not
// Preconditions: movies to compare
// Postconditions: true or false result
// -----------------------------------------------------------------------------
bool ComedyMovie::operator==(const Inventory& movieItem) const 
{
	const ComedyMovie& comedy = static_cast<const ComedyMovie&>(movieItem);	// Cast Inventory item as comedy movie

	return (title == comedy.title && year == comedy.year);
}

// --------------------- Operator< -------------------------------------------
// Comparison operator: compares comedy movies to determine ordering
// Preconditions: movies to compare
// Postconditions: true ot false result
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

// --------------------- Create -------------------------------------------
// Create comedy movie object in inventory
// Preconditions: none
// Postconditions: comedy movie object created
// -----------------------------------------------------------------------------
Inventory * ComedyMovie::create() 
{
	return new ComedyMovie();
}
