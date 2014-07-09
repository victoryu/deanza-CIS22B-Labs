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
#include "bookinfo.h"
#include <iostream>
using namespace std;

// ********************************************************
// The bookInfo function displays the Book Information    *
// Screen                                                 *
//                                                        *
// isbn:      The ISBN number of a book                   *
// title:     The book title                              *
// author:    The author’s name                           *
// publisher: The publisher’s name                        *
// date:      The date the book was added to inventory    *
// qty:       The quantity on hand of the book            *
// wholesale: The wholesale cost of the book              *
// retail:    The retail price of the book                *
// ********************************************************
void bookInfo(string isbn, string title, string author, 
	          string publisher, string date, int qty, 
			  double wholesale, double retail)
{
	cout << "\t\t\tSerendipity Booksellers\n";
	cout << "\t\t\t    Book Information\n\n";

	cout << "ISBN: "<< isbn << endl;
	cout << "Title: "<< title << endl;
	cout << "Author: "<< author << endl;
	cout << "Publisher: "<< publisher << endl;
	cout << "Date Added: "<< date << endl;
	cout << "Quantity-On-Hand: "<< qty << endl;
	cout << "Wholesale Cost: "<< wholesale << endl;
	cout << "Retail Price: "<< retail << endl;

	cout << endl << endl;
}