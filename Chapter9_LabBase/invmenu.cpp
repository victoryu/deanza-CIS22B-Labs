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
#include "invmenu.h"
#include "bookinfo.h"
#include <iostream>
using namespace std;

const int SIZE	 = 20;	

// The following are external declarations for the various
// arrays used by the program.
extern string bookTitle[SIZE];	
extern string isbn[SIZE];
extern string author[SIZE];
extern string publisher[SIZE];
extern string dateAdded[SIZE];
extern int qtyOnHand[SIZE];
extern double wholesale[SIZE];
extern double retail[SIZE];	

void invMenu()
{
	int choice = 0;	// To hold the user's choice

	// Display the menu until the user selects item 5
	while (choice != 5)
	{
		cout << "Serendipity Booksellers\n";
		cout << "  Inventory Database\n\n";

		cout << "1.Look Up a Book\n";
		cout << "2.Add a Book\n";
		cout << "3.Edit a Book's Record\n";
		cout << "4.Delete a Book\n";
		cout << "5.Return to the Main Menu\n\n";

		// Get the choice as input from the user
		cout << "Enter Your Choice: ";
		cin >> choice;

		// Validate the user's input
		while (choice < 1 || choice > 5)
		{
			cout << "\nPlease enter a number in the range 1 - 5.\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
		}

		// Display a selection message
		{
			switch (choice)
			{ 
				case 1: 
					lookUpBook();
					break;
				case 2: 
					addBook();
					break;
				case 3: 
					editBook();
					break;
				case 4: 
					deleteBook();
					break;
				case 5: 
					cout << "\nYou selected item 5.\n";
					break;
			}
		}

		cout << endl << endl;
	}
}

// ********************************************************
// lookUpbook function                                    *
// ********************************************************
void lookUpBook()
{
	bool found = false;
	int index = 0;
	string searchTitle;

	cin.ignore();

	cout << "Enter the title of the book to search for: ";
	getline(cin, searchTitle);

	// Search for a matching title.
	while (!found && index < SIZE)
	{
		if (bookTitle[index] == searchTitle)
			found = true;
		else
			index++;
	}

	if (found)
		bookInfo(isbn[index], bookTitle[index], author[index], 
		         publisher[index], dateAdded[index], 
				 qtyOnHand[index], wholesale[index], 
				 retail[index]);
	else
		cout << "The book you searched for is not in inventory.\n\n";
}

// ********************************************************
// addBook function                                       *
// ********************************************************
void addBook()
{
	bool found = false;
	int index = 0;

	// Search for an empty element
	while (!found && index < SIZE)
	{
		if (bookTitle[index] == "")
			found = true;
		else
			index++;
	}

	// An empty element was found in the array
	if (found)
	{
		// Prompt user for book information
		cin.ignore();
		cout << "\nEnter Title: ";
		getline(cin, bookTitle[index]);
			
		cout << "\nEnter ISBN(#-###-#####-#): ";
		getline(cin, isbn[index]);
			
		cout << "\nEnter Author: ";
		getline(cin, author[index]);

		cout << "\nEnter Publisher: ";
		getline(cin, publisher[index]);
			
		cout << "\nEnter Date Added to Inventory (MM/DD/YYYY): ";
		getline(cin, dateAdded[index]);

		cout << "\nEnter Quantity Being Added: ";
		cin >> (qtyOnHand[index]);

		cout << "\nEnter Wholesale Cost: ";
		cin >> (wholesale[index]);

		cout << "\nEnter Retail Price: ";
		cin >> (retail[index]);

		cout << "\n\nRecord was successfully entered.\n";
	}
	else
		cout << "No more books may be added to inventory.\n\n";
}

