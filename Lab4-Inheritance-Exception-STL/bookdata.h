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

// Specification file for the 'BookData' Class
#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

const int CSTR_SIZE = 81;			// Constant for c-string array size

class FileIO;

// BookData class declaration

class BookData
{
private:
	char	bookTitle[CSTR_SIZE];	 // Title of a book
	char	isbn	 [CSTR_SIZE];	 // ISBN number of a book
	char	author	 [CSTR_SIZE];	 // Book author's name 
	char	publisher[CSTR_SIZE];	 // Book publisher's name 
	char	dateAdded[CSTR_SIZE];	 // Date a book was added into inventory
	int		qtyOnHand;				 // Quantity on hand of a book
	double	wholesale;				 // Wholesale price of a book
	double	retail;					 // Retail price of a book
public:
	BookData();						 // the default constructor	

	// Mutator functions
	void   setTitle	   (char*);		 // sets the title of a book
	void   setISBN	   (char*);		 // sets the ISBN of a book
	void   setAuthor   (char*);		 // sets the author of a book
	void   setPub      (char*);		 // sets the publisher of a book
	void   setDateAdded(char*);		 // sets the date a book was added into inventory
	void   setQty	   (int);		 // sets the quantity on hand of a book
	void   setWholesale(double);	 // sets the wholesale cost of a book
	void   setRetail   (double);	 // sets the retail price of a book

	// Accessor functions
	char*  getTitle    ();			 // returns the title of a book
	char*  getISBN	   ();			 // returns the ISBN of a book
	char*  getAuthor   ();			 // returns the author of a book
	char*  getPub      ();			 // returns the publisher of a book
	char*  getDateAdded();			 // returns the date a book was added into inventory
	int    getQty      () const;	 // returns the quantity on hand of a book
	double getWholesale() const;	 // returns the wholesale cost of a book
	double getRetail   () const;	 // returns the retail price of a book

	// Member functions
	int    isEmpty     (BookData &);				// returns 1 if the book is empty
	void   removeBook  (BookData &, FileIO &, int);	// removes a book from the file
	bool   bookMatch   (BookData &, char*);			// returns true if a match is found
};
#endif