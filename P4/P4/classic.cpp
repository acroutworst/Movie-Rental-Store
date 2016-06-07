// ------------------------------------------------ classic.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Classic - This class extends the movie class and adds functionality of major actor and release date. 
// Classic is denoted as 'C'.
// --------------------------------------------------------------------------------------------------------------------

#include "classic.h"


ClassicMovie::ClassicMovie() 
	: Movie(), actorFName(""), actorLName(""), month(0), GENRE("CLASSIC") 
{
}

ClassicMovie::ClassicMovie(const ClassicMovie& classic) 
{
	director = classic.director;
	title = classic.title;
	actorFName = classic.actorFName;
	actorLName = classic.actorLName;
	month = classic.month;
	year = classic.year;
}

 
ClassicMovie::~ClassicMovie()
{
}

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
	infile >> actorFName >> actorLName;
	infile >> month >> year;
}

void ClassicMovie::setDataTwice(istream& infile) 
{
	infile >> month;
	infile >> year;
	infile >> actorFName;
	infile >> actorLName;

}

void ClassicMovie::display() const 
{
	cout << left << setw(22) << title << " "
		<< setw(18) << director << " "
		<< setw(3) << month << " "
		<< setw(5) << year << " "
		<< actorFName << " " << actorLName << endl;
}

void ClassicMovie::displayHeader() const
{
	cout << "IN/OUT *TITLE*                *DIRECTOR*         *MO**YEAR* " <<
		"*ACTOR* " << endl;
	cout <<
		"---------------------------------------------------------------------"
		<< endl;
}

bool ClassicMovie::operator==(const Inventory& inv) const 
{

	const ClassicMovie& aClassic = static_cast<const ClassicMovie&>(inv);

	return (year == aClassic.year && month == aClassic.month
		&& actorFName == aClassic.actorFName &&
		actorLName == aClassic.actorLName);
}

bool ClassicMovie::operator<(const Inventory& inv) const
{
	const ClassicMovie& aClassic = static_cast<const ClassicMovie&>
		(inv);

	if (year < aClassic.year)
		return true;
	else if (year == aClassic.year)
	{
		if (actorFName < aClassic.actorFName)
		{
			return true;
		}
		else if (actorFName == aClassic.actorFName)
		{
			return (actorLName < aClassic.actorLName);
		}
		else
			return false;
	}
	else
		return false;
}

Inventory * ClassicMovie::create() 
{
	return new ClassicMovie();
}