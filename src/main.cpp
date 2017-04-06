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
	c.addStudent(s);
	cout << c.studentIsIn(s) << endl;
	c.addTeacher(t);
	cout << c.teacherIsIn(t) << endl;
	cout << c.addStudent(s) << endl;
	cout << c.removeStudent(s) << endl;
	c.clearTeacher();
	cout << c.teacherIsIn(t) << endl;
	cout << c.removeTeacher(t) << endl;
	return 0;
}
