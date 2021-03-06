// observer.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Observer updates when Subject updates
// Subject notify Observer to update;

class Observer {
public:
	virtual void update(float data) = 0;
};

class CurrentBoard : public Observer{
	float m_cur;
public:
	CurrentBoard(float data) : m_cur(data) {};
	void update(float data) override {
		m_cur = data;
	}
};

class StatisticBoard : public Observer {
	float m_min;
public:
	StatisticBoard(float data) : m_min(data) {};
	void update(float data) override {
		m_min = min(m_min, data);
	}
};

class WeatherData {
	float m_data;
	set<Observer*> m_observers;
public:
	WeatherData(float d) : m_data(d) {};
	
	void registerObserver(Observer* observer) {
		m_observers.insert(observer);
	}

	void unregisterObserver(Observer* observer) {
		m_observers.erase(observer);
	}

	void notify() {
		for (Observer* ob : m_observers) {
			ob->update(m_data);
		}
	}
};

int main()
{
	WeatherData w(20);
	CurrentBoard* cb = new CurrentBoard(10);
	StatisticBoard* sb = new StatisticBoard(10);

	w.registerObserver(cb);
	w.registerObserver(sb);

	w.notify();

    return 0;
}

