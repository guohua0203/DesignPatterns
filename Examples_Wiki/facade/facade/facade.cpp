// facade.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Facade methods hides the complexity of Components' methods;

class Alarm {
public:
	void on(){
		cout << "alarm on" << endl;
	}

	void off() {
		cout << "alarm off" << endl;
	}
};


class Ac {
public:
	void on() {
		cout << "ac on" << endl;
	}

	void off() {
		cout << "ac off" << endl;
	}
};

class HouseFacade {
	Alarm m_alarm;
	Ac m_ac;

public:
	HouseFacade(Alarm alarm, Ac ac) : m_alarm(alarm), m_ac(ac) {};

	void enterHouse() {
		m_alarm.off();
		m_ac.on();
	}

	void leaveHouse() {
		m_alarm.on();
		m_ac.off();
	}
};

int main()
{
	Alarm al;
	Ac ac;
	HouseFacade hf(al, ac);
	hf.enterHouse();
	hf.leaveHouse();

    return 0;
}

