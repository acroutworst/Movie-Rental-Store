// ------------------------------------------------ inventory.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Inventory - This class will handle transactions by customers and contains the hash function to store movie library
// --------------------------------------------------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Inventory
{
public:
    
    Inventory (); 		      // Default constructor
    ~Inventory (); 		      // Default destructor
    void buildHash(string movieArray[]); // Build hash of movies
    void borrow(int movieID, int custID); // Change stock by intaking movie and customer
    void returnMovie(int movieID, int custID); // Return contents of movie
    void addStock(int movieID);       // Add stock by movie info
    //Movie accessor;	      // Access a movie
    //Customer accessor; 	      // Access a customer
    //void buildComedy();	      // Build comedy hash
    //void buildDrama(); 	     // Build drama hash
    //void buildClassic();          // build classic hash
    
private:
    
    vector<int> movieLibrary; //movie hash table
};