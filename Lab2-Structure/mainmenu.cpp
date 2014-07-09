// ********************************************************
// Starting Out with C++                                  *
// From Control Stuctures through Objects                 *
// seventh edition                                        *
//                                                        *
// Chapter 11 Structured Data                             *
//                                                        *
// Serendipity Booksellers Software Development           *
// Project — Part 11: A Problem-Solving Exercise          *
//                                                        *
// Multi-File Program                                     *
// ********************************************************
#include <iostream>
#include <iomanip>
#include "mainmenu.h"
#include "bookdata.h"
using namespace std;

const int	 NUM_BOOKS	 = 20;			// the maximum number of books
BookData book[NUM_BOOKS];				// the array of 'BookData' stuctures

int main()
{
	int choice = 0; // stores user's choice

	// display the 'Main Menu' until item 4 is selected
	while (choice != 4)
	{
		// display company name and screen title
		cout << "\n\nSerendipity Booksellers\n";
		cout << "Main Menu\n\n";

		// display menu items
		cout << "\n1.Cashier Module\n";
		cout << "2.Inventory Database Module\n";
		cout << "3.Report Module\n";
		cout << "4.Exit\n\n";

		// display user prompt
		cout << "Enter Your Choice: ";
		cin >> choice;

		// validate the user's input
		while (choice < 1 || choice > 4)
		{
			cout << "\nPlease enter a number in the range 1 - 4.\n\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
		}

		// call the selected function
		switch (choice)
		{ 
			case 1:
				cashier();
					break;

			case 2:
				invMenu();
					break;

			case 3:
				reports();
					break;

			case 4:
				cout << "\nGoodbye\n\n\n";
				exit(0);
					break;

		}	// end switch

	}	// end the 'Main Menu' while loop

	cout << endl << endl;

	return 0;
}

	
