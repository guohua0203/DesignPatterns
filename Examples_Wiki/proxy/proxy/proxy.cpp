// proxy.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Proxy has Subject and some of its information;
// Client has Proxy, since Client wants some info of the Subject without necessity of Subject;
// Client does not have Subject since create it is expensive and before 
// creation the wanted info is unavailable;

class Image {
	int m_area;
public:
	Image* create(int area) {
		Image* img = new Image();
		img->m_area = area;
		cout << "create image expensively" << endl;
		return img;
	}

	int getArea() {
		return m_area;
	}
};

class ImageProxy : Image{
	// area of *m_image;
	int m_area;
	Image* m_image;

public:
	ImageProxy(int area) : m_area(area), m_image(nullptr) {};

	void createImage() {
		m_image = create(m_area);
	}

	int getArea() {
		if (!m_image) {
			cout << "Cheap image area without creating the object" << endl;
			return m_area;
		}
		else {
			cout << "Expensive image area after creating the object" << endl;
			return m_image->getArea();
		}
	}
};


int main()
{
	int area = 22;
	ImageProxy ip(area);

	cout << ip.getArea() << endl;

	// !!! before createImage, m_image of proxy is NULL !!!
	ip.createImage();

	cout << ip.getArea() << endl;

    return 0;
}

