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

// Implementation file for the 'BookData' Class
#include "bookdata.h"
#include "fileio.h"

//****************************************************************
// The Default Constructor sets the private member variable      *
// 'bookTitle' to an empty c-string.                             *
//****************************************************************

BookData::BookData()								
{ 
	strcpy(bookTitle,"\0"); 
}

//****************************************************************
// The setTitle Member Function.								 *
// Stores a c-string, representing a book title, in the private  *
// member variable 'bookTitle'.                                  *
//****************************************************************
void BookData::setTitle (char* newBookTitle)
{	
	strcpy(bookTitle, newBookTitle); 
}

//****************************************************************
// The getTitle Member Function.								 *
// Returns a c-string containing the private member variable     *
// 'bookTitle'.                                                  *
//**************************************************************** 
char* BookData::getTitle() 			
{ 
	return bookTitle; 
}

//****************************************************************
// The setISBN Member Function.								     *
// Stores a c-string, representing a book ISBN, in the private   * 
// member variable 'isbn'.                                       *
//****************************************************************
void BookData::setISBN (char* newISBN)
{ 
	strcpy(isbn, newISBN);
}

//****************************************************************
// The getISBN Member Function.								     *
// Returns a c-string containing the private member variable     *
// 'isbn'.                                                       *
//****************************************************************
char* BookData::getISBN()		
{ 
	return isbn; 
}

//****************************************************************
// The setAuthor Member Function.								 *
// Stores a c-string, representing a book author, in the private * 
// member variable 'author'.                                     *
//****************************************************************
void BookData::setAuthor (char* newAuthor)
{ 
	strcpy(author, newAuthor); 
}

//****************************************************************
// The getAuthor Member Function.								 *
// Returns a c-string containing the private member variable     *
// 'author'.                                                     *
//****************************************************************
char* BookData::getAuthor()				
{ 
	return author; 
}

//****************************************************************
// The setPub Member Function.								     *
// Stores a c-string, representing a book publisher, in the      * 
// private member variable 'publisher'.                          *
//****************************************************************
void BookData::setPub (char* newPublisher)
{ 
	strcpy(publisher, newPublisher); 
}

//****************************************************************
// The getPub Member Function.								     *
// Returns a c-string containing the private member variable     *
// 'publisher'.                                                  *
//****************************************************************
char* BookData::getPub() 				
{ 
	return publisher; 
}

//****************************************************************
// The setDateAdded Member Function.							 *
// Stores a c-string, representing the date a book was added     *
// into inventory, in the private member variable 'dateAdded'.   *
//****************************************************************
void BookData::setDateAdded(char* newDateAdded)
{	
	strcpy(dateAdded, newDateAdded); 
}

//****************************************************************
// The getDateAdded Member Function.						     *
// Returns a c-string containing the private member variable     *
// 'dateAdded'.                                                  *
//****************************************************************
char* BookData::getDateAdded()				
{ 
	return dateAdded; 
}

//****************************************************************
// The setQty Member Function.							         *
// Stores an integer, representing the quanitity on hand of a    *
// book in inventory, in the private member variable 'qtyOnHand'.*
//****************************************************************
void BookData::setQty (int newQuanityOnHand)
{ 
	qtyOnHand = newQuanityOnHand;  
}

//****************************************************************
// The getQty Member Function.						             *
// Returns an integer containing the private member variable     *
// 'qtyOnHand'.                                                  *
//****************************************************************
int BookData::getQty()	const		
{ 
	return qtyOnHand; 
}

//****************************************************************
// The setWholesale Member Function.							 *
// Stores a double, representing the wholesale cost of a book in *
// inventory, in the private member variable 'wholesale'.        *
//****************************************************************
void BookData::setWholesale(double newWholesale) 
{ 
	wholesale = newWholesale; 
}

//****************************************************************
// The getWholesale Member Function.						     *
// Returns a double containing the private member variable       *
// 'wholesale'.                                                  *
//****************************************************************
double BookData::getWholesale()	const	
{ 
	return wholesale; 
}

//****************************************************************
// The setRetail Member Function.							     *
// Stores a double, representing the retail price of a book in   *
// inventory, in the private member variable 'retail'.           *
//****************************************************************
void BookData::setRetail(double newRetail) 
{ 
	retail = newRetail; 
}

//****************************************************************
// The getRetail Member Function.						         *
// Returns a double containing the private member variable       *
// 'retail'.                                                     *
//****************************************************************
double BookData::getRetail() const	
{ 
	return retail; 
}

//****************************************************************
// The isEmpty Member Function.						             *
// Returns an integer value of 1, representing true, if the      *
// bookTile is empty, or returns an integer value of 0,          *
// representing false, if the bookTile is not empty.             *
//****************************************************************
int BookData::isEmpty(BookData &book)
{
	if (strcmp(book.getTitle(),"\0") == 0)	// the title is empty
	{
		return 1;	// true
	}
	else 
	{
		return 0;	// false
	}
}

//****************************************************************
// The removeBook Member Function.						         *
// Removes a book from the inventory file by setting its         *
// bookTitle to an empty c-string, and then writing the changes  *
// to the inventory file.                                        *
//****************************************************************
void BookData::removeBook(BookData &bookObj, FileIO &fileObj, int position)
{
	fileObj.open(); 
	bookObj.setTitle("\0");
	fileObj.write(bookObj,position);
	fileObj.close();
}
//****************************************************************
// The bookMatch Member Function.						         *
// Returns true if the c-string being searched for is in the     *
// bookTitle, but if no match is found, returns false.           *
//****************************************************************
bool BookData::bookMatch(BookData &book, char* strSearch)
{
	if (strstr(book.getTitle(), strSearch))	// they match
	{
		return true;
	}
	else
	{
		return false;
	}
}
