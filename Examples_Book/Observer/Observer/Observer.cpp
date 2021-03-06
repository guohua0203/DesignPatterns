// Observer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"

class Subject;

class Observer {
public:
	virtual ~Observer() {}

	virtual void update(Subject* theChangedSubject) = 0;
protected:
	Observer() {
		// implementation;
	}
};

class Subject {
public:
	virtual ~Subject() {}

	virtual void attach(Observer* o) {
		m_observers.push_back(o);
	}

	virtual void detach(Observer* o) {
		m_observers.remove(o);
	}

	virtual void notify() {
		for (auto it : m_observers) {
			it->update(this);
		}
	}

protected:
	Subject() {
		// implementation;
	}

private:
	list<Observer*> m_observers;
};

class ClockTimer : public Subject {
public:
	ClockTimer() {
		// implementation;
	}

	virtual int getHour(){
		cout << "Clock Timer get Hour" << endl;
		return 1;
	}

	virtual int getMinute(){
		cout << "Clock Timer get Minute" << endl;
		return 2;
	}

	virtual int getSecond() {
		cout << "Clock Timer get second" << endl;
		return 3;
	}

	void tick() {
		notify();
	}
};

class DigitalClock : public Observer {
public:
	DigitalClock(ClockTimer* s) {
		m_subject = s;
		m_subject->attach(this);
	}

	~DigitalClock(){
		m_subject->detach(this);
	}

	void update(Subject* theChangedSubject) {
		if (theChangedSubject == m_subject) {
			int hour = m_subject->getHour();
			int minute = m_subject->getMinute();
	
			// ... etc;

			cout << "Digital Clock update done" << endl;
		}
	}

private:
	ClockTimer * m_subject;
};

class AnalogClock : public Observer {
	// same as digital clock;
};

int main()
{
	ClockTimer* timer = new ClockTimer();
	DigitalClock* dClock = new DigitalClock(timer);
	//AnalogClock* aClock = new AnalogClock(timer);

	timer->tick();

    return 0;
}

