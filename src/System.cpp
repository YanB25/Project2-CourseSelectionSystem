#include "System.hpp"
#include <fstream>
#include <iostream>
using std::endl;
using std::cerr;
using std::ifstream;
using std::ofstream;

System::System() {
	if(!_loadDateFromFile()) {
		cerr << "Warning: an Error Happened When System is Loading Data" << endl;
	}
}

System::~System() {
	if (!_saveDataToFile()) {
		cerr << "Warning: an Error Happened When System is Saving Data" << endl;
	}
}

//TODO: maybe bug please double check this code
bool System::_loadDateFromFile(const filename_t& fn) {
	ifstream fin(fn);
	int numOfCourse;
	int numOfStu;
	int numOfTea;
	string name, id;
	fin >> numOfCourse;
	for (int i = 0; i < numOfCourse; ++i) {
		fin >> name >> id; //course name and id
		Course course(name, id);
		fin >> numOfStu >> numOfTea;
		for (int istu = 0; istu < numOfStu; ++istu) {
			fin >> name >> id; // stu name and id;
			course.addStudent(Student(name, id));
		}
		for (int itea = 0; itea < numOfTea; ++itea) {
			fin >> name >> id; // tea name and id
			course.addTeacher(Teacher(name, id));
		}
		_course_group.insert(course);
	}
	
	//if fin is invalid return false, otherwise return true 
	if(fin) return true;
	return false;
}

bool System::_saveDataToFile(const filename_t& fn) {
	ofstream fout(fn);
	fout << _course_group.size() << endl;
	for (const auto& course : _course_group.GetData()) {
		fout << course.GetName() << " " << course.GetId() << " ";
		fout << course.getStuNum() <<" " << course.getTeaNum() << endl;
		for (const auto& stu : course.getStuData()) {
			fout << stu.GetName() << " " << stu.GetId() << endl;
		}
		for (const auto& tea : course.getTeaData()) {
			fout << tea.GetName() << " " << tea.GetId() << endl;
		}
	}
	fout << endl;
	
	if(fout) return true;
	return false;
}







