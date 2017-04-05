//define class for Student and Teacher
#ifndef _YB_PERSONS_HPP_
#define _YB_PERSONS_HPP_

#include <set>
#include "Object.hpp"
using std::set;

class Person : public Object { };

class Student : public Person {
public:
	~Student() = default;
};

class Teacher : public Person {
public:
	~Teacher() = default;
};

class Group {
public:
	typedef set<Person> group_t;
	typedef Group self;
	typedef group_t::iterator iter;
	typedef group_t::const_iterator const_iter;
	Group() = default;
	Group(const Group& rhs) = delete;
	
	bool insert(const Person& person) { return _group.insert(person).second; }
	bool erase(const Person& person) {
		if (find(person) == _group.end()) return false;
		_group.erase(person);
		return true;
	}
	//TODO:maybe bug: should I add const here? what will happen?
	iter find(const Person& person) { return _group.find(person); }
	const_iter find(const Person& person) const { return _group.find(person); }
	bool isIn(const Person& person) const { return _group.find(person) != _group.end(); }
	void clear() { _group.clear(); }
	//it can only return 1 or 0 because items in <set> are unique
	size_t count(const Person& person) { return _group.count(person); }
	
	size_t size() const { return _group.size(); }
	bool empty() const { return _group.empty(); }
private:
	group_t _group;
};

#endif
