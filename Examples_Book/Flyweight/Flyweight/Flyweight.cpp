// Flyweight.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Flyweight.h"

class GlyphContext {
public:
	GlyphContext() {
		// implementation;
	}

	virtual void Next(int step = 1) {
		m_index++;
	}

	virtual Font* getFont() {
		cout << "return m_fonts[m_index]." << endl;
		return nullptr;
	}

private:
	int m_index;
	BTree* m_fonts;
};

class Glyph {
public:
	virtual void draw(Window* w, GlyphContext&) {
		// implementation;
	}

	virtual void setFont(Font* font) {
		// implementation;
	}

protected:
	Glyph() {
		// implementation;
	}
};

class Character : public Glyph {
	// shared Glyph;
public:
	Character(char ch) {
		m_charcode = ch;
	}

	virtual void draw(Window* w, GlyphContext& gc) {
		Font* font = gc.getFont();
		this->setFont(font);
		cout << "draw character in font." << endl;
	}

private:
	char m_charcode;
};

class Row : public Glyph {
	// non-shared Glyph;
	// implementation;
};

const int NCHARCODES = 128;

class GlyphFactory {
public:
	GlyphFactory() {
		for (int i = 0; i < NCHARCODES; i++) {
			m_character[i] = 0;
		}
	}

	virtual Character* createCharacter(char c) {
		if (!m_character[c]) {
			m_character[c] = new Character(c);
		}

		return m_character[c];
	}

	virtual Row* createRow() {
		return new Row;
	}

private:
	Character * m_character[NCHARCODES];
};

int main()
{
	Character ch('a');
	Window* w = new Window;
	GlyphContext gc;

	ch.draw(w, gc);

    return 0;
}

// The C++ Standard section 3.10:5 indicates that the result of calling a function 
// that does not return a reference is an rvalue.Therefore;
// An rvalue does not have an address and you 
// cannot store into it. According to section 13.3.3.1.4 :3 a standard conversion sequence 
// cannot be formed if it requires binding a non - const reference to an rvalue, 
// except for implicit object parameters.