// Decorator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"

class VisualComponent {
public:
	VisualComponent() {
		// implementation;
	}

	virtual void draw() {
		cout << "draw a Visual Component" << endl;
	}

	VisualComponent operator=(VisualComponent* rhs){
		return *rhs;
	}
};

class Decorator : public VisualComponent {
public:
	Decorator(VisualComponent* component) {
		m_component = component;
	}

	virtual void draw() {
		m_component.draw();
	}

private:
	VisualComponent m_component;
};

class BorderDecorator : public Decorator {
public:
	BorderDecorator(VisualComponent* component, int borderWidth) : Decorator(component), m_width(borderWidth)
	{}

	virtual void draw() {
		Decorator::draw();
		drawBorder();
	}
private:
	void drawBorder(){
		cout << "draw a Border" << endl;
	}

	int m_width;
};

class ScrollDecorator : public Decorator {
	// similar to Border Decorator:
	//	- draw(): call Decorrator draw() and some private method, e.g., drawScrollBar();
};

int main()
{
	VisualComponent* v = new VisualComponent();
	int borderWidth = 5;
	VisualComponent* vBorder = new BorderDecorator(v, borderWidth);
	vBorder->draw();

    return 0;
}

