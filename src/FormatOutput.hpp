#ifndef _FRAME_H_
#define _FRAME_H_

#include <iostream>
#include <iomanip>
#include "System.hpp"
#include "Course.hpp"
using std::ostream;
using std::setw;
using std::left;
using std::endl;
using std::cout;
using std::cerr;
typedef string name_t;
//the constant below are for format output.
const int NameLength = 20; //how long does the name of a book takes (see func: void PrintBookInOneLine(...))
const int LengthOfLine = 30; //how long does the split-line takes (see func: void PrintTitle() )
const string FileName = "BookSystemData";

//used to print error message
//s means error message
inline void PrintError(const string& s) {
	cerr << s << endl;
}

//print all the book in the library
void PrintAllCourse(const System& sys);

void PrintHelp();
void PrintInstroduction();
inline void PrintPromt() {
	cout << ">>> " ;
}

inline void PrintPromtForInput() {
	cout << "... ";
}

//print the title(head) of the table
inline void PrintTitle() {
	cout << left << setw(NameLength) << "Name" << "Id" << endl;
	cout << string(LengthOfLine, '-') << endl;
}


void PrintCourse(const Course& crs);
//when we want to get all the infomation about the library, we use print-table
//the output may take up many lines
//inline void PrintTable(const System& sys) {
//	
//}


//function to do the real work, print information of the book in one line
//inline void PrintBookInOneLine(ostream& os, const Book& book) {
//	os << left << setw(NameLength) << book.GetName() << (book.GetState() == Borrowed ? "Borrowed" : "Available") << endl; 
//}

//print a series of books with the same name
//the output may take up one line (when there's only one book has this name)
//or may take up many lines
//void PrintOneBook(ostream& os, const Library& lib, const name_t& name); 

//print the location of errors
//it would be like "       ^"
//the caret point to the word that is an error
//void inline PrintErrorLocation(ostream& os, size_t pos) {
//	os << string(pos, ' ') << '^' << endl;
//}
#endif
