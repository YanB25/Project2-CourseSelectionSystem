//define class for Student and Teacher
#ifndef _YB_PERSON_HPP_
#define _YB_PERSON_HPP_

#include <set>
#include "Object.hpp"
using std::set;

class Person : public Object {
public:
	Person(const name_t name, const id_t& id) : Object(name, id) { }
	virtual ~Person() = default;
};

class Student : public Person {
public:
	Student(const name_t& name, const id_t& id) : Person(name, id) { } 
	Student(const Person& p) : Student(p.GetName(), p.GetId()) { }
	virtual ~Student() = default;
};

class Teacher : public Person {
public:
	Teacher(const name_t& name, const id_t& id) : Person(name, id) { }
	Teacher(const Person& p) : Teacher(p.GetName(), p.GetId()) { }
	virtual ~Teacher() = default;
};

#endif
