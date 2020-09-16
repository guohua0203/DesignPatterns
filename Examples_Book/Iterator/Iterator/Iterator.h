#pragma once

#include "header.h"

const int DEFAULT_LIST_CAPACITY = 15;

template<class Item>
class List {
	List(long size = DEFAULT_LIST_CAPACITY) {
		// implementation;
	}

	long count() const {
		// return the number of itmes in the list; 
		// implementation;
		return 1;
	}

	Item& get(long index) const {
		// return the item at index;
		// m_data could be any data structure and "get" will be
		// implemented w.r.t to the data structure;
		//
		// for simplicity, just use vector here;
		return m_data[index];
	}

private:
	vector<Item> m_data;
};