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
#include <iostream>
#include "invmenu.h"
#include "strupper.h"
#include "validation.h"					
#include "fileio.h"						
#include "bookdata.h"
#include "menu.h"
using namespace std;

const int STR_SIZE  = 51;      // represents the maximum string size
const int NUM_BOOKS	= 20;        // the number of books in inventory
extern BookData book[NUM_BOOKS]; // the array of 'BookData' objects	

//********************************************
// lookUpbook function                       *
//********************************************

void lookUpBook()
{
	int row;
	char title[STR_SIZE];	// stores a book title the user enters

	FileIO invFile("inventory.dat");		// an instance of the FileIO class
	Validation menuChoice;					// an instance of the Validation class
	Menu bookMenu;							// an instance of the Menu class

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase

	// open the inventory file
	invFile.open();

	for(int fromFile = 0; (fromFile < NUM_BOOKS) && (!invFile.eof()); fromFile++)
	{
		// read from the file
		invFile.read(book[fromFile], fromFile);
	}

	// close the inventory file
	invFile.close();

	// enter the 'book title search' for loop
	for (row = 0; row < NUM_BOOKS; row++)
	{
		// search for a match 
		if (book[row].bookMatch(book[row], title)) // if they match
		{  
			// display a possible match
			cout << "\nPossible Match Found:  " 
				 << book[row].getTitle()
			     << "\n\n";

			// prompt the user for confirmation
			do
			{
				cout << "Is this a Correct Match?\n";
				cout << "1.Yes\n";
				cout << "2.No\n\n";
			
			// validate user's input
			}while(!menuChoice.isValid(bookMenu.itemListPrompt(),1,2));

			if (menuChoice.getValidIntChoice() == 1)
			{  
				// call function 'bookInfo' to display the results
				bookInfo(book[row].getISBN(), book[row].getTitle(), 
					     book[row].getAuthor(), book[row].getPub(),
						 book[row].getDateAdded(), book[row].getQty(), 
						 book[row].getWholesale(), book[row].getRetail());
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

	FileIO invFile("inventory.dat");		// an instance of the FileIO class

	// open the inventory file
	invFile.open();

		while(!invFile.eof())
		{
			for(int fromFile = 0; fromFile < NUM_BOOKS; fromFile++)
			{
				// read from the file
				invFile.read(book[fromFile], fromFile);

				// store the data that was read from the file
				book[fromFile];	
			}

		}	// end 'eof' while loop

	// close the inventory file
	invFile.close();

	for (int record = 0; record < NUM_BOOKS; record++)
	{
		// find the first empty book title.
		if (book[record].isEmpty(book[record]))
		{
			cin.ignore();

			cout << "\nEnter Title: ";
			cin.getline(title,STR_SIZE);

			strUpper(title);

			book[record].setTitle(title);
			
			cout << "\nEnter ISBN(#-###-#####-#): ";
			cin.getline(isbn,STR_SIZE);

			strUpper(isbn);

			book[record].setISBN(isbn);
			
			cout << "\nEnter Author: ";
			cin.getline(author,STR_SIZE);

			strUpper(author);

			book[record].setAuthor(author);

			cout << "\nEnter Publisher: ";
			cin.getline(publisher,STR_SIZE);

			strUpper(publisher);

			book[record].setPub(publisher);
			
			cout << "\nEnter Date Added to Inventory (MM/DD/YYYY): ";
			cin.getline(date, STR_SIZE);

			book[record].setDateAdded(date);

			cout << "\nEnter Quantity Being Added: ";
			cin >> quantity;

			book[record].setQty(quantity);

			cout << "\nEnter Wholesale Cost: ";
			cin >> wholesale;

			book[record].setWholesale(wholesale);

			cout << "\nEnter Retail Price: ";
			cin >> retail;

			book[record].setRetail(retail);

			// open the inventory file
			invFile.open();

			// write the information to the file
			invFile.write(book[record], record);

			// close the inventory file
			invFile.close();

			cout << "\n\nRecord was successfully entered.\n";

			break;

		}	// end if

		else if (record == NUM_BOOKS - 1)
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

	int row;

	FileIO invFile("inventory.dat");		// an instance of the FileIO class
	Validation menuChoice;					// an instance of the Validation class
	Menu bookMenu;							// an instance of the Menu class

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase
	
	// open the inventory file
	invFile.open();

		while(!invFile.eof())
		{
			for(int fromFile = 0; fromFile < NUM_BOOKS; fromFile++)
			{
				// read from the file
				invFile.read(book[fromFile], fromFile);

				// store the data that was read from the file
				book[fromFile];	
			}

		}	// end 'eof' while loop

	// close the inventory file
	invFile.close();

	// enter the 'book title search' for loop
	for (row = 0; row < NUM_BOOKS; row++)
	{
		// search for a match
		if (book[row].bookMatch(book[row], title)) // if they match
		{  
			// display a possible match
			cout << "\nPossible Match Found:  " 
				 << book[row].getTitle()
			     << "\n\n";

			// prompt the user for confirmation
			do
			{
				cout << "Is this a Correct Match?\n";
				cout << "1.Yes\n";
				cout << "2.No\n\n";
			
			// validate user's input
			}while(!menuChoice.isValid(bookMenu.itemListPrompt(),1,2));

			if (menuChoice.getValidIntChoice() == 1)
			{  
				// call function 'bookInfo' to display the results
				bookInfo(book[row].getISBN(), book[row].getTitle(), 
					     book[row].getAuthor(), book[row].getPub(),
						 book[row].getDateAdded(), book[row].getQty(), 
						 book[row].getWholesale(), book[row].getRetail());
			do 
			{
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

				cout << "Please choose 1 - 8 to EDIT an item, or 9 to EXIT\n";

				// validate user's input
				}while(!menuChoice.isValid(bookMenu.itemListPrompt(),1,9));

				// diplay the selected item
				switch (menuChoice.getValidIntChoice())
				{

				case 1:
					cout << "\nCurrent ISBN:  " 
						 << book[row].getISBN()
						 << endl;

						cin.ignore();

					cout << "Enter new ISBN(#-###-#####-#): ";
					cin >> isbn;
					
					strUpper(isbn);
					book[row].setISBN(isbn);

					// open the inventory file
					invFile.open();

					// write the information to the file
					invFile.write(book[row], row);

					// close the inventory file
					invFile.close();

						break;

				case 2:
					cout << "\nCurrent Title:  " 
						 << book[row].getTitle()
						 << endl;

						cin.ignore();

					cout << "Enter new Title:  ";
					cin.getline(title, STR_SIZE);

					strUpper(title);

					book[row].setTitle(title);

					// open the inventory file
					invFile.open();

					// write the information to the file
					invFile.write(book[row], row);

					// close the inventory file
					invFile.close();

						break;

				case 3:
					cout << "\nCurrent Author:  " 
						 << book[row].getAuthor() 
						 << endl;

						cin.ignore();

					cout << "Enter new Author:  ";
					cin.getline(author , STR_SIZE);

					strUpper(author);
					
					book[row].setAuthor(author);

					// open the inventory file
					invFile.open();

					// write the information to the file
					invFile.write(book[row], row);

					// close the inventory file
					invFile.close();

						break;

				case 4:
					cout << "\nCurrent Publisher:  " 
						 << book[row].getPub()
						 << endl;

						cin.ignore();

					cout << "Enter new Publisher:  ";
					cin.getline(publisher , STR_SIZE);

					strUpper(publisher);

					book[row].setPub(publisher);

					// open the inventory file
					invFile.open();

					// write the information to the file
					invFile.write(book[row], row);

					// close the inventory file
					invFile.close();

						break;

				case 5:
					cout << "\nCurrent Date Entered Into Inventory:  " 
						 << book[row].getDateAdded()
						 << endl;

						cin.ignore();

					cout << "Enter new Date(MM/DD/YYYY):  ";
					cin.getline(date, STR_SIZE);

					book[row].setDateAdded(date);

					// open the inventory file
					invFile.open();

					// write the information to the file
					invFile.write(book[row], row);

					// close the inventory file
					invFile.close();

						break;

				case 6:
					cout << "\nCurrent Quantity on Hand:  " 
						 << book[row].getQty()
					     << endl;

						cin.ignore();

					cout << "Enter new Quantity on Hand:  ";
					cin >> quantity;

					book[row].setQty(quantity);

					// open the inventory file
					invFile.open();

					// write the information to the file
					invFile.write(book[row], row);

					// close the inventory file
					invFile.close();

						break;

				case 7:
					cout << "\nCurrent Wholesale Cost:  " 
						 << book[row].getWholesale()
					     << endl;

						cin.ignore();

					cout << "Enter new Wholesale Cost:  ";
					cin >> wholesale;

					book[row].setWholesale(wholesale);

					// open the inventory file
					invFile.open();

					// write the information to the file
					invFile.write(book[row], row);

					// close the inventory file
					invFile.close();

						break;

				case 8:
					cout << "\nCurrent Retail Price:  " 
						 << book[row].getRetail()
					     << endl;

						cin.ignore();

					cout << "Enter new Retail Price:  ";
					cin >> retail;

					book[row].setRetail(retail);

					// open the inventory file
					invFile.open();

					// write the information to the file
					invFile.write(book[row], row);

					// close the inventory file
					invFile.close();

				} // end switch


			} while (menuChoice.getValidIntChoice() != 9); // end do

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
	int row;
	char title[STR_SIZE];	// stores a book tile the user enters
	FileIO invFile("inventory.dat");		// an instance of the FileIO class
	Validation menuChoice;					// an instance of the Validation class
	Menu bookMenu;							// an instance of the Menu class

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase

	// open the inventory file
	invFile.open();

		while(!invFile.eof())
		{
			for(int fromFile = 0; fromFile < NUM_BOOKS; fromFile++)
			{
				// read from the file
				invFile.read(book[fromFile], fromFile);

				// store the data that was read from the file
				book[fromFile];	
			}

		}	// end 'eof' while loop

	// close the inventory file
	invFile.close();
	
	// enter the 'book title search' for loop
	for (row = 0; row < NUM_BOOKS; row++)
	{
		// search for a match 
		if (book[row].bookMatch(book[row], title)) // if they match
		{  
			// display a possible match
			cout << "\nPossible Match Found:  " 
				 << book[row].getTitle()
			     << "\n\n";

			// prompt the user for confirmation
			do
			{
				cout << "Is this a Correct Match?\n";
				cout << "1.Yes\n";
				cout << "2.No\n\n";
			
			// validate user's input
			}while(!menuChoice.isValid(bookMenu.itemListPrompt(),1,2));

			if (menuChoice.getValidIntChoice() == 1)
			{  
				// call function 'bookInfo' to display the results
				bookInfo(book[row].getISBN(), book[row].getTitle(), 
					     book[row].getAuthor(), book[row].getPub(),
						 book[row].getDateAdded(), book[row].getQty(), 
						 book[row].getWholesale(), book[row].getRetail());

			// prompt the user to delete the record
			do
			{
				cout << "Would you like to delete this entire record?(Y/N)\n";

			// validate user's input
			}while(!menuChoice.isValid(bookMenu.simplePrompt()));

			if (menuChoice.getValidChoice() == "Y")
			{
				book[row].removeBook(book[row], invFile, row);

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

