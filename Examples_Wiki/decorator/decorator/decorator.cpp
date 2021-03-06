// decorator.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Decorator class has the "Main" class as a member, so that it can have the functions of the Main class; 

class Car {
	int m_price;
public:
	Car(int price) : m_price(price) {};

	int get_price() {
		return m_price;
	}
};

class Option{
	Car m_car;
public:
	Option(Car car) : m_car(car) {};
	virtual int get_price() = 0;
	Car getCar() { return m_car; };
};

class Navigation : public Option {
public:
	Navigation(Car car) : Option(car) {};
	int get_price() override{
		return getCar().get_price() + 5;
	}
};

class Transmission : public Option {
public:
	Transmission(Car car) : Option(car) {};
	int get_price() override{
		return getCar().get_price() + 20;
	}
};

int main()
{
	Car c(2000);
	Navigation n(c);
	Transmission t(c);

	cout << n.get_price() << endl;
	cout << t.get_price() << endl;

    return 0;
}

