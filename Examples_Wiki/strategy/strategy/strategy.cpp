// strategy.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Strategy has execute method;
// Contex has Strategy and execute method;

class Strategy {
public:
	virtual void execute() = 0;
};

class StrategyA : public Strategy {
public:
	void execute() override {
		cout << "A execute" << endl;
	}
};

class StrategyB : public Strategy {
public:
	void execute() override {
		cout << "B execute" << endl;
	}
};

class Context {
	Strategy* m_strategy;

public:
	void execute(){
		m_strategy->execute();
	}

	void setStrategy(Strategy* s) {
		m_strategy = s;
	}
};

int main()
{
	Strategy* sA = new StrategyA;
	Strategy* sB = new StrategyB;

	Context c1;
	c1.setStrategy(sA);
	c1.execute();

	c1.setStrategy(sB);
	c1.execute();

    return 0;
}

