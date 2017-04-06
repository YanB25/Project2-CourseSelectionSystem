#include "Course.hpp"
#include "Person.hpp"
#include "System.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main() {
	Student s("yb", "16337269");
	Teacher t("yyh", "16337270");
	Course c("cs", "001"); 
	Course c2("cs2", "002");
//	c.addStudent(s);
//	cout << c.studentIsIn(s) << endl;
//	c.addTeacher(t);
//	cout << c.teacherIsIn(t) << endl;
//	cout << c.addStudent(s) << endl;
//	cout << c.removeStudent(s) << endl;
//	c.clearTeacher();
//	cout << c.teacherIsIn(t) << endl;
//	cout << c.removeTeacher(t) << endl;
	System sys;
	sys.addCourse(c);
	sys.joinStuToCourse(s, c);
	sys.joinTeaToCourse(t, c);
	cout << sys.hasCourse(c) << endl;
	cout << sys.stuIsInCourse(s, c) << endl;
	cout << sys.hasCourse(c2) << endl;
	cout << sys.stuIsInCourse(s, c2) << endl;
	cout << sys.removeStuFromCourse(s, c) << endl;
	cout << sys.removeStuFromCourse(s, c) << endl;
	cout << sys.removeStuFromCourse(s, c2) << endl;
	cout << sys.hasCourse(c) << endl;
	cout << sys.hasCourse(c2) << endl;
	auto course = sys.GetCourse("001");
	sys.removeCourse(course);
	cout << sys.hasCourse(course) << endl;
	return 0;
}
