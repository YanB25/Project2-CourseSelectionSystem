#ifndef _YB_COURSE_HPP_
#define _YB_COURSE_HPP_

#include "Person.hpp"
#include "Group.hpp"
//"tea" stands for Teacher
//"stu" stands for Student
//class Group is defined in "Persons.hpp"
class Course : public Object {
public:
	typedef Group<Student> stu_group_t;
	typedef Group<Teacher> tea_group_t;
	typedef Course self;
	
	Course() = delete;
	Course(const name_t& name, const id_t& id) : Object(name, id) { }
	~Course() = default;
	//return false if stu/tea has been in the Course, then do nothing
	//return true otherwise and add stu/tea in group
	bool addStudent(const Student& stu) { return _stu_group.insert(stu); }
	bool addTeacher(const Teacher& tea) { return _tea_group.insert(tea); }
	void clearStudent() { _stu_group.clear(); }
	void clearTeacher() { _tea_group.clear(); }
	//return an iterator as std::find do
	auto findStudent(const Student& stu) const { return _stu_group.find(stu); }
	auto findTeacher(const Teacher& tea) const { return _tea_group.find(tea); }
	bool studentIsIn(const Student& stu) const { return _stu_group.isIn(stu); }
	bool teacherIsIn(const Teacher& tea) const { return _tea_group.isIn(tea); }
	//return false if stu/tea is not in the course, then do nothing
	//return true otherwise, then remove stu/tea
	bool removeStudent(const Student& stu) { return _stu_group.erase(stu); }
	bool removeTeacher(const Teacher& tea) { return _tea_group.erase(tea); }
private:
	stu_group_t _stu_group;
	tea_group_t _tea_group;
};
#endif
