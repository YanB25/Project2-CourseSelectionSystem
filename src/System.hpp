#ifndef _YB_SYSTEM_HPP_
#define _YB_SYSTEM_HPP_

#include <set>
#include <string>
#include "Person.hpp"
#include "Course.hpp"
using std::set;
using std::string;

class System {
public:
	typedef Group<Course> course_group_t;
	typedef System self;
	typedef string id_t;
	
	//TODO:important:构造函数和析构函数需要完成文件IO的工作。
	//TODO:start here
	System();
	System(const System&) = delete;
	~System() = default;
	
	bool hasCourse(const Course& crs) const { return _course_group.isIn(crs); }
	const Course& GetCourse(const id_t& crs_id) { return *_course_group.find(Course("Unknown", crs_id)); }
	
	bool joinStuToCourse(const Student& stu, const Course& crs);
	bool joinTeaToCourse(const Teacher& tea, const Course& crs);
	bool removeStuFromCourse(const Student& stu, const Course& crs);
	bool removeTeaFromCourse(const Teacher& tea, const Course& crs);
	bool teaIsInCourse(const Teacher& tea, const Course& crs);
	bool stuIsInCourse(const Student& stu, const Course& crs);
	//TODO:not finished
	
private:
	course_group_t _course_group;
};
#endif
