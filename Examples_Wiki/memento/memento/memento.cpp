// memento.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Memento has a snapshot of Object 
// (the snapshot can be the object or 
// its "state" information that can be used to restore the object);
// Object create and reinstate Memento;
// Command undo and redo;

class Memento;

class Object {
	int m_state;
public:
	Object(int state) : m_state(state) {};

	Memento * createMemento();
	void reinstateMemento(Memento* memento);

	void increase() {
		m_state++;
	}
	
	int getState() {
		return m_state;
	}
};

class Memento {
	Object m_snapshot;

public:
	Memento(Object object) : m_snapshot(object) {};

	Object getSnapshot() {
		return m_snapshot;
	}
};

Memento* Object::createMemento() {
	Memento* memento = new Memento(*this);
	return memento;
}

void Object::reinstateMemento(Memento* memento) {
	*this = memento->getSnapshot();
}

class Command {
	Object* m_receiver;
	typedef void (Object::*Action)();
	Action m_action;
	vector<Command*> m_commandList;
	vector<Memento*> m_mementoList;

public:
	Command(Object* object, Action action) : m_receiver(object), m_action(action) {};
	void execute() { 
		Memento* memento = m_receiver->createMemento();

		// be prepared for undo:
		m_mementoList.push_back(memento);

		// be prepared for redo;
		m_commandList.push_back(this);

		(m_receiver->*m_action)(); 
	}

	void undo() {
		// this function is not exactly the usual "undo", i.e.,
		// it forgets the undone command and cannot redo it after;
		// 
		// to impelement the usual undo, add another stack to
		// store the undoen command and push its top back to comamndList
		// when redo;
		
		Command* command = m_commandList.back();
		Memento* memento = m_mementoList.back();
		command->m_receiver->reinstateMemento(memento);
		m_commandList.pop_back();
		m_mementoList.pop_back();
	}

	void redo() {
		Command* command = m_commandList.back();
		command->execute();
	}

	Object* getReceiver() {
		return m_receiver;
	}
};

int main()
{
	Object* obj = new Object(0);
	Command commandIncrease(obj, &Object::increase);

	commandIncrease.execute();
	Object* curObj = commandIncrease.getReceiver();
	cout << curObj->getState() << endl;

	commandIncrease.undo();
	curObj = commandIncrease.getReceiver();
	cout << curObj->getState() << endl;

    return 0;
}

