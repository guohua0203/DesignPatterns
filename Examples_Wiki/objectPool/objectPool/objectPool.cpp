// objectPool.cpp : Defines the entry point for the console application.
//

#include "header.h"

// ObjectPool has a vector of Object;
// Client use ObjectPool to acquire and release object;
// Object has a member variable indicating if the object is in use;
//
// If lock is involded in searching through Object Pool, remember to
// release the lock before any return, e.g, in the searching loop;
// Refer the slides;

class Object {
	int m_data;
	bool m_isInUse;
public:
	Object(int data) : m_data(data), m_isInUse(false) {};

	void setIsInUse(bool isInUse) {
		m_isInUse = isInUse;
	}

	bool isInUse() {
		return m_isInUse;
	}

	int data() {
		return m_data;
	}

	bool operator == (Object& rhs){
		bool res = this->m_data == rhs.m_data;
		return res;
	}

	//void operator = (Object& rhs) {
	//	this->m_data = rhs.data();
	//}
};

class ObjectPool {
	vector<Object> m_objects;
public:
	Object acquireObject(int data) {
		for (Object& o : m_objects) {
			bool isEqual = o.data() == data;
			bool isInUse = o.isInUse();

			if (!isInUse && isEqual) {
				return o;
			}
		}

		Object res(data);
		m_objects.push_back(res);
		return res;
	}

	void releaseObject(Object& obj) {
		for (Object& o : m_objects) {
			if (obj == o) {
				obj.setIsInUse(false);
				return;
			}
		}
	}
};


int main()
{
	ObjectPool op;
	Object o1 = op.acquireObject(2);
	o1.setIsInUse(true);

	op.releaseObject(o1);

	Object o2 = op.acquireObject(2);

    return 0;
}

