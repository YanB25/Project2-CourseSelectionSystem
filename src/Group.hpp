//whether this class is necessary remains to be discusssed
#ifndef _YB_GROUP_HPP_
#define _YB_GROUP_HPP_

//class Group is a template
//it can be a group of students/teachers/courses
//it is an encapsulation of std::set
template <typename T>
class Group {
public:
	typedef set<T> group_t;
	typedef typename group_t::iterator iter;
	typedef typename group_t::const_iterator const_iter;
	
	Group() = default;
	~Group() = default;
	
	bool insert(const T& item) { return _group.insert(item).second; }
	bool erase(const T& item) {
		if (find(item) == _group.end()) return false;
		_group.erase(item);
		return true;
	}
	//TODO:maybe bug: should I add const here? what will happen?
	iter find(const T& item) { return _group.find(item); }
	const_iter find(const T& item) const { return _group.find(item); }
	bool isIn(const T& item) const { return _group.find(item) != _group.end(); }
	void clear() { _group.clear(); }
	//it can only return 1 or 0 because items in <set> are unique
	size_t count(const T& item) { return _group.count(item); }
	
	size_t size() const { return _group.size(); }
	bool empty() const { return _group.empty(); }
	
	group_t& GetData() { return _group; }
	const group_t& GetData() const { return _group; }
private:
	group_t _group;
};
#endif
