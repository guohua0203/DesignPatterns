// Iterator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Iterator.h"

template<class Item>
class Iterator {
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isDone() const = 0;
	virtual Item currentItem() const = 0;

protected:
	Iterator() {
		// implementation;
	}
};

template<class Item>
class ListIterator : public Iterator<Item> {
public:
	ListIterator(const List<Item>* aList) : m_list(aList), m_current(0){}

	void first() {
		m_current = 0;
	}

	void next() {
		m_current++;
	}

	bool isDone() const {
		return m_current >= m_list->count();
	}

	Item currentItem() const {
		if (isDone()) {
			throw IteratorOutOfBounds;
		}
		return m_list->get(m_current);
	}

private:
	const List<Item>* m_list;
	long m_current;
};

template<class Item>
class ReverseListIterator : public Iterator<Item> {
public:
	ReverseListIterator(const List<Item>* aList) : m_list(aList), m_current(aList->count() - 1){}

	void first() {
		m_current = m_list->count() - 1;
	}

	void next() {
		m_current--;
	}

	bool isDone() {
		return m_current < 0;
	}

	Item currentItem() {
		if (isDone()) {
			throw IteratorOutOfBounds;
		}
		return m_list->get(m_current);
	}

private:
	List<Item>* m_list;
	long m_current;
};

int main()
{
    return 0;
}

