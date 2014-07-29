// ********************************************************
// Starting Out with C++                                  *
// From Control Stuctures through Objects                 *
// seventh edition                                        *
//                                                        *
// Chapter 14 More About Classes                          *
//                                                        *
// Serendipity Booksellers Software Development           *
// Project — Part 14: A Problem-Solving Exercise          *
//                                                        *
// Multi-File Program                                     *
// ********************************************************

// Implementation file for the 'Menu' Class
#include "menu.h"
#include <iostream>
#include <iomanip>
using namespace std;

//****************************************************************
// The Default Constructor.                                      *
// Sets the private member variable 'choice' to an empty         *
// c-string.                                                     *
//****************************************************************
Menu::Menu()
{
	strcpy(choice, "\0");
}

//****************************************************************
// The mainMenu Member Function.                                 *
// Displays the 'Main Menu' of the Serendipity Booksellers       *
// Program.                                                      *
//****************************************************************
void Menu::mainMenu()
{
	// display company name and screen title
	cout << "\n\nSerendipity Booksellers\n";
	cout << "Main Menu\n\n";

	// display menu items
	cout << "\n1.Cashier Module\n";
	cout << "2.Inventory Database Module\n";
	cout << "3.Report Module\n";
	cout << "4.Exit\n\n";
}

//****************************************************************
// The invMenu Member Function.                                  *
// Displays the 'Inventory Database Menu' of the Serendipity     *
// Booksellers Program.                                          *
//****************************************************************
void Menu::invMenu()
{
	// display company name and screen title
	cout << "\n\n\tSerendipity Booksellers\n";
	cout << "\tInventory Database\n\n";

	// display menu items
	cout << "\t\t1.Look Up a Book\n";
	cout << "\t\t2.Add a Book\n";
	cout << "\t\t3.Edit a Book's Record\n";
	cout << "\t\t4.Delete a Book\n";
	cout << "\t\t5.Return to the Main Menu\n\n";
}

//****************************************************************
// The reports Member Function.                                  *
// Displays the 'Reports Module Menu' of the Serendipity         *
// Booksellers Program.                                          *
//****************************************************************
void Menu::reports()
{
		// display company name and screen title
		cout << "\n\n\t\t\tSerendipity Booksellers\n";
		cout << "\t\t\t\tReports\n\n";

		// display information items
		cout << "\t\t1.Inventory Listing\n";
		cout << "\t\t2.Inventory Wholesale Value\n";
		cout << "\t\t3.Inventory Retail Value\n";
		cout << "\t\t4.Listing by Quantity\n";
		cout << "\t\t5.Listing by Cost\n";
		cout << "\t\t6.Listing by Age\n";
		cout << "\t\t7.Return to the Main Menu\n\n";
}

//****************************************************************
// The itemListPrompt Member Function.                           *
// for use with list choices.                                    *
// sets the value of the privatemember variable 'choice'.		 *                                     *
//****************************************************************
char* Menu::itemListPrompt()
{
	cout << "Enter your choice: ";
	cin >> choice;

	return choice;
}

//****************************************************************
// The simplePrompt Member Function.                             *
// for use with simple Y or N prompts.                           *
// sets the value of the private member variable 'choice'.       *
//****************************************************************
char* Menu::simplePrompt()
{
	cin >> choice;

	return choice;
}