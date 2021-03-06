// Composite.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "header.h"

class Equipment {
public:
	Equipment() {
		// implementation;
	}

	virtual int netPrice() {
		// implementation;
		return 0;
	}
};

class FloppyDisk : public Equipment{
public:
	FloppyDisk() {
		// implementation;
	}

	int netPrice() {
		return 5;
	}
};

class Bus : public Equipment {
public:
	Bus() {
		// implementation;
	}

	int netPrice() {
		return 10;
	}
};

class CompositeEquipment : public Equipment {
public:
	CompositeEquipment() {
		// implementation;
	}

	int netPrice() {
		int res = 0;
		// use iterator to indicate "vector" could be user defined aggregate;
		for (vector<Equipment*>::iterator it = eqs.begin(); it != eqs.end(); it++) {
			res += (*it)->netPrice();
		}
		return res;
	}

	void addEquipment(Equipment* eq) {
		eqs.push_back(eq);
	}

private:
	vector<Equipment*> eqs;
};

class Computer : public CompositeEquipment {
public:
	Computer() {
		// implementation;
	}
};

int main()
{
	FloppyDisk* f = new FloppyDisk();
	Bus* b = new Bus();

	Computer c;
	c.addEquipment(f);
	c.addEquipment(b);

	int res = c.netPrice();
	cout << res << endl;
}
