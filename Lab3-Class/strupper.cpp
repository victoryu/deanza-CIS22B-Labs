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
#include <cctype>

//********************************************
// strUpper function                         *
//********************************************
void strUpper(char* str)
{
	while( *str != 0 )
	{
		*str = toupper(*str);
		str++;
	}
}