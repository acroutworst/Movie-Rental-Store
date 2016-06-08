// ------------------------------------------------ movie.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Movie - This class is used as a base class to derive comedy, drama, and classic movies. 
// The inventory keeps track of the types of movies and its inventory>
// --------------------------------------------------------------------------------------------------------------------

#include "movie.h"

// --------------------- Movie() -----------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: Null for title, director, and year
// -----------------------------------------------------------------------------
Movie::Movie() : Inventory(), title(""), director(""), year(0) 
{
}

// --------------------- Movie() -----------------------------------------------
// Copy constructor
// Preconditions: Constant reference to movie object
// Postconditions: Set title, director, and year released of movie
// -----------------------------------------------------------------------------
Movie::Movie(const Movie& movie) 
{
	title = movie.title;
	director = movie.director;
	year = movie.year;
}

// --------------------- ~Movie() -------------------------------------------
// Destructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Movie::~Movie()
{
}

// --------------------- Display -------------------------------------------
// Display: display the contents of the movie
// Preconditions: Movie title, director, and year
// Postconditions: An output with the title then director then year
// -----------------------------------------------------------------------------
void Movie::display() const
{
	cout << title << " " << director << " " << year << endl;
}

// --------------------- Set Data -------------------------------------------
// setData: Read in the file of data
// Preconditions: Movie file data
// Postconditions: A string of director, title, and year
// -----------------------------------------------------------------------------
void Movie::setData(istream& infile) 
{
	infile.get();					
	getline(infile, director, ',');	// Read line of file

	infile.get();
	getline(infile, title, ',');    // Read line of file

	infile.get();
	infile >> year;					// Read year of file
}

// --------------------- Display Header -------------------------------------------
// displayHeader: Display header for Movie section
// Preconditions: none
// Postconditions: String containing header
// -----------------------------------------------------------------------------
void Movie::displayHeader() const 
{
	cout << " ****** MOVIE ITEM ***** " << endl;
}

// --------------------- Get Item -----------------------------------------------
// getItem: get inventory item
// Preconditions: none
// Postconditions: an immutable Inventory item
// -----------------------------------------------------------------------------
string Movie::getItem() const 
{
	return title;
}

// --------------------- Get Director -----------------------------------------------
// getDirector: get director of movie
// Preconditions: none
// Postconditions: string containing director name
// -----------------------------------------------------------------------------
string Movie::getDirector()
{
	return director;
} 

// --------------------- Get Title -----------------------------------------------
// getTitle: get title of movie
// Preconditions: none
// Postconditions: string containing title name
// -----------------------------------------------------------------------------
string Movie::getTitle() 
{
	return title;
}

// --------------------- Get Year -----------------------------------------------
// getYear: get release of movie
// Preconditions: none
// Postconditions: Return int of released year
// -----------------------------------------------------------------------------
int Movie::getYear() 
{
	return year;
}
