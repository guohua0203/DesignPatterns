// mediator.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Colleague send message to Mediator;
// Mediator distribute message;

class ColleagueInterface;

class MediatorInterface {
public:
	virtual void distribute() = 0;
	virtual void registerColleague(ColleagueInterface* c) = 0;
};

class ColleagueInterface {
public:
	void send(MediatorInterface* mediator) {
		cout << "send a message" << endl;
		mediator->distribute();
	}

	void receive() {
		cout << "receive a message" << endl;
	}
};

//class Colleague : public ColleagueInterface {};

class Mediator : public MediatorInterface{
	vector<ColleagueInterface*> m_v;

public:
	void distribute() {
		for (ColleagueInterface* c : m_v) {
			c->receive();
		}
	}

	void registerColleague(ColleagueInterface* c) {
		m_v.push_back(c);
	}
};

int main()
{
	// alex sends message;
	// bob and charles receive message;
	ColleagueInterface* alex = new ColleagueInterface();
	ColleagueInterface* bob = new ColleagueInterface();
	ColleagueInterface* charles = new ColleagueInterface();

	Mediator* aMediator = new Mediator();
	aMediator->registerColleague(bob);
	aMediator->registerColleague(charles);

	alex->send(aMediator);

    return 0;
}

