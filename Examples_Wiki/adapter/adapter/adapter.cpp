// adapter.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Adapt a interface of a class t another interface that clients expected;

class Muslim{
public:
	virtual void performMuslimRitual(){
		cout << "Muslim Ritual" << endl;
	}
};

class Hindu{
public:
	void performHinduRitual(){
		cout << "Hindu Ritual" << endl;
	}
};


class MuslimRitual {
public:
	void perform(Muslim* muslim) {
		muslim->performMuslimRitual();
	}
};

class MuslimAdapter : public Muslim {
	Hindu* m_hindu;

public:
	MuslimAdapter(Hindu* h) : m_hindu(h) {};

	void performMuslimRitual() {
		m_hindu->performHinduRitual();
	}
};

int main()
{
	Hindu* h = new Hindu;
	
	MuslimAdapter* ma = new MuslimAdapter(h);

	MuslimRitual mr;
	mr.perform(ma);

    return 0;
}

