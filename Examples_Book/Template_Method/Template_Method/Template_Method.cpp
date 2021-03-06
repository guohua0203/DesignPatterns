// Template_Method.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"

class View {
public:
	View() {
		// implementation;
	}

	void Display() {
		setFocus();
		doDisplay();
		resetFocus();
	}

	void setFocus() {
		// implmenentation;
	}

	virtual void doDisplay() {
		// do nothing, as sub-classes will implement it;
	}

	void resetFocus() {
		// implementaion;
	}
};

class MyView : public View{
public:
	MyView() {
		// implementation;
	}

	void doDisplay() override {
		cout << "My View render the contents" << endl;
	}
};

int main()
{
	MyView mv;
	mv.Display();
    return 0;
}

