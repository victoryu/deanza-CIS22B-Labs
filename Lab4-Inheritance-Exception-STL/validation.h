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

// Specification file for the 'Validation' Class
#ifndef VALIDATION_H
#define VALIDATION_H

const int CHOICE_SIZE = 81;			 // constant for c-string array size

// Declaration of the 'Validation' class
class Validation				
{
private:	
	char choice[CHOICE_SIZE];		 // The user's valid choice
	void cstrUpper(char*);			 // Converts a c-string to uppercase
public:
	Validation();					 // The defalult constructor
	char* getValidChoice();			 // Returns the private member variable 'choice'
	int	  getValidIntChoice();		 // Returns the integer conversion of 'choice'
	bool isValid  (char*, int, int); // returns true if the input is valid
	bool isValid  (char*);			 // returns true if the input is valid
};

#endif