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
#include <cstring>
#include "bookdata.h"
#include "strupper.h"
using namespace std;

const int NUM_BOOKS = 20;        // the maximum number of books
extern BookData book[NUM_BOOKS]; // the array of 'BookData' stuctures


//*********************************************************
// Function setTitle                                      *
//*********************************************************

void setTitle(char* newTitle, int subscript)
{
	strUpper(newTitle);
	strcpy(book[subscript].bookTitle, newTitle);
}

//*********************************************************
// Function setISBN                                       *
//*********************************************************

void setISBN(char* newISBN, int subscript)
{
	strUpper(newISBN);
	strcpy(book[subscript].isbn, newISBN);
}

//*********************************************************
// Function setAuthor                                     *
//*********************************************************

void setAuthor(char* newAuthor, int subscript)
{
	strUpper(newAuthor);
	strcpy(book[subscript].author, newAuthor);
}

//*********************************************************
// Function setPub                                        *
//*********************************************************

void setPub(char* newPublisher, int subscript)
{
	strUpper(newPublisher);
	strcpy(book[subscript].publisher, newPublisher);
	
}

//*********************************************************
// Function setDateAdded                                  *
//*********************************************************

void setDateAdded(char* newDate, int subscript)
{
	strcpy(book[subscript].dateAdded, newDate);
}

//*********************************************************
// Function setQty                                        *
//*********************************************************

void setQty(int newQuantity, int subscript)
{
	book[subscript].qtyOnHand = newQuantity;
}

//*********************************************************
// Function setWholesale                                  *
//*********************************************************

void setWholesale(double newWholesale, int subscript)
{
	book[subscript].wholesale = newWholesale;
}

//*********************************************************
// Function setRetail                                     *
//*********************************************************

void setRetail(double newRetail, int subscript)
{
	book[subscript].retail = newRetail;
}

//*********************************************************
// Function isEmpty                                       *
//*********************************************************

int isEmpty(int subscript)
{
	if (book[subscript].bookTitle[0] == 0)
	{
		return 1;
	}
	else return 0;
}

//*********************************************************
// Function removeBook                                    *
//*********************************************************

void removeBook(int subscript)
{
	book[subscript].bookTitle[0] = 0;
	book[subscript].isbn[0] = 0;
}