// ********************************************************
// editBook function                                      *
// ********************************************************
void editBook()
{
	int  choice = 0;	// To hold the user's choice
	bool found = false;	// The book title found flag
	int index = 0;		// The book title array index
	string searchTitle;	// To hold the book search title

	cin.ignore();	// Skip the newline character

	// Get the book title to search for from the user
	cout << "Enter the title of the book to edit: ";
	getline(cin, searchTitle);

	// Search for a matching book title
	while (!found && index < SIZE)
	{	
		if (bookTitle[index] == searchTitle)
			found = true;
		else
			index++;
	}

	// The book was found
	if (found)
	{
		// Display the results
		bookInfo(isbn[index], bookTitle[index], 
				 author[index], publisher[index],
				 dateAdded[index], qtyOnHand[index], 
				 wholesale[index], retail[index]);

		// Ask the user which fields to change, repeat until exit
		do 
		{
			cout << "\nYou may edit any of the following fields:\n";
			cout << "1. ISBN\n"; 
			cout << "2. Title\n";
			cout << "3. Author's Name\n";
			cout << "4. Publisher's Name\n"; 
			cout << "5. Date Book Was Added To Inventory\n";
			cout << "6. Quantity On Hand\n";
			cout << "7. Wholesale Cost\n"; 
			cout << "8. Retail Price\n"; 
			cout << "9. Exit\n\n";
			cout << "Enter Your Choice: ";
			cin >> choice;

			// Validate the user's input
			while (choice < 1 || choice > 9)
			{
				cout << "\nPlease enter a number in the range 1 - 9.\n";
				cout << "Enter Your Choice: ";
				cin >> choice;
			}

			// Display the user's choice
			switch (choice)
			{
				case 1:
					cout << "\nCurrent ISBN:  ";
					cout << isbn[index] << endl;
					cin.ignore();
					cout << "Enter new ISBN(#-###-#####-#): ";
					cin >>  isbn[index];
					break;
				case 2:
					cout << "\nCurrent Title:  ";
					cout << bookTitle[index] << endl;
					cin.ignore();
					cout << "Enter new Title:  ";
					getline(cin, bookTitle[index]);
					break;
				case 3:
					cout << "\nCurrent Author:  ";
					cout << author[index] << endl;
					cin.ignore();
					cout << "Enter new Author:  ";
					getline(cin, author[index]);
					break;
				case 4:
					cout << "\nCurrent Publisher:  ";
					cout << publisher[index] << endl;
					cin.ignore();
					cout << "Enter new Publisher:  ";
					getline(cin, publisher[index]);
					break;
				case 5:
					cout << "\nCurrent Date Added:  ";
					cout << dateAdded[index] << endl;
					cin.ignore();
					cout << "Enter new Date(MM/DD/YYYY):  ";
					getline(cin, dateAdded[index]);
					break;
				case 6:
					cout << "\nCurrent Quantity on Hand:  ";
					cout << qtyOnHand[index] << endl;
					cin.ignore();
					cout << "Enter new Quantity on Hand:  ";
					cin >> qtyOnHand[index];
					break;
				case 7:
					cout << "\nCurrent Wholesale Cost:  ";
					cout << wholesale[index] << endl;
					cin.ignore();
					cout << "Enter new Wholesale Cost:  ";
					cin >> wholesale[index];
					break;
				case 8:
					cout << "\nCurrent Retail Price:  "; 
					cout << retail[index] << endl;
					cin.ignore();
					cout << "Enter new Retail Price:  ";
					cin >> retail[index];
					break;
			} 

		} while (choice != 9);
	}
	// The book was not found
	else
		cout << "The book you searched for is not in inventory.\n\n";
}

// ********************************************************
// deleteBook function                                    *
// ********************************************************
void deleteBook()
{
	bool found = false;
	int index = 0;
	string searchTitle;
	char confirm;

	cin.ignore();	// Skip the newline character

	// Get the book title as input from the user
	cout << "Enter the title of the book to delete: ";
	getline(cin, searchTitle);

	// Search for a matching title
	while (!found && index < SIZE)
	{
		if (bookTitle[index] == searchTitle)
			found = true;
		else
			index++;
	}

	// Display the book information
	if (found)
	{
		bookInfo(isbn[index], bookTitle[index], author[index], 
		         publisher[index], dateAdded[index], 
				 qtyOnHand[index], wholesale[index], 
				 retail[index]);

		// Confirm book deletion
		cout << "Are you sure you want to delete this book? (Y/N): ";
		cin >> confirm;

		// Delete the book
		if (confirm == 'Y' || confirm == 'y')
		{
			bookTitle[index] = "";
			isbn[index] = "";
			cout << "The book has been deleted.\n\n";
		}
	}
	// The book was not found
	else
		cout << "The book you searched for is not in inventory.\n\n";
}
