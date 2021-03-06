// interpreter.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Expression has an Interpreter;
// Interpreters are called w.r.t. Expressions;

class Expression {
public:
	virtual int interpret(map<char, int>& mp) = 0;
};

class Variable : public Expression{
	char m_name;

public:
	Variable(char name) : m_name(name) {};

	int interpret(map<char, int>& mp) override{
		return mp[m_name];
	}
};

class Plus : public Expression{
	Expression* m_l;
	Expression* m_r;

public:
	Plus(Expression* l, Expression* r) : m_l(l), m_r(r) {};

	int interpret(map<char, int>& mp) {
		int x = m_l->interpret(mp);
		int y = m_r->interpret(mp);

		return x + y;
	}
};

class Minus : public Expression{
	Expression* m_l;
	Expression* m_r;

public:
	Minus(Expression* l, Expression* r) : m_l(l), m_r(r) {};

	int interpret(map<char, int>& mp) {
		int x = m_l->interpret(mp);
		int y = m_r->interpret(mp);

		return x - y;
	}
};

class Sentence : public Expression {
	Expression* m_syntaxTree;

public:
	int interpret(map<char, int>& mp) {
		int res = m_syntaxTree->interpret(mp);
		return res;
	}

	Sentence(string& s) {
		stack<Expression*> st;

		for (char c : s) {
			if (islower(c)) {
				Variable* var = new Variable(c);
				st.push(var);
			}
			else if (c == '+') {
				Expression* l = st.top();
				st.pop();

				Expression* r = st.top();
				st.pop();

				Plus* plus = new Plus(l, r);
				st.push(plus);
			}
			else {
				Expression * l = st.top();
				st.pop();

				Expression* r = st.top();
				st.pop();

				Minus* minus = new Minus(l, r);
				st.push(minus);
			}
		}

		m_syntaxTree = st.top();
		st.pop();
	}

};

int main()
{
	string s = "wxy-+";

	// y - x + w;
	Sentence sentence(s);

	map<char, int> mp;
	mp['w'] = 5;
	mp['x'] = 10;
	mp['y'] = 42;

	int res = sentence.interpret(mp);

	cout << res << endl;
    return 0;
}

