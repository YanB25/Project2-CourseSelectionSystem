/*
by 颜彬
class 7
student's id 16337269
github: YanB25

*/
#include "Course.hpp"
#include "Person.hpp"
#include "System.hpp"
#include "FormatOutput.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::vector;
using std::find;
using std::istringstream;
using std::regex;
using std::smatch;


template <typename T>
T InputNameAndId(const string& s = "") {
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
T InputId(const string& s = "") {
	string id;
	cout << s + " Id: " << endl;
	PrintPromtForInput();
	getline(cin, id);
	return T("Unknown", id);
}

Course InputCourseById() {
	string crs_id;
	cout << "Course Id: " << endl;
	PrintPromtForInput();
	getline(cin, crs_id);
	return Course("Unknown", crs_id);
}

int main() {
	System sys; //the system
	PrintInstroduction();
	string first_order;//the first words that the user inputs
	string second_order;//the second words that the user inputs
	
	string input;
	string name;
	string id;
	string crs_id;
//	//regex
//	regex checkOrder(OrderPattern);
//	regex checkAll(validPattern);
//	smatch results;
	
	while (true) {
		PrintPromt(); //print ">>> "
		//when we simply touch "Enter",we creat a new line 
		if (cin.peek() == '\n') {
			cin.get();
			continue;
		}
		
		//get input, order and name
		getline(cin, input);
		istringstream sin(input);
		sin >> first_order;
		//discard spaces
		while (sin.peek() == ' ') sin.get();
//		getline(sin, name);
		
		//check the syntax
//		if (!regex_search(input, results, checkOrder)) {
//			//print a caret to indicate where the error happened
//			//it is like "     ^"
//			PrintError(cout, "Syntax Error: invalid order. use <help> to get help");
//			continue;
//		} else if (!regex_search(input, results, checkAll)) {
//			PrintErrorLocation(cout, order.length() + 5);
//			PrintError(cout, "Syntax Error: invalid parameter, please check both number and format");
//			continue;
//		} 
		
		//work
		if (first_order == "quit") {
			return 0;
		}
		
		else if (first_order == "help") {
			PrintHelp();
		} 
		
		else if (first_order == "prta") {
			PrintAllCourse(sys);
		}
		else {
			sin >> second_order;
			if (first_order == "add") {
				if (second_order == "crs") {
					Course c = InputNameAndId<Course>("Course");
					if (!sys.addCourse(c)) {
						PrintError("RunTime Error: Fail to add this course");
						continue;
					}
				} else {
					Person p = InputNameAndId<Person>("Person");
					Course crs = InputCourseById();
					if (!sys.hasCourse(crs.GetId())) {
						PrintError("RunTime Error: can not find this course");
					}
					auto& course = sys.GetCourse(crs);
					if (second_order == "stu") {
						if (!sys.joinStuToCourse(Student(p), course)) {
							PrintError("RunTime Error: can not join this student");
						}
					} else {
						if (!sys.joinTeaToCourse(Teacher(p), course)) {
							PrintError("RunTime Error: can not join this teacher");
						}
					}
				}
			} else if (first_order == "rm") {
				if (second_order == "crs") {
					Course crs = InputCourseById();
					if (!sys.hasCourse(crs.GetId())) {
						PrintError("RuntTime Error: can not find the course");
					}
					auto& course = sys.GetCourse(crs);
					if (!sys.removeCourse(course)) {
						PrintError("RuntTime Error: cannot remove course");
					}
				} else {
					Person p = InputId<Person>("Person");
					Course crs = InputCourseById();
					if (!sys.hasCourse(crs.GetId())) {
						PrintError("RunTime Error: can not find the course");
					}
					auto& course = sys.GetCourse(crs);
					if (second_order == "stu") {
						if (!sys.removeStuFromCourse(Student(p), course)) {
							PrintError("RunTime Error: can not remove student");
						}
					} else {
						if (!sys.removeTeaFromCourse(Teacher(p), course)) {
							PrintError("RunTime Error: can not remove teacher");
						}
					}
				}
			} else if (first_order == "prt") {
				if (second_order == "crs") {
					Course crs = InputCourseById();
					if (!sys.hasCourse(crs.GetId())) {
						PrintError("RunTimeError: cannot find this course");
					}
					PrintCourse(sys.GetCourse(crs));
				}
			
			}
		}
	}
		
	return 0;
}


