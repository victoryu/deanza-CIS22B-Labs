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

// Implementation file for the 'Validation' Class
#include "validation.h"
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//****************************************************************
// The Default Constructor.                                      *
// Sets the private member variable 'choice' to an empty         *
// c-string.                                                     *
//****************************************************************
Validation::Validation()
{
	strcpy(choice, "\0");
}

//****************************************************************
// The cstrUpper Private Member Function.						 *
// Converts a c-string to upper case.                            *
//****************************************************************
void Validation::cstrUpper(char* userChoice)
{
	// convert the c-string to uppercase.
	while(*userChoice != 0)
	{
		*userChoice = toupper(*userChoice);

		userChoice++;
	}
}

//****************************************************************
// The getChoice Member Function.								 *
// Returns a c-string containing the private member variable     *
// 'choice'.                                                     *
//****************************************************************
char* Validation::getValidChoice()
{
	return choice;
}

//****************************************************************
// The getChoice Member Function.								 *
// Returns an integer containing the private member variable     *
// 'choice'.                                                     *
//****************************************************************
int Validation::getValidIntChoice()
{
	return atoi(choice);
}

//****************************************************************
// The overloaded isValid Member Function.						 *
// Validates input based on the two integer ranges that are      *
// passed as arguments.		                                     *
// Returns true if the choice is valid, otherwise return false,  *
// and displays a message to the user indicating the range of    *
// valid choices.                                                *
//****************************************************************
bool Validation::isValid(char* userChoice, int startRange, int endRange )
{
	// convert the c-string to an integer
	int intChoice;
	intChoice = atoi(userChoice);

	// validate the user's choice
	while(intChoice < startRange || intChoice > endRange) // choice is invalid
	{
		// display the valid range of choices 
		cout << "\nPlease enter a number in the range " 
			 << startRange 
			 << " - " 
			 << endRange 
			 << ".\n\n";

		return false;	// return false
	}

	// set private member variable 'choice' to the valid value
	strcpy(choice, userChoice);	

	return true;	// return true
}

//****************************************************************
// The overloaded isValid Member Function.						 *
// Returns true if the choice is valid, otherwise return false,  *
// and displays a message to the user indicating the range of    *
// valid choices.                                                *
//****************************************************************
bool Validation::isValid(char* userChoice)
{
	// covert to uppercase
	cstrUpper(userChoice);

	// validate the user's choice
	while(strcmp(userChoice,"Y") != 0 && strcmp(userChoice,"N") != 0)
	{
		// display the valid choices to the user
		cout << "\nPlease enter Y or N.\n\n";
		
		return false;	// return false
	}

	// set private member variable 'choice' to the valid value
	strcpy(choice, userChoice);

	return true;	// return true
}