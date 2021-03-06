// template.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Template has a "templateMethod" and primitive methods;
// Concrete override primitive methods;
// Concrete does not the override "templateMethod"

class Game {
public:
	void playGame() {
		while (!endOfGame()) {
			makePlay();
		}
	}

	virtual void makePlay() = 0;
	virtual bool endOfGame() = 0;
};

class Chess : public Game {
public:
	void makePlay() override{
		cout << "a Chess step" << endl;
	}

	bool endOfGame() override{
		cout << "determine Chess end" << endl;

		// implementation needed;
		return false;	
	}
};

class Monoplay : public Game {
public:
	void makePlay() override {
		cout << "a Monoply step" << endl;
	}

	bool endOfGame() override {
		cout << "determine Monoplay end" << endl;

		// implementation needed
		return false;
	}
};

int main()
{
	Chess c;
	Monoplay m;

	c.playGame();
	m.playGame();
    return 0;
}

