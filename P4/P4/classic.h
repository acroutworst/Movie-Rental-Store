#include <iostream>
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

