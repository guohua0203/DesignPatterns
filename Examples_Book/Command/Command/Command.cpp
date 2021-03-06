// Command.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Command.h"

class Command {
public:
	virtual void execute() = 0;

	virtual ~Command() {
		// implementation;
	};


protected:
	Command() {
		// implementation;
	}
};

class OpenCommand : public Command {
public:
	OpenCommand(Application* a) {
		m_application = a;
	}

	void execute() {
		const string name = askUser();

		if (!name.empty()) {
			Document* document = new Document(name);
			m_application->add(document);
			document->open();
		}
	}

protected:
	virtual const string askUser() {
		return "My Document Name";
	};

private:
	Application* m_application;
};

class PasteCommand : public Command {
public:
	PasteCommand(Document* d) {
		m_document = d;
	}

	virtual void execute() {
		m_document->paste();
	}

private:
	Document * m_document;
};

int main()
{
	Application* a = new Application();
	OpenCommand* oc = new OpenCommand(a);
	oc->execute();

	Document* d = new Document("Another Document Name");
	PasteCommand* pc = new PasteCommand(d);
	pc->execute();

    return 0;
}

