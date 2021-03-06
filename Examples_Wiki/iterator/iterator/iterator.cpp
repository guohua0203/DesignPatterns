// iterator.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Iterator has iterating functions, e.g., first(), isEnd(), next(), current();
// Iterator has aggregate data;
// Iterating functions are based on the data;
// During iteration, client need not to know anything about the data -- it is Iterator's job;

template<template<typename, typename> class U, typename T, typename A>
class Iterator {
	typedef typename U<T, A>::iterator IteratorType;

	IteratorType m_it;
	U<T, A> m_data;

public:
	Iterator(U<T, A>& data) : m_data(data) {};

	void first() { m_it = m_data.begin(); };

	void next() { m_it++; };

	bool isLast() { return m_it == m_data.end(); };

	IteratorType current() { return m_it; };
};


class Money {
	int m_val;

public:
	Money(int val) : m_val(val) {};
	int getVal(){ return m_val; };
};

int main()
{
	// Iterator of vector of int;
	vector<int> vectorInt({ 1, 2, 3 });

	Iterator<vector, int, allocator<int>> it(vectorInt);
	
	for (it.first(); !it.isLast(); it.next()) {
		int x = *(it.current());
		cout << x << endl;
	}


	// Iterator of list of int;
	list<int> listInt({ 5, 6 });

	Iterator<list, int, allocator<int >> it2(listInt);

	for (it2.first(); !it2.isLast(); it2.next()) {
		int x = *(it2.current());
		cout << x << endl;
	}

	// Iterator of vector of Money;
	Money m1(20);
	Money m2(100);

	vector<Money> vectorMoney({ m1, m2 });
	
	Iterator<vector, Money, allocator<Money>> it3(vectorMoney);
	
	for (it3.first(); !it3.isLast(); it3.next()) {
		Money m = *(it3.current());
		cout << m.getVal() << endl;
	}

	// Iterator of list of Money
	list<Money> listMoney({ m1, m2 });

	Iterator<list, Money, allocator<Money>> it4(listMoney);
	
	for (it4.first(); !it4.isLast(); it4.next()) {
		Money m = *(it4.current());
		cout << m.getVal() << endl;
	}

    return 0;
}

