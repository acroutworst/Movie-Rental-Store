// ------------------------------------------------ main.cpp ---------------------------------------------------------
// Adam Croutworst, Shane Gardner CSS343A
// 06/03/16
// 06/08/16
// --------------------------------------------------------------------------------------------------------------------
// Main - This program is intended to initialize the contents of the inventory from a
// file(data4movies.txt), the customer list from another file(data4customers.txt), and then
// process an arbitrary sequence of commands from a third file(data4commands.txt).
// --------------------------------------------------------------------------------------------------------------------

#include "classic.h"
#include "movie.h"
#include "customer.h"
#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {

	ifstream infile1("data4movies.txt");
	ifstream infile2("data4customers.txt");
	ifstream infile3("data4commands.txt");

	if (!infile1 || !infile2 || !infile3)
	{
		cout << "File could not be opened" << endl;
		return 1;
	}

	return 0;
}
