#include "Course.hpp"
//see Course.hpp
bool Course::setMaxStu(size_t num) {
	if (num <= 0) {
		return false;
	}
	_max_stu = num;
	return true;
}

bool Course::setMaxTea(size_t num) {
	if (num <= 0) {
		return false;
	}
	_max_tea = num;
	return true;
}

bool Course::addStudent(const Student& stu) { 
	if (_stu_group.size() <= _max_stu) {
		return _stu_group.insert(stu);
	}
	return false;
}

bool Course::addTeacher(const Teacher& tea) { 
	if (_tea_group.size() <= _max_tea) {
		return _tea_group.insert(tea); 
	}
	return false;
}
