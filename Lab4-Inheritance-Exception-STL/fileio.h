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

// specification file for the 'FileIO' class
#ifndef FILEIO_H
#define FILEIO_H

#include <fstream>
#include <iostream>
#include "bookdata.h"
using namespace std;

const int F_SIZE = 31;			// constant for c-string array size

// FileIO class declaration

class FileIO
{
private:
	 char fileName[F_SIZE];							// the file name
	 fstream fileObj;								// the fstream object
public:
	FileIO		(char* binaryFileName);				// the constructor
	void  open  ();									// opens the file
	void  read  (BookData &bookObj, int position);	// reads data from the file
	void  write (BookData &bookObj, int position);	// writes data to the file
	void  close ();									// closes the file
	bool  eof	();									// checks for the end of the file
};

#endif