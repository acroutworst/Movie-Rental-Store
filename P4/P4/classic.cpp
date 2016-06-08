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

<<<<<<< HEAD
// --------------------- setData() -------------------------------------------
// Read in data from movie file
// Preconditions: file with info, valid and invalid
// Postconditions: movies will be read in and invalid data will not be kept
=======
// --------------------- Set Data -------------------------------------------
// setData: Set inventory data
// Preconditions: An input stream from movie file
// Postconditions: A string of actor first/last names
//				   and release month and year
>>>>>>> ae0cff8c539ddb566a4f3b4018da488fc3a0b534
// -----------------------------------------------------------------------------
void ClassicMovie::setData(istream& infile) 
{
	infile.get();
	getline(infile, director, ',');	// Read director

	if (director.size() > 18) {		// Resize width if text is too large
		title.resize(18);
	}

	infile.get();
	getline(infile, title, ',');	// Read title	

	if (title.size() > 22) {		// Resize width if text is too large
		title.resize(22);
	}

	infile.get();
	infile >> actorFirst >> actorLast;
	infile >> month >> year;
}

<<<<<<< HEAD
// --------------------- setDataTwice() -------------------------------------------
// Safety function to help read in data
// Preconditions: file with info, valid and invalid
// Postconditions: movies will be read in and invalid data will not be kept
=======
// --------------------- Set Data -------------------------------------------
// setDataTwice: Set additional inventory data
// Preconditions: Input file stream
// Postconditions: string wit month, year, first, and last name
>>>>>>> ae0cff8c539ddb566a4f3b4018da488fc3a0b534
// -----------------------------------------------------------------------------
void ClassicMovie::setDataTwice(istream& infile) 
{
	infile >> month;
	infile >> year;
	infile >> actorFirst;
	infile >> actorLast;

}

<<<<<<< HEAD
// --------------------- display() -------------------------------------------
// Display movie
// Preconditions: movie data to output
// Postconditions: properly formatted output, if no info in data types, will not
// output
=======
// --------------------- Display -------------------------------------------
// Display: display classic movie data 
// Preconditions: none
// Postconditions: String of classic data from title to actor last name
>>>>>>> ae0cff8c539ddb566a4f3b4018da488fc3a0b534
// -----------------------------------------------------------------------------
void ClassicMovie::display() const 
{
	cout << left << setw(22) << title << " "
		<< setw(18) << director << " "
		<< setw(3) << month << " "
		<< setw(5) << year << " "
		<< actorFirst << " " << actorLast << endl;
}

<<<<<<< HEAD
// --------------------- displayHeader() -------------------------------------------
// Helper function to display the column headers for movies
=======
// --------------------- Display Header -------------------------------------------
// displayHeader: Display title / header for each classic
>>>>>>> ae0cff8c539ddb566a4f3b4018da488fc3a0b534
// Preconditions: none
// Postconditions: An output displaying at the top of the classic movie section
// -----------------------------------------------------------------------------
void ClassicMovie::displayHeader() const
{
	cout << "IN/OUT *TITLE*                *DIRECTOR*         *MO**YEAR* " <<
		"*ACTOR* " << endl;
	cout <<
		"---------------------------------------------------------------------"
		<< endl;
}

<<<<<<< HEAD
// --------------------- operator== -------------------------------------------
// Comparison operator to compare movies
// Preconditions: inventory built
// Postconditions: boolean result of equal (true) or not (false)
=======
// --------------------- Operator== -------------------------------------------
// operator==: check to see if current classic movie is equivalent to the one 
//			   in the inventory
// Preconditions: Inventory object
// Postconditions: Boolean for equivalence check of classic movie
>>>>>>> ae0cff8c539ddb566a4f3b4018da488fc3a0b534
// -----------------------------------------------------------------------------
bool ClassicMovie::operator==(const Inventory& inv) const 
{

	const ClassicMovie& aClassic = static_cast<const ClassicMovie&>(inv); // Cast inventory as classic movie

	return (year == aClassic.year && month == aClassic.month
		&& actorFirst == aClassic.actorFirst &&
		actorLast == aClassic.actorLast);
}

<<<<<<< HEAD
// --------------------- operator< -------------------------------------------
// Comparison operator to determine sorting
// Preconditions: inventory built
// Postconditions: boolean result of less than (true) or greater than (false)
=======
// --------------------- Operator< -------------------------------------------
// Operator<: This method is used to organize the movie by year and actor
// Preconditions: Inventory object 
// Postconditions: Boolean saying if current classic is older or newer than 
//					the one passed through
>>>>>>> ae0cff8c539ddb566a4f3b4018da488fc3a0b534
// -----------------------------------------------------------------------------
bool ClassicMovie::operator<(const Inventory& inv) const
{
	const ClassicMovie& aClassic = static_cast<const ClassicMovie&>(inv); // Cast inventory as classic movie


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

<<<<<<< HEAD
// --------------------- create() -------------------------------------------
// Create a classic movie object
// Preconditions: none
// Postconditions: classic movie object created
=======
// --------------------- Create -------------------------------------------
// create: Return instance of classic movie
// Preconditions: none
// Postconditions: Instance of ClassicMovie
>>>>>>> ae0cff8c539ddb566a4f3b4018da488fc3a0b534
// -----------------------------------------------------------------------------
Inventory * ClassicMovie::create() 
{
	return new ClassicMovie(); // Return new instance of classic movie
}