// ********************************************************
// Starting Out with C++                                  *
// From Control Stuctures through Objects                 *
// seventh edition                                        *
//                                                        *
// Chapter 8 Searching and Sorting Arrays                 *
//                                                        *
// Serendipity Booksellers Software Development           *
// Project — Part 8: A Problem-Solving Exercise           *
//                                                        *
// Multi-File Program                                     *
// ********************************************************
#include "reports.h"
#include <iostream>
using namespace std;

void reports()
{
	int choice = 0;	// To hold the user's choice

	// Display the menu until the user selects item 7
	while (choice != 7)
	{
		cout << "Serendipity Booksellers\n";
		cout << "\tReports\n\n";

		cout << "1.Inventory Listing\n";
		cout << "2.Inventory Wholesale Value\n";
		cout << "3.Inventory Retail Value\n";
		cout << "4.Listing by Quantity\n";
		cout << "5.Listing by Cost\n";
		cout << "6.Listing by Age\n";
		cout << "7.Return to the Main Menu\n\n";

		// Get the choice as input from the user
		cout << "Enter Your Choice: ";
		cin >> choice;

		// Validate the user's input
		while (choice < 1 || choice > 7)
		{
			cout << "\nPlease enter a number in the range 1 - 7.\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
		}

		// Display a selection message
		{
			switch (choice)
			{ 
				case 1: 
					repListing();
					break;
				case 2: 
					repWholesale();
					break;
				case 3: 
					repRetail();
					break;
				case 4: 
					repQty();
					break;
				case 5: 
					repCost();
					break;
				case 6: 
					repAge();
					break;
				case 7: 
					cout << "\nYou selected item 7.\n";
					break;
			}
		}

		cout << endl << endl;
	}
}

// ********************************************************
// repListing stub function                               *
// ********************************************************
void repListing()
{
	cout << "\nYou selected Inventory Listing.\n";
}

// ********************************************************
// repWholesale stub function                             *
// ********************************************************
void repWholesale()
{
	cout << "\nYou selected Inventory Wholesale Value.\n";
}

// ********************************************************
// repRetail stub function                                *
// ********************************************************
void repRetail()
{
	cout <<"\nYou selected Inventory Retail Value.\n";
}

// ********************************************************
// repQty stub function                                   *
// ********************************************************
void repQty()
{
	cout << "\nYou selected Listing By Quantity.\n";
}

// ********************************************************
// repCost stub function                                  *
// ********************************************************
void repCost()
{
	cout << "\nYou selected Listing By Cost.\n";
}

// ********************************************************
// repAge stub function                                   *
// ********************************************************
void repAge()
{
	cout << "\nYou selected Listing By Age.\n";
}