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
using std::cin;
typedef string name_t;
//the constant below are for format output.
const int NameLength = 20; 
const int LengthOfLine = 45; 

//used to print error message
//s means error message

inline void OutputHelper(const string& lhs, const string& rhs) {
	cout << left << setw(NameLength) << lhs << rhs << endl;
}

inline void PrintError(const string& s) {
	cerr << s << endl;
}

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
	cout << endl;
	cout << left << setw(NameLength) << "Name" << left << setw(NameLength) << "Id" << "State" << endl;
	cout << string(LengthOfLine, '-') << endl;
}

inline void PrintTitle2() {
	cout << endl;
	OutputHelper("Name", "Id");
	cout << string(LengthOfLine, '-') << endl;
}

void PrintCourse(const Course& crs);

template <typename T>
T InputNameAndId(const string& s) {
	string name, id;
	cout << s + " Name: " << endl;
	PrintPromtForInput();
	getline(cin, name);
	cout << s + " Id: " << endl;
	PrintPromtForInput();
	getline(cin, id);
	T ret(name, id);
	return ret;
}

template <typename T>
T InputId(const string& s) {
	string id;
	cout << s + " Id: " << endl;
	PrintPromtForInput();
	getline(cin, id);
	return T("Unknown", id);
}

Course InputCourseById();

void PrintHisCourse(const System& sys, const Teacher& tea);
void PrintHisCourse(const System& sys, const Student& stu);


#endif
