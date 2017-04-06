#ifndef _YB_COURSE_HPP_
#define _YB_COURSE_HPP_

#include "Person.hpp"
#include "Group.hpp"
//"tea" stands for Teacher
//"stu" stands for Student
//class Group is defined in "Persons.hpp"
const size_t MAX_STU = 100;
const size_t MAX_TEA = 10;

class Course : public Object {
public:
	typedef Group<Student> stu_group_t;
	typedef Group<Teacher> tea_group_t;
	typedef Course self;
	
	Course() = delete;
	Course(const name_t& name, const id_t& id) : Object(name, id) { }
	~Course() = default;
	//return false if stu/tea has been in the Course, or the course if full, then do nothing
	//return true otherwise and add stu/tea in group
	bool addStudent(const Student& stu);
	bool addTeacher(const Teacher& tea);
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
	
	//return true if successfully set the num
	bool setMaxStu(size_t new_stu);
	size_t getMaxStu() const { return _max_stu; }
	bool setMaxTea(size_t new_tea);
	size_t getMaxTea() const { return _max_tea; }
	size_t getStuNum() const { return _stu_group.size(); }
	size_t getTeaNum() const { return _tea_group.size(); }
	
	auto& getStuData() const { return _stu_group.GetData(); }
	auto& getTeaData() const { return _tea_group.GetData(); }
private:
	stu_group_t _stu_group;
	tea_group_t _tea_group;
	size_t _max_stu = MAX_STU;
	size_t _max_tea = MAX_TEA;
};
#endif
