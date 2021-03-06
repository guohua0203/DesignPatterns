// Mediator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"

class Widget;

class DialogDirector {
public:
	virtual ~DialogDirector() {};

	virtual void widgetChanged(Widget*) = 0;
};

class Widget {
public:
	Widget(DialogDirector* director) {
		m_director = director;
	}

	virtual void Changed() {
		m_director->widgetChanged(this);
	}

private:
	DialogDirector * m_director;
};

class ListBox : public Widget {
public:
	ListBox(DialogDirector* dd) : Widget(dd){}
};

class EntryField : public Widget {
public:
	EntryField(DialogDirector* dd) : Widget(dd) {};

	virtual void setText(const string& text) {
		cout << "Entry Field set to: " << text << endl;
	}
};

class FontDialogDirector : public DialogDirector{
public:
	FontDialogDirector() {
		createWidgets();
	}

	virtual ~FontDialogDirector() {};

	virtual void widgetChanged(Widget* theChangedWidget) {
		if (theChangedWidget == m_fontList) {
			m_fontName->setText("Text");
		}
		else {
			// do nothing;
		}
	}

	Widget* getFontList() const{
		return m_fontList;
	}

protected:
	void createWidgets() {
		m_fontList = new ListBox(this);
		m_fontName = new EntryField(this);
	}

private:
	ListBox * m_fontList;
	EntryField* m_fontName;
};

int main()
{
	FontDialogDirector* fdd = new FontDialogDirector();
	Widget* fontList = fdd->getFontList();
	fontList->Changed();
}

