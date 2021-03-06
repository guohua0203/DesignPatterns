// composite.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Composite enables to treat composition same way as Individuals;
// Composite and Individual dervied from same class;

class Graphic {
public:
	virtual void print() = 0;
	//Graphic* get() {
	//	return this;
	//}
};

class Ellipse : public Graphic{
public:
	void print() override {
		cout << "print Ellipse" << endl;
	}
};

class CompositeGraphic : public Graphic {
	vector<Graphic*> m_v;
public:
	void print() override {
		for (Graphic* g : m_v) {
			g->print();
		}
	}

	void add(Graphic* g) {
		m_v.push_back(g);
	}
};

int main()
{
	Ellipse* e1 = new Ellipse;
	Ellipse* e2 = new Ellipse;
	Ellipse* e3 = new Ellipse;

	CompositeGraphic* cg1 = new CompositeGraphic;
	CompositeGraphic* cg2 = new CompositeGraphic;
	cg1->add(e1);
	cg2->add(e2);
	cg2->add(e3);
	cg2->add(cg1);

	cg2->print();

	return 0;
}

