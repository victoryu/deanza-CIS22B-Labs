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
#include <iomanip>
#include "cashier.h"
#include "validation.h"					
#include "fileio.h"						
#include "bookdata.h"
#include "menu.h"
using namespace std;

const int    STR_SIZE  = 51;      // represents the maximum string size
const int	 NUM_WIDTH	 =  6;	  // the numeric display length
const int	 TITLE_WIDTH = 26;	  // the title display length
const int	 ISBN_WIDTH	 = 14;	  // the ISBN display length
const int	 NUM_BOOKS	 = 20;	  // the number of books in inventory
const int	 PRECISION	 =  2;	  // the decimal precision
const double  SALES_TAX	 =  0.06; // the rate of the sales tax

extern BookData book[NUM_BOOKS];	// the array of 'BookData' objects

//********************************************
// cashier function                          *
//********************************************

void cashier()
{
	char	isbnNumber[NUM_BOOKS][STR_SIZE];	// ISBN number of each book ordered
	char	thisTitle [NUM_BOOKS][STR_SIZE];	// title of each book ordered

	char	quantityBooks[NUM_BOOKS][STR_SIZE];	// quantity of each book ordered
	double	unitPrice	 [NUM_BOOKS];			// unit price of each book ordered
	double	subTotal	 [NUM_BOOKS];			// total before sales tax
	char	transDate	 [STR_SIZE];			// the transaction date

	double	orderSalesTax	= 0;	// the amount of sales tax for this order
	double	runningTotal	= 0;	// the total of the order before sales tax
	double	grandTotal		= 0;	// the subtotal + sales tax 
	int		validQty		= 0;	// stores quantity of a book before user input
	int     subQty			= 0;	// stores the quantity of a book after sale
	int		counter			= 0;	// counts each new book ordered

	FileIO invFile("inventory.dat");		// an instance of the FileIO class
	Validation menuChoice;					// an instance of the Validation class
	Menu bookMenu;							// an instance of the Menu class

	// open the inventory file
	invFile.open();

	while(!invFile.eof())
	{
		for( int fromFile = 0; fromFile < NUM_BOOKS; fromFile++)
		{
			// read from the inventory file
			invFile.read(book[fromFile], fromFile);
			// store data into a BookData object
			book[fromFile];
		}
	}

	// close the file
	invFile.close();

	// 'Process Another Transaction' repeats the program until item 2 is selected
	while(menuChoice.getValidIntChoice() != 2)	
	{
		counter = 0;		// reset the counter

		// display company name and screen title
		cout << "\n\nSerendipity Booksellers\n";
		cout << " Cashier Module\n\n";

		// enter date of purchase
		cin.ignore();
		cout << "Date(MM/DD/YY): ";
		cin.getline(transDate,STR_SIZE);

			// 'Add Another Title' add another title until item 2 is selected
			while(menuChoice.getValidIntChoice() != 2)	
			{
				// 'Re-enter ISBN Number' re-enter the ISBN number until item 2 is selected
				while(menuChoice.getValidIntChoice() != 2) 
				{
					// prompt the user to enter an ISBN number
					cout << "ISBN(#-###-#####-#): ";
					cin.getline(isbnNumber[counter],STR_SIZE);
					
				// enter the 'search for isbn number' for loop
				for (int row = 0; row < NUM_BOOKS; row++)
				{
					if(strcmp(isbnNumber[counter],book[row].getISBN()) == 0) // they match
					{
						// display book information
						cout << "Title: " 
							 << book[row].getTitle() 
							 << endl;
					
						cout << fixed 
							 << showpoint 
							 << setprecision(PRECISION) 
							 << "Price: " 
							 << book[row].getRetail()
							 << endl;

						// store book information in local variables
						unitPrice[counter] = book[row].getRetail();
						strcpy(thisTitle[counter], book[row].getTitle());
						
						validQty = book[row].getQty();	// store quantity before input

						// prompt the user to enter quantity of books
						do
						{
						cout << "Quantity of Book: ";
						cin	 >> quantityBooks[counter];
						}while(!menuChoice.isValid(quantityBooks[counter],1,validQty));
						cin.ignore();

						// quantity requested is in inventory
						if(menuChoice.getValidIntChoice() <= validQty)
						{
							// remove the quantity requested from inventory
							subQty = validQty;
							subQty -= menuChoice.getValidIntChoice();

							book[row].setQty(subQty);
						}

						// quantity requested is not in inventory
						else if(menuChoice.getValidIntChoice() > validQty)
						{
							counter--;	// decrement the counter

							book[row].setQty(validQty);	// restore quantity before input

							cout << "\nSorry, insufficient quantity in stock.\n";
							
							return;		// return to the Main Menu
						}

						// prompt the user to add another title
						do
						{
							cout << "\nAdd another title to this order?\n";
							cout << "1. Yes\n";
							cout << "2. No\n\n";

						// validate user's input
						}while(!menuChoice.isValid(bookMenu.itemListPrompt(),1,2));
						cin.ignore();

						counter++;		// increment the counter

						break;

					}	// end if 

					else if(row == NUM_BOOKS - 1)
					{
						cout << "\nISBN was not found.\n\n";

						// prompt the user to re-enter ISBN 
						do
						{
							cout << "Re-enter ISBN?\n";
							cout << "1.Yes\n";
							cout << "2.No\n\n";

						// validate user's input
						}while(!menuChoice.isValid(bookMenu.itemListPrompt(),1,2));
						cin.ignore();
					}	// end else if 

				}	// end the 'search for ISBN' for loop

			}	// end the 'Re-enter ISBN' while loop

		}	// end the 'Add Another Title' while loop

			if( counter > 0)	 // verify at least one order exists
			{

			// display company name
			cout << "\n\nSerendipity Book Sellers\n\n";

			// display date
			cout << "Date: " 
				 << transDate 
				 << "\n\n";

			// display headings
			cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal\n";
			cout << "________________________________________";
			cout << "________________________________________";
			cout << "\n";

			// enter the 'Display Information' for loop
			for (int i = 0; i < counter; i++)
			{
				// perform the calculations
				subTotal[i]		= (atoi(quantityBooks[i]) * unitPrice[i]);
				orderSalesTax  += (subTotal[i] * SALES_TAX);
				runningTotal   +=  subTotal[i];
				grandTotal		= (orderSalesTax + runningTotal);

				// display order information
				cout << fixed 
					 << showpoint 
					 << right 
					 << setprecision(PRECISION);

				cout << quantityBooks[i] 
					 << "\t";

				cout << left 
					 << setw(ISBN_WIDTH) 
					 << isbnNumber[i] 
					 << "\t";

				cout << left 
					 << setw(TITLE_WIDTH) 
					 << thisTitle[i] 
					 << "\t$ ";

				cout << fixed 
					 << showpoint 
					 << right;

				cout << setw(NUM_WIDTH) 
					 << unitPrice[i] 
					 << "\t$ ";

				cout << setw(NUM_WIDTH) 
					 << subTotal[i];

			}	// end the 'Display Information' for loop

			cout << "\n\n\n";

			// display footer information
			cout << "\t\t\tSubtotal\t\t\t\t\t$ " 
				 << setw(NUM_WIDTH) 
				 << setprecision(PRECISION) 
				 << fixed 
				 << runningTotal 
				 << "\n";

			cout << "\t\t\tTax\t\t\t\t\t\t$ " 
				 << setw(NUM_WIDTH) 
				 << setprecision(PRECISION) 
				 << fixed 
				 << orderSalesTax 
				 << "\n";

			cout << "\t\t\tTotal\t\t\t\t\t\t$ "
				 << setw(NUM_WIDTH) 
				 << setprecision(PRECISION) 
				 << fixed 
				 << grandTotal 
				 << "\n\n";

			cout << "Thank You for Shopping at Serendipity!\n";
	
			cout << endl << endl;

			}	// end 'Order verification' if

		// prompt the user to enter another transaction
		do
		{
			cout << "\nProcess another transaction?\n";
			cout << "1. Yes\n";
			cout << "2. No\n\n";

		// validate user's input
		}while(!menuChoice.isValid(bookMenu.itemListPrompt(),1,2));

	}	// end the 'Process Another Transaction' while loop

	cout << endl << endl;

}	// end cashier function
			
