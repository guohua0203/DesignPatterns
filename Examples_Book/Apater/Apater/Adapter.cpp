// Apater.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Adapter.h"


class Shape {
public:
	Shape() {
		// implementation;
	};

	virtual void boundingBox(Point& bottomLeft, Point& topRight) const {
		// implementation;
	}
};

class TextView {
public:
	TextView() {
		// implementation;
	};

	void getOrigin(Coord& x, Coord& y) const {
		cout << "Text View getOrigin" << endl;
	}

	void getExtent(Coord& width, Coord& height) const {
		cout << "Text View getExtent" << endl;
	}
};

// Object Adapter:
class TextShape : public Shape {
public:
	TextShape(TextView* t) {
		m_text = t;
	}

	virtual void boundingBox(Point& bottomLeft, Point& topRight) const {
		Coord bottom, left, width, height;

		m_text->getOrigin(bottom, left);
		m_text->getExtent(width, height);

		bottomLeft = Point(bottom, left);
		topRight = Point(bottom + height, left + width);
	}

private:
	TextView * m_text;
};

int main()
{
	TextView* tv = new TextView();
	TextShape ts(tv);
	Point bottomLeft;
	Point topRight;
	ts.boundingBox(bottomLeft, topRight);

    return 0;
}

// =============================================================================
// Optional Reading
// =============================================================================
// Class Adapter:
//class TextShape : public Shape, private TextView {
//public:
//	TextShape() {
//		// implementation
//	};
//
//	virtual void boundingBox(Point& bottomLeft, Point& topRight) const {
//		Coord bottom, left, width, height;
//
//		getOrigin(bottom, left);
//		getExtent(width, height);
//
//		bottomLeft = Point(bottom, left);
//		topRight = Point(bottom + height, left + width);
//
//	}
//};

