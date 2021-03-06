// Chain_Of_Responsibility.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"

typedef int Topic;
const Topic NO_HELP_TOPIC = -1;

class HelpHandler {
public:
	HelpHandler(HelpHandler* h = 0, Topic t = NO_HELP_TOPIC) : m_successor(h), m_topic(t) {};
	virtual bool hasHelp() {
		return m_topic != NO_HELP_TOPIC;
	}

	virtual void setHandler(HelpHandler* h, Topic t) {
		// this function provides flexibility to change Handler;
		// see the Dialog class;
		// my implementation (not from book);
		m_successor = h;
		m_topic = t;
	}

	void handleHelp() {
		if (m_successor != 0) {
			m_successor->handleHelp();
		}
	}

private:
	HelpHandler * m_successor;
	Topic m_topic;
};

class Widget : public HelpHandler {
protected:
	Widget(Widget* parent, Topic t = NO_HELP_TOPIC) : HelpHandler(parent, t) {
		m_parent = parent;
	}

private:
	Widget * m_parent;
};

class Button : public Widget {
public:
	Button(Widget* d, Topic t = NO_HELP_TOPIC) : Widget(d, t) {}

	void HandleHelp() {
		if (hasHelp()) {
			cout << "offer help on the button" << endl;
		}
		else {
			HelpHandler::handleHelp();
		}
	}
};

class Dialog : public Widget {
public:
	Dialog(HelpHandler* h, Topic t = NO_HELP_TOPIC) : Widget(0) {
		// any HelpHandler class could be made the successor of Dialog.Moreover, 
		// its successor could be changed dynamically.
		// So no matter where a dialog is used, you'll get the proper context-dependent 
		// help informatio fnor it.
		setHandler(h, t);
	}

	virtual void HandleHelp() {
		if (hasHelp()) {
			cout << "offer help on the dialog" << endl;
		}
		else {
			HelpHandler::handleHelp();
		}
	}
};

class Application : public HelpHandler {
public:
	Application(Topic t) : HelpHandler(0, t){}
	void HandleHelp() {
		cout << "show a list of help topics" << endl;
	}
};


int main()
{
	const Topic PRINT_TOPIC = 1;
	const Topic PAPER_ORIENTATION_TOPIC = 2;
	const Topic APPLICATION_TOPIC = 3;

	Application* application = new Application(APPLICATION_TOPIC);
	Dialog* dialog = new Dialog(application, PRINT_TOPIC);
	Button* button = new Button(dialog, PAPER_ORIENTATION_TOPIC);

	button->HandleHelp();

    return 0;
}

