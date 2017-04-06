#include "System.hpp"

bool System::joinStuToCourse(const Student& stu, Course& crs) {
	return crs.insert(stu):
}

bool System::joinTeaToCourse(const Teacher& tea, Course& crs) {
	
bool removeStuFromCourse(const Student& stu, Course& crs);
bool removeTeaFromCourse(const Teacher& tea, Course& crs);
bool teaIsInCourse(const Teacher& tea, const Course& crs);
bool stuIsInCourse(const Student& stu, const Course& crs);
