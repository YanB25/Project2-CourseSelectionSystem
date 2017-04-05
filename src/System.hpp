#ifndef _YB_SYSTEM_HPP_
#define _YB_SYSTEM_HPP_

#include <set>
#include "Persons.hpp"
using std::set;

class System {
public:
	//type for a group of students and teachers
	typedef set<Student> stu_group_t;
	typedef set<Teacher> tea_group_t;
	
	System() { };
	//TODO:not finished
};
#endif
