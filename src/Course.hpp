#ifndef _YB_COURSE_HPP_
#define _YB_COURSE_HPP_

#include "Persons.hpp"
//"tea" stands for Teacher
//"stu" stands for Student
//class Group is defined in "Persons.hpp"
class Course : public Object {
public:
	typedef Group stu_group_t;
	typedef Group tea_group_t;
	typedef Course self;
	
	~Course() = default;
	//TODO:start here:
	bool addStudent(const Student& stu);
	bool addTeacher(const Student& tea);
	void clearStudent() { _stu_group.clear(); }
	void clearTeacher() { _tea_group.clear(); }
	auto findStudent(const Student& stu) const { return _stu_group.find(stu); }
	auto findTeacher(const Teacher& tea) const { return _stu_group.find(tea); }
	bool studentIsIn(const Student& stu) const { return _stu_group.isIn(stu); }
	bool teacherIsIn(const Teacher& tea) const { return _tea_group.isIn(tea); }
	bool removeStudent();
	bool removeTeacher();
private:
	stu_group_t _stu_group;
	tea_group_t _tea_group;
};
#endif
