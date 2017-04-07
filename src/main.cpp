/*
by 颜彬
class 7
student's id 16337269
github: YanB25

*/
#include "Course.hpp"
#include "Person.hpp"
#include "System.hpp"
#include "IOHelper.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istringstream;
using std::regex;
using std::smatch;

const string Pattern("^help|quit|prta|(add|rm|prt) (stu|tea|crs)$");

const string SYNTAX_ERROR("Syntax Error: invalid order. use <help> to get help");

const string FAIL_TO("Runtime Error: Fail to ");
const string FAIL_TO_REMOVE = FAIL_TO + "Remove ";
const string FAIL_TO_ADD = FAIL_TO + "Add ";
const string FAIL_TO_FIND_COURSE = FAIL_TO + "Find This Course";
const string FAIL_TO_REMOVE_STUDENT = FAIL_TO_REMOVE + "Student";
const string FAIL_TO_REMOVE_TEACHER = FAIL_TO_REMOVE + "Teacher";
const string FAIL_TO_REMOVE_COURSE = FAIL_TO_REMOVE + "Course";
const string FAIL_TO_ADD_STUDENT = FAIL_TO_ADD + "Student";
const string FAIL_TO_ADD_TEACHER = FAIL_TO_ADD + "Teacher";
const string FAIL_TO_ADD_Course = FAIL_TO_ADD + "Course";

int main() {
	System sys; //the system
	PrintInstroduction();
	string first_order;//the first words that the user inputs
	string second_order;//the second words that the user inputs
	
	string input;
	string name;
	string id;
	string crs_id;
	//regex
	regex checkValidInput(Pattern);
	smatch results;
	
	while (true) {
		PrintPromt(); //print ">>> "
		//when we simply touch "Enter",we creat a new line 
		if (cin.peek() == '\n') {
			cin.get();
			continue;
		}
		
		getline(cin, input);
		istringstream sin(input);
		sin >> first_order;
		//discard spaces
		while (sin.peek() == ' ') sin.get();
		
		//check the syntax
		if (!regex_search(input, results, checkValidInput)) {
			PrintError(SYNTAX_ERROR);
			continue;
		}
		
				
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
						PrintError(FAIL_TO_FIND_COURSE);
						continue;
					}
				} else {
					Person p = InputNameAndId<Person>("Person");
					Course crs = InputCourseById();
					if (!sys.hasCourse(crs.GetId())) {
						PrintError(FAIL_TO_FIND_COURSE);
					}
					auto& course = sys.GetCourse(crs);
					if (second_order == "stu") {
						if (!sys.joinStuToCourse(Student(p), course)) {
							PrintError(FAIL_TO_ADD_STUDENT);
						}
					} else {
						if (!sys.joinTeaToCourse(Teacher(p), course)) {
							PrintError(FAIL_TO_ADD_TEACHER);
						}
					}
				}
			} else if (first_order == "rm") {
				if (second_order == "crs") {
					Course crs = InputCourseById();
					if (!sys.hasCourse(crs.GetId())) {
						PrintError(FAIL_TO_FIND_COURSE);
					}
					auto& course = sys.GetCourse(crs);
					if (!sys.removeCourse(course)) {
						PrintError(FAIL_TO_REMOVE_COURSE);
					}
				} else {
					Person p = InputId<Person>("Person");
					Course crs = InputCourseById();
					if (!sys.hasCourse(crs.GetId())) {
						PrintError(FAIL_TO_FIND_COURSE);
					}
					auto& course = sys.GetCourse(crs);
					if (second_order == "stu") {
						if (!sys.removeStuFromCourse(Student(p), course)) {
							PrintError(FAIL_TO_REMOVE_STUDENT);
						}
					} else {
						if (!sys.removeTeaFromCourse(Teacher(p), course)) {
							PrintError(FAIL_TO_REMOVE_TEACHER);
						}
					}
				}
			} else if (first_order == "prt") {
				if (second_order == "crs") {
					Course crs = InputCourseById();
					if (!sys.hasCourse(crs.GetId())) {
						PrintError(FAIL_TO_FIND_COURSE);
					}
					else {
						PrintCourse(sys.GetCourse(crs));
					}
				} else {
					Person p = InputId<Person>("Person");
					if (second_order == "stu") {
						PrintHisCourse(sys, Student(p));
					} else {
						PrintHisCourse(sys, Teacher(p));
					}
				}	
			}
		}
	}
		
	return 0;
}


