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
#include "cashier.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void cashier()
{
	// Constants
	const double SALES_TAX	= 0.06;	// The sales tax

	// Variables
	string date;		// To hold the date
	int quantity;		// To hold the quantity
	string isbn;		// To hold the ISBN number
	string title;		// To hold the title
	double price;		// To hold the price
	double subtotal;	// To hold the subtotal
	double tax;			// To hold the tax
	double total;		// To hold the total
	char again;			// To hold Y or N input
	
	// Repeat as long as the user wants to process 
	// another transaction
	do
	{
		cout << "Serendipity Booksellers\n";
		cout << " Cashier Module\n\n";

		cin.ignore();	// Skip the newline character

		// Get the date
		cout << "Date: ";
		getline(cin, date);

		// Get the quantity 
		cout << "Quantity of Book: ";
		cin >> quantity;

		cin.ignore();	// Skip the newline character

		// Get the ISBN number
		cout << "ISBN: ";
		getline(cin, isbn);

		// Get the title
		cout << "Title: ";
		getline(cin, title);

		// Get the price
		cout << "Price: ";
		cin >> price;

		// Perform the calculations
		subtotal = quantity * price;	// Calculate the subtotal
		tax = subtotal * SALES_TAX;		// Calculate the tax
		total = subtotal + tax;			// Calculate the total

		cout << "\n\nSerendipity Book Sellers\n\n";

		// Display the date
		cout << "Date: " << date << "\n\n";

		cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal\n";
		cout << "_________________________________________";
		cout << "_________________________________________";
		cout << "\n\n\n";

		// Display the quantity
		cout << quantity << "\t";

		// Display the ISBN number
		cout << left << setw(14) << isbn << "\t";

		// Display the title
		cout << left << setw(26) << title << "\t$ ";

		// Set up the formatting for dollar amounts
		cout << fixed << showpoint << right << setprecision(2);

		// Display the price
		cout << setw(6) << price << "\t$ ";

		// Display the subtotal
		cout << setw(6) << subtotal;
		cout << "\n\n\n";

		// Display the calculated totals
		cout << "\t\tSubtotal\t\t\t\t\t\t$ ";
		cout << setw(6) << subtotal << "\n";

		cout << "\t\tTax\t\t\t\t\t\t\t$ ";
		cout << setw(6) << tax << "\n";

		cout << "\t\tTotal\t\t\t\t\t\t\t$ ";
		cout << setw(6) << total << "\n\n";

		cout << "\n\nThank You for Shopping at Serendipity!\n";

		// Does the user want to process another transaction?
		cout << "Process another transaction? (Y/N) ";
		cin >> again;

		cout << endl << endl;

	} while (again == 'Y' || again == 'y');
}