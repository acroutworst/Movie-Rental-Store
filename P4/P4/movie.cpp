// ------------------------------------------------ movie.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Movie - This class is used as a base class to derive comedy, drama, and classic movies. 
// The inventory keeps track of the types of movies and its inventory>
// --------------------------------------------------------------------------------------------------------------------

#include "movie.h"


Movie::Movie() : Inventory(), title(""), director(""), year(0) 
{
}

Movie::Movie(const Movie& movie) 
{
	title = movie.title;
	director = movie.director;
	year = movie.year;
}

Movie::~Movie()
{
}

void Movie::display() const
{
	cout << title << " " << director
		<< " "
		<< year
		<< endl;
}

void Movie::setData(istream& infile) 
{
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;
}

void Movie::displayHeader() const 
{
	cout << " ****** MOVIE ITEM ***** "
		<< endl;
}

string Movie::getItem() const 
{
	return title;
}

string Movie::getDirector()
{
	return director;
} 

string Movie::getTitle() {
	return title;
}

int Movie::getYear() {
	return year;
}
