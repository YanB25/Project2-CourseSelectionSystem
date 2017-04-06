//an abstract base class for Object
//class Student, class Teacher,class Course are all object

#ifndef _YB_OBJECT_HPP_
#define _YB_OBJECT_HPP_

#include <string>
using std::string;

class Object {
public:
	typedef string name_t;
	typedef string id_t;
	typedef Object self;
	
	Object() = delete;
	Object(name_t name, id_t id) : _name(name), _id(id) { }
	virtual ~Object() = 0;
	
	bool operator<(const self& rhs) const { return _id < rhs._id; }
	bool operator>(const self& rhs) const { return _id > rhs._id; }
	bool operator==(const self& rhs) const { return _id == rhs._id; }
	bool operator!=(const self& rhs) const { return _id != rhs._id; }
	
	name_t GetName() const { return _name; }
	id_t GetId() const { return _id; }
	void SetName(const name_t& new_name) { _name = new_name; }
	void SetId(const id_t& new_id) { _id = new_id; }
	
private:
	name_t _name;
	id_t _id;
};
Object::~Object() { }
#endif
