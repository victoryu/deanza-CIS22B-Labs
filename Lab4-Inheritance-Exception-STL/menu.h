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

// Specification file for the 'Menu' Class
#ifndef MENU_H
#define MENU_H

#include "BookData.h"

const int PROMPT_SIZE = 81;		// The maximum c-string size 

class Menu
{
private:
char choice[PROMPT_SIZE];		// the users choice
public:
	Menu();						// the default constructor

	void mainMenu();			// displays the 'Main Menu'
	void invMenu ();			// displays the 'Inventory Database Menu'
	void reports ();			// displays the 'Reports Menu'

	char* itemListPrompt ();	// used with list menus - sets the choice variable
	char* simplePrompt   ();    // used with Y/N prompt - sets the choice variable
};

#endif