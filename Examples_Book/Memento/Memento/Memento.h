#pragma once

struct Point {
	// implementation;

	Point& operator-() {
		//implementation;
		Point p;
		return p;
	}
};

class Graphic {
public:
	Graphic() {
		// implemenation;
	}

	void move(Point& delta) {
		cout << "Graphic move delta" << endl;
	}
};