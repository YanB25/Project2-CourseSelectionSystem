//for more, see IOHelper.hpp
#include "IOHelper.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include "Course.hpp"
using std::cout;
using std::endl;
using std::ostream;
using std::left;
using std::setw;
using std::string;
using std::cin;

void PrintAllCourse(const System& sys) {
	cout << endl;
	PrintTitle2();
	for (const auto& course: sys.GetCourse()) {
		OutputHelper(course.GetName(), course.GetId());
	}
	cout << endl << endl;
	for (const auto& course : sys.GetCourse()) {
		PrintCourse(course);
		cout << endl;
	}
}

void PrintInstroduction() {
	cout << "\tWelcome to Course Selection System" << endl;
	cout << "\tuse <help> to get tutorial" << endl;
	cout << "\tuse <quit> to exit" << endl;
}

void PrintHelp() {
	 cout << "\t<add crs> to add a course" << endl;
	 cout << "\t<add (stu | tea)> to join a student/teacher into a course" << endl;
	 cout << "\t<rm crs> to delete a course" << endl;
	 cout << "\t<rm (stu | tea)> to delete a student/teacher from a course" << endl;
	 cout << "\t<prta> to print all the information" << endl;
	 cout << "\t<prt crs> to print the information about a course" << endl;
	 cout << endl;
}


void PrintCourse(const Course& course) {
	cout << endl;
	cout << "Course: " << course.GetName() << "  " << course.GetId() << endl;
	PrintTitle();
	for (const auto& stu : course.getStuData()) {
		cout << left << setw(NameLength) << stu.GetName() << left << setw(NameLength) << stu.GetId() << "Student" << endl;
	}
	cout << endl;
	for (const auto& tea : course.getTeaData()) {
	cout << left << setw(NameLength) << tea.GetName() << left << setw(NameLength) << tea.GetId() << "Teacher" << endl;
	} 
}

Course InputCourseById() {
	string crs_id;
	cout << "Course Id: " << endl;
	PrintPromtForInput();
	getline(cin, crs_id);
	return Course("Unknown", crs_id);
}


void PrintHisCourse(const System& sys, const Student& stu) {
	PrintTitle2();
	for (const auto& course : sys.GetCourse()) {
		if (course.studentIsIn(stu)) {
			OutputHelper(course.GetName(), course.GetId());
		}
	}
}

void PrintHisCourse(const System& sys, const Teacher& tea) {
	PrintTitle2();
	for (const auto& course : sys.GetCourse()) {
		if (course.teacherIsIn(tea)) {
			OutputHelper(course.GetName(), course.GetId());
		}
	}
}






