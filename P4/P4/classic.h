// ------------------------------------------------ classic.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Classic - This class extends the movie class and adds functionality of major actor and release date. 
// Classic is denoted as 'C'.
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Classic //: public Movie 
{
public:
	Classic(); //default constructor
	~Classic(); //deconstructor

	// Need a struct for Actor?
	void changeUniqueStock(string *name); // Change stock of specific movie

private:
	struct classicMovie
	{
		//string Actor first; //actor’s first name
		//string Actor last; //actor’s last name
		//int Release month; //release month of movie
		int uniqueStock;  // tracks stock for movies w/ same name, different actors
	};
	vector<classicMovie> uniqueClassics; //track multiples of movie with different 
										  //main actors

};

