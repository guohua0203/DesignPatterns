#pragma once

class Point {
	// implementation;
public:
	Point() {
		// implementation;
	}

	static Point Zero;

	const Point& operator=(const Point& rhs) {
		//impementation;
		return rhs;
	}

	bool operator==(const Point& rhs) {
		// implementation;
		return true;
	}
};

istream& operator >>(istream& stream, Point& point) {
	return stream;
}