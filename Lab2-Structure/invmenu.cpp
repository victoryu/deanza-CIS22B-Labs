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
#include "invmenu.h"
#include "strupper.h"
#include "bookdata.h"
using namespace std;

const int NUM_BOOKS	= 20;        // the number of books in inventory
extern BookData book[NUM_BOOKS]; // the array of 'BookData' stuctures

//********************************************
// lookUpbook function                       *
//********************************************

void lookUpBook()
{
	char title[STR_SIZE];	// stores a book title the user enters
	int  choice = 0;		// stores the user's numeric choice
	int row;                // Used in a loop to step through the array

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase
	
	// enter the 'book title search' for loop
	for (row = 0; row < NUM_BOOKS; row++)
	{
		// search for a match 
		if (strstr(book[row].bookTitle, title)) // if they match
		{  
			// display a possible match
			cout << "\nPossible Match Found:  " 
				 << book[row].bookTitle 
			     << "\n\n";

			// prompt the user for confirmation
			cout << "Is this a Correct Match?\n";
			cout << "1.Yes\n";
			cout << "2.No\n\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
			
			// validate the user's input
			while (choice != 1 && choice != 2)
			{
				cout << "Please enter a number in the range 1 - 2\n\n";

				cout << "Is this a Correct Match?\n";
				cout << "1.Yes\n";
				cout << "2.No\n\n";

				cout << "Enter Your Choice: ";
				cin >> choice;
			}

			if (choice == 1)
			{  
				// call function 'bookInfo' to display the results
				bookInfo(book[row].isbn, book[row].bookTitle, 
					     book[row].author, book[row].publisher,
						 book[row].dateAdded, book[row].qtyOnHand, 
						 book[row].wholesale, book[row].retail);
				break;
			}
			else 
			{
				continue;
			}

		}	// end if

	}	// end the 'book title search' for loop

	if (row == NUM_BOOKS - 1)
	{
		cout << "\nSorry.  No title matching \'" 
			 << title 
			 << "\' was found."  
			 << "\n\n";
	}

}	// end function lookUpBook

//********************************************
// addBook function                          *
//********************************************

void addBook()
{
	char   title    [STR_SIZE];	// stores a book title the user enters
	char   isbn     [STR_SIZE];	// stores an ISBN the user enters
	char   author   [STR_SIZE];	// stores an author the user enters
	char   publisher[STR_SIZE];	// stores a publisher the user enters
	char   date     [STR_SIZE];	// stores a date the user enters

	int    quantity;			// stores a book quantity the user enters
	double wholesale;			// stores a wholesale cost the user enters
	double retail;				// stores a retail price the user enters
	int row;                    // Used in a loop to step through the array

	for (row = 0; row < NUM_BOOKS; row++)
	{
		// find the first book whose element is 0.
		if (isEmpty(row))
		{
				cin.ignore();

			cout << "\nEnter Title: ";
			cin.getline(title,STR_SIZE);

			setTitle(title,row);
			
			cout << "\nEnter ISBN(#-###-#####-#): ";
			cin.getline(isbn,STR_SIZE);

			setISBN(isbn,row);
			
			cout << "\nEnter Author: ";
			cin.getline(author,STR_SIZE);

			setAuthor(author,row);

			cout << "\nEnter Publisher: ";
			cin.getline(publisher,STR_SIZE);

			setPub(publisher,row);
			
			cout << "\nEnter Date Added to Inventory (MM/DD/YYYY): ";
			cin.getline(date, STR_SIZE);

			setDateAdded(date,row);

			cout << "\nEnter Quantity Being Added: ";
			cin >> quantity;

			setQty(quantity,row);

			cout << "\nEnter Wholesale Cost: ";
			cin >> wholesale;

			setWholesale(wholesale,row);

			cout << "\nEnter Retail Price: ";
			cin >> retail;

			setRetail(retail,row);

			cout << "\n\nRecord was successfully entered.\n";

				break;
		}

		else if (row == NUM_BOOKS - 1)
		{
			cout << "\n\t\t****Sorry. Database is full.****\n\n";
		}

	}	// end the 'first empty row' for loop

}	// end function addBook

//********************************************
// editBook function                         *
//********************************************

