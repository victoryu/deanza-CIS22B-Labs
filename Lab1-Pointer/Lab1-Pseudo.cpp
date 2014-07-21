#include "cashier.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 20;

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

void cashier()
{
	// Constants
	const double SALES_TAX	= 0.06;	// The sales tax


	char again;						// To hold Y or N input
	string	isbnNumber[SIZE];		// ISBN number of each book ordered
	string	thisTitle [SIZE];		// title of each book ordered

	int		quantityBooks[SIZE];	// quantity of each book ordered
	double	unitPrice	 [SIZE];	// unit price of each book ordered
	double	subTotal	 [SIZE];	// total of the each order before sales tax
	string	transDate;				// the transaction date

	double	orderSalesTax	= 0;	// the amount of sales tax for this order
	double	runningTotal	= 0;	// the total of the order before sales tax
	double	grandTotal		= 0;	// the subtotal + sales tax 
	int		validQty		= 0;	// stores quantity of a book before user input

	int		choice			= 0;	// stores the user's choice
	int		counter			= 0;	// counts each new book ordered

	// 'Process Another Transaction' repeats the program until item 2 is selected
	while(choice != 2)	
	{
		counter = 0;		// reset the counter

		// display company name and screen title

		// enter date of purchase

			// 'Add Another Title' repeats the program until item 2 is selected
			while(choice != 2)	
			{
				// 'Re-enter ISBN Number' re-enter the ISBN number until item 2 is selected
				while(choice != 2) 
				{
					// prompt the user to enter an ISBN number
				
				// enter the 'search for isbn number' for loop

						// store book information in local variables
						// store quantity before input

						// prompt the user to enter quantity of books

						// validate user's input
						while(quantityBooks[counter] < 1)
						{

						}

						// quantity requested is in inventory
						if(quantityBooks[counter] <= qtyOnHand[index])
						{
							// remove the quantity requested from inventory

						}

						// quantity requested is not in inventory
						else if(quantityBooks[counter] > qtyOnHand[index])
						{
							// decrement the counter
							// restore quantity before input				
							return;		// return to the Main Menu
						}

						// prompt the user to add another title
						cout << "\nAdd another title to this order?\n";
						cout << "1. Yes\n";
						cout << "2. No\n\n";

						cout << "Enter Your Choice: ";
						cin	 >> choice;
						cin.ignore();

						counter++;		// increment the counter

						cout << endl;

						// validate user's input
						while (choice != 1 && choice != 2)
						{
							cout << "\nPlease enter a number in the range 1 - 2.\n\n";

							cout << "\nAdd another title to this order?\n";
							cout << "1. Yes\n";
							cout << "2. No\n\n";

							cout << "Enter Your Choice: ";
							cin	 >> choice;
							cin.ignore();
						}		

						break;

					}	// end if 

					else if(index == SIZE - 1)
					{
						cout << "\nISBN number was not found.\n\n";

						cout << "Re-enter ISBN number?\n";
						cout << "1.Yes\n";
						cout << "2.No\n\n";

						cout << "Enter Your Choice: ";
						cin	 >> choice;
						cin.ignore();

						// validate user's input
						while (choice != 1 && choice != 2)
						{
							cout << "\nPlease enter a number in the range 1 - 2.\n\n";

							cout << "\nRe-enter ISBN number?\n";
							cout << "1. Yes\n";
							cout << "2. No\n\n";

							cout << "Enter Your Choice: ";
							cin	 >> choice;
							cin.ignore();
						}	

					}	// end else if 

				}	// end the 'search for isbn number' for loop

				cout << endl;

			}	// end the 'Re-enter ISBN Number' while loop

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
				subTotal[i]		= (quantityBooks[i] * unitPrice[i]);
				orderSalesTax  += (subTotal[i] * SALES_TAX);
				runningTotal   +=  subTotal[i];
				grandTotal		= (orderSalesTax + runningTotal);

				// display order information
				cout << fixed 
					 << showpoint 
					 << right 
					 << setprecision(2);

				cout << quantityBooks[i] 
					 << "\t";

				cout << left 
					 << setw(14) 
					 << isbnNumber[i] 
					 << "\t";

				cout << left 
					 << setw(26) 
					 << thisTitle[i] 
					 << "\t$ ";

				cout << fixed 
					 << showpoint 
					 << right;

				cout << setw(6) 
					 << unitPrice[i] 
					 << "\t$ ";

				cout << setw(6) 
					 << subTotal[i];

			}	// end the 'Display Information' for loop

			cout << "\n\n\n";

			// display footer information
			cout << "\t\t\tSubtotal\t\t\t\t\t$ " 
				 << setw(6) 
				 << setprecision(2) 
				 << fixed 
				 << runningTotal 
				 << "\n";

			cout << "\t\t\tTax\t\t\t\t\t\t$ " 
				 << setw(6) 
				 << setprecision(2) 
				 << fixed 
				 << orderSalesTax 
				 << "\n";

			cout << "\t\t\tTotal\t\t\t\t\t\t$ "
				 << setw(6) 
				 << setprecision(2) 
				 << fixed 
				 << grandTotal 
				 << "\n\n";

			cout << "Thank You for Shopping at Serendipity!\n";
	
			cout << endl << endl;

			}	// end 'Order verification' if

		// prompt the user to enter another transaction
		cout << "\nProcess another transaction?\n";
		cout << "1. Yes\n";
		cout << "2. No\n\n";

		cout << "Enter Your Choice: ";
		cin	 >> choice;

		// validate user's input
		while (choice != 1 && choice != 2)
		{
			cout << "\nPlease enter a number in the range 1 - 2.\n\n";

			cout << "\nProcess another transaction?\n";
			cout << "1. Yes\n";
			cout << "2. No\n\n";

			cout << "Enter Your Choice: ";
			cin	 >> choice;
		} 

	}	// end the 'Process Another Transaction' while loop

	cout << endl << endl;

}	// end cashier function