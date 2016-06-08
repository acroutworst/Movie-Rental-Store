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

// --------------------- Convert to Subscript -------------------------------------------
// Function to handle uppercase letters by changing them to lowercase
// Preconditions: char to analyze
// Postconditions: modified char or nothing
// -----------------------------------------------------------------------------
int Hash::convertToSubscript(char ch)
{
	return hash(ch);		// Return subscript from helper function
}

// --------------------- Hash -------------------------------------------
// Helper function to handle uppercase letters by changing them to lowercase
// Preconditions: char to analyze and possibly modify
// Postconditions: modified char to lowercase if necessary, otherwise nothing
// -----------------------------------------------------------------------------
int Hash::hash(char ch) const 
{
	if (ch < 'a')			// Change character to int value based on uppercase  
		return ch - 'A';
	else
		return 0;
}

// --------------------- Get Media Type -------------------------------------------
// Locate type of media
// Preconditions: char distinguishing type of media
// Postconditions: type of media returned
// -----------------------------------------------------------------------------
string Hash::getMediaType(char ch)
{
	return mediaType[hash(ch)];		// Return media type
}

// --------------------- Create Movie() -------------------------------------------
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

// --------------------- Create Transaction() -------------------------------------------
// Create transaction item
// Preconditions: valid file and char value
// Postconditions: transaction generated
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

// --------------------- Init Inventory -------------------------------------------
// Initialize inventory, set all parts of Inventory to NULL in the beginning
// Preconditions: none
// Postconditions: Inventory to work with
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