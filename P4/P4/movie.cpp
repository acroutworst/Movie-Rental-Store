// ------------------------------------------------ movie.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Movie - This class is used as a base class to derive comedy, drama, and classic movies. 
// The inventory keeps track of the types of movies and its inventory>
// --------------------------------------------------------------------------------------------------------------------

#include "movie.h"

// --------------------- Movie() ---------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// ----------------------------------------------------------------------------
/*Movie::Movie()
{
    
}

// --------------------- ~Movie() ---------------------------------------------
// Deconstructor
// Preconditions: none
// Postconditions: none
// ----------------------------------------------------------------------------
Movie::~Movie()
{
}

// --------------------- isMovie() ---------------------------------------------
// Function to check if valid movie or not
// Preconditions: movieID
// Postconditions: returns true or false result
// ----------------------------------------------------------------------------
bool Movie::isMovie(int *movieID)
{
    return 1;
}

// --------------------- changeStock() ---------------------------------------------
// Modify stock of a particular movie
// Preconditions: none
// Postconditions: none
// ----------------------------------------------------------------------------
void Movie::changeStock(int *movieID, int *newStock)
{
    
}*/

Movie::Movie() : Inventory(), title(""), director(""), year(0) {
}//end constructor

 //----------------------------------------------------------------------------
 // Copy Constructor
 // copies data from rightSide object into newly created movie object
 // @param rightSide movie object copying from
 //
Movie::Movie(const Movie& rightSide) {
	title = rightSide.title;
	director = rightSide.director;
	year = rightSide.year;
}//end copy constructor

 //----------------------------------------------------------------------------
 // Destructor
 // deallocates dynamically allocated memory and returns it to the heap
 //
Movie::~Movie() {
}//end destructor

 //----------------------------------------------------------------------------
 // Display
 // displays the title, year, month, director, and actor for specific movie
 //
void Movie::display() const {
	cout << title << " " << director
		<< " "
		<< year
		<< endl;
}//end display

 //----------------------------------------------------------------------------
 // Set Data
 // sets data for specific movie object from istream object parameter
 // @pre infile must be valid
 // @param infile istream object reading data from
 //
void Movie::setData(istream& infile) {
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;
} //end setData

  //----------------------------------------------------------------------------
  // Display Header
  //
void Movie::displayHeader() const {
	cout << " ****** MOVIE ITEM ***** "
		<< endl;
}	//end displayHeader

	//----------------------------------------------------------------------------
	// Get Item
	// returns the title of movie
	// @return title
	//
string Movie::getItem() const {
	return title;
}//end getItem

 //----------------------------------------------------------------------------
 // Get Director
 // returns the director of movie
 // @return director
 //
string Movie::getDirector() {
	return director;
} //end getDirector

  //----------------------------------------------------------------------------
  // Get Title
  // returns the title of the movie
  // @return title
  //
string Movie::getTitle() {
	return title;
}//end getTitle

 //----------------------------------------------------------------------------
 // Get Year
 // returns the year
 // @return year
 //
int Movie::getYear() {
	return year;
}//end getYear
