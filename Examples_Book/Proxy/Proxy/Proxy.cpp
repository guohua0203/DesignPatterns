// Proxy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Proxy.h"

class Graphic {
public:
	virtual void draw(const Point& at) = 0;
	virtual const Point& getExtent() = 0;

protected:
	Graphic() {
		// implementation;
	};
};

class Image : public Graphic {
public:
	Image(const char* file) {
		// implementation;
	}

	virtual void draw(const Point& at) {
		cout << "expensive draw image" << endl;
	}

	virtual const Point& getExtent() {
		cout << "cheap get extent" << endl;
		return Point::Zero;
	}

	virtual void load(istream& from) {
		// this method is here to indicate that
		// "load" in Proxy only loads Extent and Fila Name
		// of the image, which is cheap;
		
		cout << "expensive image load" << endl;
		// implementation;
	}

private:
};

class ImageProxy : public Graphic {
public:
	ImageProxy(const char* fileName) {
		m_fileName = const_cast<char*> (fileName);
		m_extent = Point::Zero;
		m_image = 0;
	}

	Image* getImage() {
		if (m_image == 0) {
			m_image = new Image(m_fileName);
		}
		return m_image;
	}

	const Point& getExtent() {
		if (m_extent == Point::Zero) {
			m_extent = getImage()->getExtent();
		}
		return m_extent;
	}

	void draw(const Point& at) {
		getImage()->draw(at);
	}

	void load(istream& from) {
		cout << "cheap image proxy load" << endl;
		from >> m_extent;
	}

private:
	Image* m_image;
	Point m_extent;
	char* m_fileName;
};

class TextDocument {
public:
	TextDocument() {
		// implementation;
	}

	void insert(Graphic*) {
		// implementation;
	}
};

Point Point::Zero;

int main()
{
	const char* fileName = "my Image file";
	TextDocument* text = new TextDocument();
	ImageProxy* imgProxy = new ImageProxy(fileName);
	text->insert(imgProxy);

	// text's "load" and "draw" methods (not present here/book)
	// calls imageProxy's "load" and "draw".
	// imageProxy's load is cheap and "draw" is expensive;
	//
	//std::filebuf  dummy;
	//std::istream  stream(&dummy);
	//imgProxy->load(stream);
	//Image* img = new Image(fileName);
	//img->load(stream);
	//
	//imgProxy.getExtent();
	//imgProxy.draw(Point::Zero);

    return 0;
}

