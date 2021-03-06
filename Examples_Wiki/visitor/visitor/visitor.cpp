// visitor.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Visitor has visit method;
// Element accept visitor where Visitor's visit method is called;

class Engine;

class Visitor {
public:
	virtual void visit(Engine* e) = 0;
};

class ViewVisitor : public Visitor {
public:
	void visit(Engine* e) override {
		cout << "view Engine e" << endl;
	}
};

class DoVisitor : public Visitor {
public:
	void visit(Engine* e) override {
		cout << "start Engine e" << endl;
	}
};

class Engine {
public:
	void accept(Visitor* v) {
		v->visit(this);
	}
};

int main()
{
	ViewVisitor* vv = new ViewVisitor;
	DoVisitor* dv = new DoVisitor;

	Engine e;

	e.accept(vv);
	e.accept(dv);

    return 0;
}

