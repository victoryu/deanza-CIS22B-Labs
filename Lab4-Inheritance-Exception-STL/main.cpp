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

#include "menu.h"						
#include "validation.h"					
#include "fileio.h"						
#include "bookdata.h"					
#include "mainmenu.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"

const int	 NUM_BOOKS	 = 20;			// the maximum number of books
const int	 NUM_WIDTH	 =  6;			// the numeric display length
const int	 TITLE_WIDTH = 26;			// the title display length
const int	 ISBN_WIDTH	 = 14;			// the ISBN display length
const int	 PRECISION	 =  2;			// the decimal precision
const int	 STR_SIZE	 = 51;			// constant for c-string array size
const double SALES_TAX	 =  0.06;		// the rate of the sales tax

BookData book[NUM_BOOKS];				// an array of BookData objects
Menu bookMenu;							// an instance of the Menu class
FileIO invFile("inventory.dat");		// an instance of the FileIO class
Validation menuChoice;					// an instance of the Validation class

int main()
{
	do	// display the 'Main Menu' until item '4' is selected
	{	
		bookMenu.mainMenu();	

		// prompt the user and validate input
		menuChoice.isValid(bookMenu.itemListPrompt(), 1, 4);

		// branch to the selected item from the 'Main Menu'
		switch(menuChoice.getValidIntChoice())
		{
		case 1:
			cashier();	// display the 'Cashier' module
			break;

		case 2:
			do	// displays the 'Inventory Database Menu' until item '5' is selected
			{
				do	// display until a valid item is selected
				{
					bookMenu.invMenu();

				// prompt the user and validate input
				}while(!menuChoice.isValid(bookMenu.itemListPrompt(), 1, 5));	

				// branch to the selected item from the 'Inventory Database Menu'
				switch(menuChoice.getValidIntChoice())
				{
				case 1:
					lookUpBook();	// call the 'lookUpBook' Function
					break;

				case 2:
					addBook();		// call the 'addBook' Function
					break;

				case 3:	
					editBook();		// call the 'editBook' Function
					break;

				case 4:	
					deleteBook();	// call the 'deleteBook' Function
					break;

				case 5:	
					break;	// Return to the 'Main Menu'
				}

			}while(menuChoice.getValidIntChoice() != 5);	// end 'InvMenu' do

			break;	// Return to the 'Main Menu'

		case 3:
			do	// display the 'Reports Menu' until item '5' is selected
			{
				do	// display until a valid item is selected
				{
					bookMenu.reports();

				// prompt the user and validate input
				}while(!menuChoice.isValid(bookMenu.itemListPrompt(), 1, 7));

				// branch to the selected item from the 'Reports Module Menu'
				switch(menuChoice.getValidIntChoice())
				{
				case 1:	
					repListing();	// call the 'repListing' Function
					break;

				case 2:	
					repWholesale();	// call the 'repWholesale' Function
					break;

				case 3:
					repRetail();	// call the 'repRetail' Function
					break;

				case 4:	
					repQty();		// call the 'repQty' Function
					break;

				case 5:	
					repCost();		// call the 'repCost' Function
					break;

				case 6:	
					repAge();		// call the 'repAge' Function
					break;

				case 7:	
					break;	// Return to the 'Main Menu'
				}

			}while(menuChoice.getValidIntChoice() != 7);// end 'Reports Module Menu' do

			break;		// Return to the 'Main Menu'

		case 4:	// item '4' is selected from the 'Main Menu'

			cout << "\n\nGoodbye\n\n";
			exit(0);	// exit the program

			break;
		}

	}while(menuChoice.getValidIntChoice() != 4);	// end 'Main Menu' do
	
	return 0;
}	
