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
const int STR_SIZE  = 51; // represents the maximum string size

// BookData structure declaration.

struct BookData
{
	char	bookTitle[STR_SIZE];	// stores the tile of a book
	char	isbn	 [STR_SIZE];	// stores the isbn number of a book
	char	author	 [STR_SIZE];	// stores the book author's name 
	char	publisher[STR_SIZE];	// stores the book publisher's name 
	char	dateAdded[STR_SIZE];	// stores the date a book was added into inventory
	int		qtyOnHand;				// stores the quantity on hand of a book
	double	wholesale;				// stores the wholesale price of a book
	double	retail;					// stores the retail price of a book
};

// Function prototypes
void setTitle(char* , int);
void setISBN(char* , int);
void setAuthor(char* , int);
void setPub(char* , int);
void setDateAdded(char* , int);
void setQty(int , int);
void setWholesale(double , int);
void setRetail(double , int);
int isEmpty(int);
void removeBook(int);
