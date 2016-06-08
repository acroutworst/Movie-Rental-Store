// ------------------------------------------------ hash.h ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Hash - This class will hash the inventory, create list of movies, create transaction, and process transaction.
// --------------------------------------------------------------------------------------------------------------------

#include "hash.h"

// --------------------- Hash() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: Initializes inventory, set instances of classic, drama, comedy, borrow, history, and return movie
// -----------------------------------------------------------------------------
Hash::Hash() 
{
	initInventory();								// Initialize inventory
	storeInventory[CLASSIC] = new ClassicMovie();	// Set movie instances
	storeInventory[DRAMA] = new DramaMovie();
	storeInventory[COMEDY] = new ComedyMovie();

	transactionInventory[BORROW] = new Borrow();	// Set transaction instances
	transactionInventory[HISTORY] = new History();
	transactionInventory[RETURN] = new ReturnMovie();

	mediaType[DRAMA] = "DVD";						// Drama and DVD both service as 3
}

// --------------------- Hash() -------------------------------------------
// Destructor
// Preconditions: Store inventory
// Postconditions: Empty the inventory
// -----------------------------------------------------------------------------
Hash::~Hash() 
{
	for (int i = 0; i < MAXITEMS; i++)				// While less than max,
	{	
		if (storeInventory[i] != NULL)				// and item is not null,
		{
			delete storeInventory[i];				// delete item and set to null.
			storeInventory[i] = NULL;
		}

		if (transactionInventory[i] != NULL)		// If trans item is not null,
		{	
			delete transactionInventory[i];			// also delete and set to null.
			transactionInventory[i] = NULL;
		}
	}
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
int Hash::convertToSubscript(char ch)
{
	return hash(ch);		// Return subscript from helper function
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
int Hash::hash(char ch) const 
{
	if (ch < 'a')			// Change character to int value based on uppercase  
		return ch - 'A';
	else
		return 0;
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
string Hash::getMediaType(char ch)
{
	return mediaType[hash(ch)];		// Return media type
}

// --------------------- Inventory() -------------------------------------------
// Create movie in inventory
// Preconditions: valid input movie file and character
// Postconditions: Inventory item
// -----------------------------------------------------------------------------
Inventory * Hash::createMovie(char ch, istream& infile) 
{
	string temp;							// temp string

	int subscript = hash(ch);				// Return character type 

	if (storeInventory[subscript] == NULL)	// Remove invalid character type
	{
		getline(infile, temp, '\n');
		return NULL;
	} else {
		return storeInventory[subscript]->create();	// Create inventory item based on subscript
	}
}

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
Transaction * Hash::createTransaction(char ch, istream& infile) 
{
	string temp;									// temp string 		

	int subscript = hash(ch);						// Return character type
	if (transactionInventory[subscript] == NULL)	// Remove invalid character type
	{
		getline(infile, temp, '\n');
		return NULL;
	}
	else
		return transactionInventory[subscript]->create(); // Create transaction item based on subscript
}	

// --------------------- Inventory() -------------------------------------------
// Default constructor
// Preconditions: none
// Postconditions: none
// -----------------------------------------------------------------------------
void Hash::initInventory() 
{
	for (int i = 0; i < MAXITEMS; i++)		// While less than max,
	{
		storeInventory[i] = NULL;			// initialize store and transaction inventory,
		transactionInventory[i] = NULL;
		mediaType[i] = "";					// and set media type to empty string.
	}
}