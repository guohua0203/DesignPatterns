// Strategy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Strategy.h"

class Compositor;

class Composition {
public:
	Composition(Compositor* compositor) {
		m_compositor = compositor;
	}

	// cannot implement yet, 
	// since "Compositor" class has not been defined;
	void repair();

private:
	Compositor * m_compositor;

	// the list of components;
	vector<Component*> m_components;
};

class Compositor {
public:
	virtual void compose(vector<int>& breaks) = 0;
};

class SimpleCompositor : public Compositor {
public:
	SimpleCompositor() {
		// implementation;
	}

	virtual void compose(vector<int>& breaks) override {
		cout << "Simple Compositor fills the vector of breaks" << endl;
	}
};

class TexCompositor: public Compositor {
public:
	TexCompositor() {
		// implementation;
	}

	virtual void compose(vector<int>& breaks) override {
		cout << "Tex Compositor fills the vector of breaks" << endl;
	}
};

void Composition::repair() {
	vector<int> breaks;
	m_compositor->compose(breaks);
	cout << "lay out components according to breaks" << endl;
}


int main()
{
	Composition* simpleComp = new Composition(new SimpleCompositor());
	Composition* texComp = new Composition(new TexCompositor());
	simpleComp->repair();
	texComp->repair();
}

