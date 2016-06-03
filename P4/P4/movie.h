#include <iostream>
using namespace std;

class Movie
{
public:
	Movie(); //default constructor
	~Movie(); //deconstructor

	void isMovie(int *movieID); //check if valid movie

private:
	struct movie
	{
		char Type; //Movie genre type
		int Stock; //Current stock
		string Director; //name of director
		string Title; //Title of movie
		int releaseYear; //year of release
	};

	bool changeStock(int *newStock); //modify stock

};

