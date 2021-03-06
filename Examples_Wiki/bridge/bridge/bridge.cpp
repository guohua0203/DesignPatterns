// bridge.cpp : Defines the entry point for the console application.
//

#include "header.h"

// DrawingApi (Bridge) bridges Circle (Interface) and its drawing (Implementation);

class DrawingApi {
public:
	virtual void draw(int x, int y, int r) = 0;
};

class DrawingApi1 : public DrawingApi{
public:
	void draw(int x, int y, int r) override{
		cout << "Drawing API 1" << endl;
	}
};

class DrawingApi2 : public DrawingApi{
public:
	void draw(int x, int y, int r) override{
		cout << "Drawing API 2" << endl;
	}
};

class Circle {
	int m_x;
	int m_y;
	int m_r;
	unique_ptr<DrawingApi> m_drawingApi;

public:
	Circle(int x, int y, int r, unique_ptr<DrawingApi> drawingApi) : m_x(x), m_y(y), m_r(r), m_drawingApi(move(drawingApi)) {};

	void drawCircle() {
		m_drawingApi->draw(m_x, m_y, m_r);
	}
};

int main()
{
	unique_ptr<DrawingApi> draw1 = make_unique<DrawingApi1>();
	unique_ptr<DrawingApi> draw2 = make_unique<DrawingApi2>();

	Circle c1(1, 2, 3, move(draw1));
	Circle c2(5, 6, 8, move(draw2));

	c1.drawCircle();
	c2.drawCircle();
    return 0;
}

