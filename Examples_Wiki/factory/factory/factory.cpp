// factory.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Factory create Product;

class Computer {
public:
	virtual void run() = 0;
};

class Desktop : public Computer{
public:
	void run() override {
		cout << "Desktop run" << endl;
	}
};

class Laptop : public Computer {
public:
	void run() override {
		cout << "Laptop run" << endl;
	}
};

class Factory {
public:
	virtual Computer* produce() = 0;
};

class DesktopFactory : public Factory{
public:
	Computer* produce() override {
		Desktop* dComputer = new Desktop;
		return dComputer;
	}
};

class LaptopFactory : public Factory {
public:
	Computer * produce() override {
		Laptop* lComputer = new Laptop;
		return lComputer;
	}
};

int main()
{
	Computer* pComputer = nullptr;

	string type = "Desktop";
	Factory* f = nullptr;

	if (type == "Desktop") {
		f = new DesktopFactory;
		pComputer = f->produce();
	}
	else {
		f = new LaptopFactory;
		pComputer = f->produce();
	}
	
	pComputer->run();

	delete pComputer;
	delete f;
    return 0;
}

