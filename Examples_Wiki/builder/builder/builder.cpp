// builder.cpp : Defines the entry point for the console application.
//

#include "header.h"

// PizzaBuilder build each part of a pizza, according to pizza type;

class Pizza {
	string m_dough;
	string m_topping;

public:
	void setDough(const string& dough) {
		m_dough = dough;
	}

	void setTopping(const string& topping) {
		m_topping = topping;
	}
};

class PizzaBuilder{
protected:
	Pizza m_pizza;

public:
	virtual void buildDough() = 0;
	virtual void buildTopping() = 0;
	void buildPizza() {
		buildDough();
		buildTopping();
	};
	Pizza getPizza() {
		return m_pizza;
	}
};

class HawaiianPizzaBuilder : public PizzaBuilder{
public:
	void buildDough() override {
		m_pizza.setDough("Hawaiian dough");
	}

	void buildTopping() override{
		m_pizza.setTopping("Hawaiian topping");
	}
};

class SpicyPizzaBuilder : public PizzaBuilder {
public:
	void buildDough() override {
		m_pizza.setDough("Spicy dough");
	}

	void buildTopping() override{
		m_pizza.setTopping("Spicy topping"); 
	}
};

int main()
{
	HawaiianPizzaBuilder hpb;
	SpicyPizzaBuilder spb;

	hpb.buildPizza();
	Pizza hPizza = hpb.getPizza();

	spb.buildPizza();
	Pizza sPizza = spb.getPizza();

    return 0;
}

