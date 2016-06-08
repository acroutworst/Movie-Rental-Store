// ------------------------------------------------ drama.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Drama - This class is derived from movie and serves as a drama movie 
// --------------------------------------------------------------------------------------------------------------------

#include "drama.h"

// --------------------- DramaMovie() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
DramaMovie::DramaMovie() : Movie(), GENRE("DRAMA") 
{
}

// --------------------- DramaMovie() -------------------------------------------
// Copy constructor
// Preconditions: ComedyMovie object
// Postconditions: Copied object of comedy movie
// -----------------------------------------------------------------------------
DramaMovie::DramaMovie(const DramaMovie& drama) 
{
	title = drama.title;
	director = drama.director;
	year = drama.year;
}

// --------------------- ~DramaMovie() -------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
DramaMovie::~DramaMovie() 
{
}

// --------------------- Display -------------------------------------------
// Output Drama movie details
// Preconditions: Movie with valid information to display
// Postconditions: Properly formatted output of a drama movie
// -----------------------------------------------------------------------------
void DramaMovie::display() const
{
	cout << left << setw(22) << title << " "
		<< setw(18) << director << " "
		<< setw(5) << year << endl;
}

// --------------------- Display Header -------------------------------------------
// Helper function to display header of drama movies
// Preconditions: none
// Postconditions: Header of drama movies outputted
// -----------------------------------------------------------------------------
void DramaMovie::displayHeader() const 
{
	cout << "IN/OUT  TITLE                  DIRECTOR           YEAR  " << endl;
	cout << "---------------------------------------------------------------------" << endl;
}

// --------------------- Set Data -------------------------------------------
// Read in file data to build drama movie objects
// Preconditions: file with valid and invalid data
// Postconditions: Drama movies read in
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

// --------------------- Set Data Twice -------------------------------------------
// Read in file data to build drama movie objects, handles exceptions to 
// differently formatted years on dramas
// Preconditions: file with valid and invalid date
// Postconditions: Drama movies read in
// -----------------------------------------------------------------------------
void DramaMovie::setDataTwice(istream& infile) 
{
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');
}

// --------------------- Operator== -------------------------------------------
// Comparison operator: compares drama movies to see if same or not
// Preconditions: movies to compare
// Postconditions: true or false result
// -----------------------------------------------------------------------------
bool DramaMovie::operator==(const Inventory& inv) const 
{
	const DramaMovie& aDrama = static_cast<const DramaMovie&>(inv); // Cast inventory as drama movie

	return (title == aDrama.title && director == aDrama.director);
} 

// --------------------- Operator< -------------------------------------------
// Comparison operator: compares drama movies to determine ordering
// Preconditions: movies to compare
// Postconditions: true ot false result
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

// --------------------- Create -------------------------------------------
// Create drama movie object in inventory
// Preconditions: none
// Postconditions: drama movie object created
// -----------------------------------------------------------------------------
Inventory * DramaMovie::create() 
{
	return new DramaMovie();
}