// Bridge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Bridge.h"

class WindowImp {
public:
	WindowImp() {
		// implementation;
	}

	virtual void deviceRect(const Coord&, const Coord&, const Coord&, const Coord&) = 0;
};

class XWindowImp : public WindowImp {
public:
	XWindowImp() {
		// implementation;
	}

	virtual void deviceRect(const Coord& c1, const Coord& c2, const Coord& c3, const Coord& c4) override {
		cout << "xWindow device Rect" << endl;
	}
};

class PmWindowImp : public WindowImp {
public:
	PmWindowImp() {
		// implementation;
	}

	virtual void deviceRect(const Coord& c1, const Coord& c2, const Coord& c3, const Coord& c4) override{
		cout << "PmWindow device Rect" << endl;
	}
};

class Window {
public:
	Window() {
		// implementation;
	}

	Window(WindowImp* imp) {
		m_imp = imp;
	}

	virtual void drawRect(const Point& p1, const Point& p2) {
		m_imp->deviceRect(p1.x(), p1.y(), p2.x(), p2.y());
	}

private:
	WindowImp* m_imp;
};


int main()
{
	Point p1;
	Point p2;

	WindowImp* xWImp = new XWindowImp();
	Window w(xWImp);
	w.drawRect(p1, p2);

	WindowImp* pmWImp = new PmWindowImp();
	Window w2(pmWImp);
	w2.drawRect(p1, p2);
	
    return 0;
}

