#include "FormatOutput.hpp"
#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::endl;
using std::ostream;
using std::left;
using std::setw;
using std::string;
//for more details, please refer to "frame.h"

void PrintAllCourse(const System& sys) {
	cout << endl;
	for (const auto& course : sys.GetCourse()) {
		cout << course.GetName() << "  " << course.GetId() << endl;
		cout << "student num: " << course.getStuNum() << " teacher num: " << course.getTeaNum() << endl;
		cout << "Student:" << endl;
		PrintTitle();
		for (const auto& stu : course.getStuData()) {
			cout << left << setw(NameLength) << stu.GetName() << stu.GetId() << endl;
		}
		cout << endl;
		cout << "Teacher:" << endl;
		PrintTitle();
		for (const auto& tea : course.getTeaData()) {
		cout << left << setw(NameLength) << tea.GetName() << tea.GetId() << endl;
		}
		cout << endl << endl;
	}
}

void PrintInstroduction() {
	cout << "\tWelcome to Course Selection System" << endl;
	cout << "\tuse <help> to get tutorial" << endl;
	cout << "\tuse <quit> to exit" << endl;
}

void PrintHelp() {
	 cout << "\t <add crs> to add a course" << endl;
	 cout << "\t <rm crs> to delete a course" << endl;
	 cout << "\t <add (stu | tea)> to join a student/teacher into a course" << endl;
	 cout << "\t <rm (stu | tea)> to delete a student/teacher from a course" << endl;
	 cout << "\t <prt crs> to print the information about a course" << endl;
	 cout << "\t <prta> to print all the information" << endl;
	 cout << endl;
}

//void PrintOneBook(ostream& os, const Library& lib, const name_t& name) {
//	PrintTitle(os);
//	auto info = lib.GetBookInfo(name);
//	for (const auto& book : info) {
//		PrintBookInOneLine(os, book);
//	}
//	os << endl;
//}

//TODO:
void PrintCourse(const Course& crs) { }


