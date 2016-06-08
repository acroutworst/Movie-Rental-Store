// ------------------------------------------------ hash.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Hash - This class will hash the inventory, create list of movies, create transaction, and process transaction.
// --------------------------------------------------------------------------------------------------------------------

#ifndef HASH_H_
#define HASH_H_
// Static definitions
#define MAXITEMS 26
#define CLASSIC 2
#define DRAMA 3
#define COMEDY 5
#define BORROW 1
#define HISTORY 7 
#define RETURN 17

#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include "transaction.h"
#include "borrow.h"
#include "returnMovie.h"
#include "history.h"
#include <string>

// Class instances
class Movie;
class Transaction;

using namespace std;

class Hash 
{
public:
	Hash();												// Constructor
	~Hash();											// Destructor

	int convertToSubscript(char);
	string getMediaType(char);							// Return media type

	// Main functions
	Inventory * createMovie(char, istream&);			// Create movie from input file
	Transaction * createTransaction(char, istream&);	// Create transaction from input file 


private:
	Inventory * storeInventory[MAXITEMS];				// Store inventory
	Transaction * transactionInventory[MAXITEMS];		// Transaction inventory
	string mediaType[MAXITEMS];							// Store media type

	int hash(char) const;								// Hash function
	void initInventory();								// Initialize inventory
};

#endif