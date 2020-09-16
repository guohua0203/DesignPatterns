#pragma once

class Document {
public:
	Document(const string& name) : m_name(name) {
		cout << "create document with name: " << name << endl;
	}

	void open() {
		cout << "open document with name: " << m_name << endl;
	}

	void paste() {
		cout << "paste document with name: " << m_name << endl;
	}

	string getName() {
		return m_name;
	}

private:
	string m_name;
};

class Application {
public:
	Application() {
		// implementation;
	}

	void add(Document* d) {
		cout << "application add the document with name: " << d->getName() << endl;
	}
};


