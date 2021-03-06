// state.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Context has a member State;
// State handle input to change Context;

class Fighter;
class DuckState;

class FighterState {
public:
	virtual void handleInput(Fighter* fighter, string& input) {};
};

class StandState : public FighterState {
public:
	StandState() {};
	void handleInput(Fighter* fighter, string& input);
};

class DuckState : public FighterState {
public:
	DuckState() {};
	void handleInput(Fighter* fighter, string& input);
};

class Fighter {
	FighterState* m_state;
public:
	Fighter(FighterState* state) : m_state(state) {};
	void handleInput(string& input);
	void changeState(FighterState* newState) { m_state = newState; };
};

void StandState::handleInput(Fighter* fighter, string& input) {
	if (input == "standUp") {
		cout << "do nothing" << endl;
	}
	else{
		// "duckDown":
		cout << "duck down" << endl;
		DuckState* newState = new DuckState;
		fighter->changeState(newState);
	}
};

void DuckState::handleInput(Fighter* fighter, string& input) {
	if (input == "standUp") {
		cout << "stand up" << endl;
		StandState* standState = new StandState;
		fighter->changeState(standState);
	}
	else{
		// "duckDown":
		cout << "do nothing" << endl;
	}
}

void Fighter::handleInput(string& input) {
	m_state->handleInput(this, input);
}

int main()
{
	FighterState* stand = new StandState;
	Fighter f(stand);

	string input = "duckDown";
	f.handleInput(input);

	input = "standUp";
	f.handleInput(input);

    return 0;
}

