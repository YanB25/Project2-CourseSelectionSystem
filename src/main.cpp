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
//	System sys;
//	Course c("sc", "001");
//	Student s("yb", "16337269");
//	sys.addCourse(c);
//	auto& c1 = sys.GetCourse("001");
//	cout << sys.joinStuToCourse(s, c1) << endl;
//	cout << sys.joinStuToCourse(s, c1) << endl;
////	cout << c1.addStudent(s) << endl;
////	cout << c1.studentIsIn(s) << endl;
//	for (auto& crs : sys.GetCourse()) {
//		cout << "ok" << endl;
//		cout << crs.getStuNum() << endl;
//		cout << crs.getTeaNum() << endl;
//	}
	System sys;
	auto& cs = sys.GetCourse("001");
	Teacher t1("yangyh", "00000001");
	sys.joinTeaToCourse(t1, cs);
	return 0;
}
