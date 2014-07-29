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

// implementation file for the 'FileIO' class
#include "fileio.h"

//****************************************************************
// The FileIO constuctor              						     *
// Stores a c-string, represting the file name, in the private   *
// member variable 'binaryFileName', and is also used to access  *
// the open, fail, close, and clear methods of the private       * 
// member variable 'fileObj', which represents an fstream        * 
// object.														 *
// Checks for the existance of a file, if the file does not      *
// exist, it creates the file, clears all flags, and then closes *
// the file.									                 *
//****************************************************************
FileIO::FileIO(char* binaryFileName)
{
	// set the file name
	strcpy(fileName, binaryFileName);

	// open the file in input mode
	fileObj.open(fileName, ios::in | ios::binary);

	// if the file does not exist, create the file
	if(fileObj.fail())
	{
		fileObj.open(fileName, ios::out | ios::binary);
	}

	fileObj.close();	// close the file
	fileObj.clear();	// clear all flags, if any
}

//******************************************************************
// The open Member Function.									   *
// Used to access the open method of the private member variable   *
// 'fileObj', which represents an fstream object.                  *
// Opens the inventory file in binary mode for both input and	   *
// output.														   *
//******************************************************************
void FileIO::open()
{
	// open the inventory file for both input and output
	fileObj.open(fileName, ios::in | ios::out | ios::binary);
}	

//******************************************************************
// The read Member Function.									   *
// Used to access the read method of the private member variable   *
// 'fileObj', which represents an fstream object.                  *
// Reads the data stored in the inventory file into a BookData     *
// object.                                                         * 
//******************************************************************
void FileIO::read(BookData &bookObj, int position)
{
	// store the position in a long variable type
	long Lposition = position;	

	// seek the position to start reading from the file.
	fileObj.seekg(Lposition * sizeof(bookObj), ios::beg);

	// read the 'BookData' object data from the file
	fileObj.read(reinterpret_cast<char *>(&bookObj),sizeof(bookObj));
}

//******************************************************************
// The write Member Function.									   *
// Used to access the write method of the private member variable  *
// 'fileObj', which represents an fstream object.                  *
// Writes the data stored in a BookData Object into the inventory  *
// file.                                                           * 
//******************************************************************
void FileIO::write(BookData &book, int position)
{
	// store the position in a long variable type
	long Lposition = position;	

	// seek the position to start writing to the file
	fileObj.seekp(Lposition * sizeof(book),ios::beg);

	// write the 'BookData' object data to the file
	fileObj.write(reinterpret_cast<char *>(&book),sizeof(book));
}

//******************************************************************
// The close Member Function.									   *
// Used to access the close method of the private member variable  *
// 'fileObj', which represents an fstream object.                  *
// Closes the file and clears all flags, if any have been set.     *
//******************************************************************
void FileIO::close()
{
	fileObj.close();	// close the file
	fileObj.clear();	// clear all flags, if any
}

//******************************************************************
// The eof Member Function.									       *
// Used to access the eof method of the private member variable    *
// 'fileObj', which represents an fstream object.                  *                                                          * 
// Returns true if the private member fstream object 'fileObj'     *
// end of file is found, otherwise returns false.                  *                                                    * 
//******************************************************************
bool FileIO::eof()
{
	// return the 'end of file' status of the 'FileIO' object
	return fileObj.eof();
		
}