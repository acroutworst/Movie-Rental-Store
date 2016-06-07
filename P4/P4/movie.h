// ------------------------------------------------ movie.h -----------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Movie - This class is used as a base class to derive comedy, drama, and classic movies. 
// The inventory keeps track of the types of movies and its inventory>
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>

using namespace std;

class Movie
{
public:
	Movie(); //default constructor
	~Movie(); //deconstructor

	bool isMovie(int *movieID); //check if valid movie

private:
	struct movie
	{
		char Type; //Movie genre type
		int Stock; //Current stock
		string Director; //name of director
		string Title; //Title of movie
		int releaseYear; //year of release
	};

	void changeStock(int *movieID, int *newStock); //modify stock

};