void editBook()
{
	char   title    [STR_SIZE];	// stores a book title the user enters
	char   isbn     [STR_SIZE];	// stores an ISBN the user enters
	char   author   [STR_SIZE];	// stores an author the user enters
	char   publisher[STR_SIZE];	// stores a publisher the user enters
	char   date     [STR_SIZE];	// stores a date the user enters

	int    quantity;			// stores a book quantity the user enters
	double wholesale;			// stores a wholesale cost the user enters
	double retail;				// stores a retail price the user enters

	int  choice = 0;			// stores the user's numeric choice

	int row;                // Used in a loop to step through the array

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase
	
	// enter the 'book title search' for loop
	for (row = 0; row < NUM_BOOKS; row++)
	{
		// search for a match
		if (strstr(book[row].bookTitle, title)) // if they match
		{  
			// display a possible match
			cout << "\nPossible Match Found:  " 
				 << book[row].bookTitle
			     << "\n\n";

			// prompt the user for confirmation
			cout << "Is this a Correct Match?\n";
			cout << "1.Yes\n";
			cout << "2.No\n\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
			
			// validate the user's input
			while (choice != 1 && choice != 2)
			{
				cout << "Please enter a number in the range 1 - 2\n\n";

				cout << "Is this a Correct Match?\n";
				cout << "1.Yes\n";
				cout << "2.No\n\n";

				cout << "Enter Your Choice: ";
				cin >> choice;
			}

			if (choice == 1)
			{  
				// call function 'bookInfo' to display the results
				bookInfo(book[row].isbn, book[row].bookTitle, 
					     book[row].author, book[row].publisher,
						 book[row].dateAdded, book[row].qtyOnHand, 
						 book[row].wholesale, book[row].retail);
			do 
			{
				cout << "\nYou may edit any of the following fields:\n";
				cout << "\t1.  ISBN\n"; 
				cout << "\t2.  Title\n";
				cout << "\t3.  Author's Name\n";
				cout << "\t4.  Publisher's Name\n"; 
				cout << "\t5.  Date Book Was Added To Inventory\n";
				cout << "\t6.  Quantity On Hand\n";
				cout << "\t7.  Wholesale Cost\n"; 
				cout << "\t8.  Retail Price\n"; 
				cout << "\t9.  Exit\n\n";
				cout << "Please choose 1 - 8 to EDIT an item, or 9 to EXIT:  ";
				cin >> choice;

				// validate the user's input
				while (choice < 1 || choice > 9)
				{
					cout << "\nPlease choose 1 - 8 to EDIT an item, or 9 to CANCEL:  ";
					cin >> choice;
				}

				// diplay the selected item
				switch (choice)
				{

				case 1:
					cout << "\nCurrent ISBN:  " 
						 << book[row].isbn 
						 << endl;

						cin.ignore();

					cout << "Enter new ISBN(#-###-#####-#): ";
					cin >> isbn;
					
					setISBN(isbn,row);

						break;

				case 2:
					cout << "\nCurrent Title:  " 
						 << book[row].bookTitle 
						 << endl;

						cin.ignore();

					cout << "Enter new Title:  ";
					cin.getline(title, STR_SIZE);

					setTitle(title,row);

						break;

				case 3:
					cout << "\nCurrent Author:  " 
						 << book[row].author 
						 << endl;

						cin.ignore();

					cout << "Enter new Author:  ";
					cin.getline(author , STR_SIZE);

					setAuthor(author,row);

						break;

				case 4:
					cout << "\nCurrent Publisher:  " 
						 << book[row].publisher 
						 << endl;

						cin.ignore();

					cout << "Enter new Publisher:  ";
					cin.getline(publisher , STR_SIZE);

					setPub(publisher,row);

						break;

				case 5:
					cout << "\nCurrent Date Entered Into Inventory:  " 
						 << book[row].dateAdded
						 << endl;

						cin.ignore();

					cout << "Enter new Date:  ";
					cin.getline(date, STR_SIZE);

					setDateAdded(date,row);

						break;

				case 6:
					cout << "\nCurrent Quantity on Hand:  " 
						 << book[row].qtyOnHand
					     << endl;

						cin.ignore();

					cout << "Enter new Quantity on Hand:  ";
					cin >> quantity;

					setQty(quantity,row);

						break;

				case 7:
					cout << "\nCurrent Wholesale Cost:  " 
						 << book[row].wholesale 
					     << endl;

						cin.ignore();

					cout << "Enter new Wholesale Cost:  ";
					cin >> wholesale;

					setWholesale(wholesale,row);

						break;

				case 8:
					cout << "\nCurrent Retail Price:  " 
						 << book[row].retail 
					     << endl;

						cin.ignore();

					cout << "Enter new Retail Price:  ";
					cin >> retail;

					setRetail(retail,row);

				} // end switch


			} while (choice != 9); // end do

				break;

		} // end if

			else 
			{
				continue;
			}

		}	// end 'Search for Match' if

	}	// end the 'book title search' for loop

	if (row == NUM_BOOKS - 1)
	{
		cout << "\nSorry.  No title matching \'" 
			 << title 
			 << "\' was found."  
			 << "\n\n";
	}

}	// end function editBook
//********************************************
// deleteBook function                       *
//********************************************

