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

// --------------------- Set Data -------------------------------------------
// setData: Set inventory data
// Preconditions: An input stream from movie file
// Postconditions: A string of actor first/last names
//				   and release month and year
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

// --------------------- Set Data -------------------------------------------
// setDataTwice: Set additional inventory data
// Preconditions: Input file stream
// Postconditions: string wit month, year, first, and last name
// -----------------------------------------------------------------------------
void ClassicMovie::setDataTwice(istream& infile) 
{
	infile >> month;
	infile >> year;
	infile >> actorFirst;
	infile >> actorLast;

}

// --------------------- Display -------------------------------------------
// Display: display classic movie data 
// Preconditions: none
// Postconditions: String of classic data from title to actor last name
// -----------------------------------------------------------------------------
void ClassicMovie::display() const 
{
	cout << left << setw(22) << title << " "
		<< setw(18) << director << " "
		<< setw(3) << month << " "
		<< setw(5) << year << " "
		<< actorFirst << " " << actorLast << endl;
}

// --------------------- Display Header -------------------------------------------
// displayHeader: Display title / header for each classic
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

// --------------------- Operator== -------------------------------------------
// operator==: check to see if current classic movie is equivalent to the one 
//			   in the inventory
// Preconditions: Inventory object
// Postconditions: Boolean for equivalence check of classic movie
// -----------------------------------------------------------------------------
bool ClassicMovie::operator==(const Inventory& inv) const 
{

	const ClassicMovie& aClassic = static_cast<const ClassicMovie&>(inv); // Cast inventory as classic movie

	return (year == aClassic.year && month == aClassic.month
		&& actorFirst == aClassic.actorFirst &&
		actorLast == aClassic.actorLast);
}

// --------------------- Operator< -------------------------------------------
// Operator<: This method is used to organize the movie by year and actor
// Preconditions: Inventory object 
// Postconditions: Boolean saying if current classic is older or newer than 
//					the one passed through
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

// --------------------- Create -------------------------------------------
// create: Return instance of classic movie
// Preconditions: none
// Postconditions: Instance of ClassicMovie
// -----------------------------------------------------------------------------
Inventory * ClassicMovie::create() 
{
	return new ClassicMovie(); // Return new instance of classic movie
}