#ifndef _YB_SYSTEM_HPP_
#define _YB_SYSTEM_HPP_

#include <set>
#include <string>
#include "Person.hpp"
#include "Course.hpp"
using std::set;
using std::string;
//file to save and load
const string filename("../data/CourseDateInSystem");
class System {
public:
	typedef Group<Course> course_group_t;
	typedef System self;
	typedef string id_t;
	typedef string filename_t;
	
	System();
	System(const System&) = delete;
	~System();
	
	bool hasCourse(const Course& crs) const { return _course_group.isIn(crs); }
	bool hasCourse(const id_t& crs_id) const { return _course_group.isIn(Course("Unknown", crs_id)); }
	Course& GetCourse(const id_t& crs_id) { return const_cast<Course&>(*_course_group.find(Course("Unknown", crs_id))); }
	Course& GetCourse(const Course& crs) { return const_cast<Course&>(*_course_group.find(crs)); }
	
	bool joinStuToCourse(const Student& stu, Course& crs) { return _course_group.isIn(crs) && crs.addStudent(stu); }
	bool joinTeaToCourse(const Teacher& tea, Course& crs) { return _course_group.isIn(crs) && crs.addTeacher(tea); }
	bool removeStuFromCourse(const Student& stu, Course& crs) { return _course_group.isIn(crs) && crs.removeStudent(stu); }
	bool removeTeaFromCourse(const Teacher& tea, Course& crs) { return _course_group.isIn(crs) && crs.removeTeacher(tea); }
	bool teaIsInCourse(const Teacher& tea, const Course& crs) { return crs.teacherIsIn(tea); }
	bool stuIsInCourse(const Student& stu, const Course& crs) { return crs.studentIsIn(stu); }
	
	bool addCourse(const Course& crs) { return _course_group.insert(crs); }
	bool removeCourse(const Course& crs) { return _course_group.erase(crs); }
	const auto& GetCourse() const { return _course_group.GetData(); }
private:
	course_group_t _course_group;
	bool _saveDataToFile(const filename_t& fn = filename);
	bool _loadDateFromFile(const filename_t& fn = filename);
};
#endif