void deleteBook()
{
	char title[STR_SIZE];	// stores a book tile the user enters
	int  choice = 0;		// stores the user's numeric choice
	char response = 'N';	// stores the user's alphanumeric response
	int row;                // Used in a loop to step through the array

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase
	
	// enter the 'book title search' for loop
	for (row = 0; row < NUM_BOOKS; row++)
	{
		// search for a match 
		if (strstr(book[row].bookTitle, title)) // if they match
		{  
			// display a possible match
			cout << "\nPossible Match Found:  " 
				 << book[row].bookTitle
			     << "\n\n";

			// prompt the user for confirmation
			cout << "Is this a Correct Match?\n";
			cout << "1.Yes\n";
			cout << "2.No\n\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
			
			// validate the user's input
			while (choice != 1 && choice != 2)
			{
				cout << "Please enter a number in the range 1 - 2\n\n";
				cout << "Is this a Correct Match?\n";
				cout << "1.Yes\n";
				cout << "2.No\n\n";

				cout << "Enter Your Choice: ";
				cin >> choice;
			}

			if (choice == 1)
			{  
				// call function 'bookInfo' to display the results
				bookInfo(book[row].isbn, book[row].bookTitle, 
					     book[row].author, book[row].publisher,
						 book[row].dateAdded, book[row].qtyOnHand, 
						 book[row].wholesale, book[row].retail);

			// prompt the user to delete the record
			cout << "Would you like to delete this entire record?(Y/N):  ";
			cin >> response;

			// validate the user's input
			while( response != 'y' && response != 'Y' && response != 'n' && response != 'N')
			{
				cout << "\nPlease enter \'Y\' for Yes or \'N\' for No.\n\n";

					cout << "Would you like to delete this entire record?(Y/N):  ";
					cin >> response;
			}

			if (response == 'Y' || response == 'y')
			{
				removeBook(row);

				// notify the user that the record has been deleted
				cout << "\nRecord has been deleted.\n";

			} // end if

				break;
			}
			else 
			{
				cout << "\nRecord was not deleted.\n";
				continue;
			}

		}	// end if match found

	}	// end the 'book title search' for loop

	if (row == NUM_BOOKS - 1)
	{
		cout << "\nSorry.  No title matching \'" 
			 << title 
			 << "\' was found."  
			 << "\n\n";
	}	

}  // end function deleteBook

//********************************************
// invMenu function                          *
//********************************************

void invMenu()
{
	int choice = 0; // stores user's choice

	// display the 'Inventory Database Menu' until item 5 is selected
	while (choice != 5)
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

		// display user prompt
		cout << "\t\tEnter Your Choice: ";
		cin >> choice;

		// validate the user's input
		while (choice < 1 || choice > 5)
		{
			cout << "\n\t\tPlease enter a number in the range 1 - 5.\n\n";

			cout << "\t\tEnter Your Choice: ";
			cin >> choice;
		}

		// call the selected function
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
				cout << "\n\t\tYou selected item 5.\n";
					break;

		}	// end switch

	}	// end the 'Inventory Database Menu' while loop

	cout << endl << endl;

}	// end function invMenu


