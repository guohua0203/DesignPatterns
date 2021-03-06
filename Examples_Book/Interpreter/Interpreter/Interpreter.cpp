// Interpreter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"
#include "Interpreter.h"

class BooleanExp {
public:
	BooleanExp() {
		// implementation
	}

	virtual ~BooleanExp() {
		// implementation;
	}

	virtual bool evaluate(Context&) = 0;
};

class VariableExp : public BooleanExp {
public:
	VariableExp(const string& name) {
		m_name = name;
	}

	virtual bool evaluate(Context& aContext) {
		return aContext.lookup(m_name);
	}

private:
	string m_name;
};

class AndExp : public BooleanExp {
public:
	AndExp(BooleanExp* op1, BooleanExp* op2) {
		m_operand1 = op1;
		m_operand2 = op2;
	}

	bool evaluate(Context& aContext) {
		return m_operand1->evaluate(aContext) && m_operand2->evaluate(aContext);
	}

private:
	BooleanExp* m_operand1;
	BooleanExp* m_operand2;
};

int main()
{
	VariableExp* x = new VariableExp("X");
	VariableExp* y = new VariableExp("Y");

	BooleanExp* expression = new AndExp(x, y);
	Context* context = new Context();

	context->assign(x, true);
	context->assign(y, true);

	bool res = expression->evaluate(*context);
	cout << res << endl;

    return 0;
}

