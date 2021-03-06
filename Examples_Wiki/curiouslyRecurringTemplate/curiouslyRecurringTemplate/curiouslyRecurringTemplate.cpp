// curiouslyRecurringTemplate.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Derived class derives from Base class template using Derived itself as template argument;
// 
// Usages (see slides):
//	- static polymorphism, e.g., deign a class so that any of its derived class is singleton;
//	- object counter: counters of objects of different classes;
//	- polymorphic chaining;
//	- polymorphic copy construction;

template<class T>
class Base {

public:
	// methods within Base can use template to access members of Derived;
	//
	// non-static function;
	void nonStaticFunc() {
		static_cast<T*> (this)->nonStaticSubFunc();
	}

	// static function
	static void staticFunc(){
		T::staticSubFunc();
	}
};

class Derived1 : public Base<Derived1>{
public:
	void nonStaticSubFunc() {
		cout << "derived 1 non-static sub-function" << endl;
	}

	static void staticSubFunc() {
		cout << "derived 1 static sub-function" << endl;
	}
};

class Derived2 : public Base<Derived2> {
public:
	void nonStaticSubFunc() {
		cout << "derived 2 non-static sub-function" << endl;
	}

	static void staticSubFunc() {
		cout << "derived 2 non-static sub-function" << endl;
	}
};

int main()
{
	Derived1 d1;
	d1.nonStaticFunc();
	Derived1::staticFunc();

	Derived2 d2;
	d2.nonStaticFunc();
	Derived2::staticFunc();

	// this also works
	Base<Derived1>* b1 = new Base<Derived1>();
	b1->nonStaticFunc();
	Base<Derived1>::staticFunc();

    return 0;
}

