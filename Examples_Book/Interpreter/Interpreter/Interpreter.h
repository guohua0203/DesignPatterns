#pragma once
#include "header.h"

class VariableExp;

class Context {
public:
	bool lookup(const string& name) {
		// implementation:
		return true;
	}

	void assign(VariableExp* var, bool value) {
		// implementation;
	}
};
