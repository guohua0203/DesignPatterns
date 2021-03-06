// command.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Command has Receiveer and an Execute method;
// Execute call Receiver's corresponding method;

class Light {
public:
	void turnOn() {
		cout << "turn light on" << endl;
	}

	void turnOff() {
		cout << "turn light off" << endl;
	}
};

class Command {
protected:
	Light m_light;
public:
	Command(Light light) : m_light(light) {};
	virtual void execute() = 0;
};

class FlipUpCommand : public Command{
public:
	FlipUpCommand(Light light) : Command(light) {};

	void execute() override{
		m_light.turnOn();
	}
};

class FlipDownCommand : public Command {
public:
	FlipDownCommand(Light light) : Command(light) {};

	void execute() override {
		m_light.turnOff();
	}
};

class Switch {
	Command* m_flipUpCommand;
	Command* m_flipDownCommand;

public:
	Switch(Command* flipUpCommand, Command* flipDownCommand) : m_flipUpCommand(flipUpCommand), m_flipDownCommand(flipDownCommand) {};

	void flipUp() {
		m_flipUpCommand->execute();
	}

	void flipDown() {
		m_flipDownCommand->execute();
	}
};

int main()
{
	Light light;

	FlipUpCommand* flipUpCommand = new FlipUpCommand(light);
	FlipDownCommand* flipDownCommand = new FlipDownCommand(light);

	Switch switcher(flipUpCommand, flipDownCommand);
	
	switcher.flipUp();
	switcher.flipDown();

    return 0;
}

