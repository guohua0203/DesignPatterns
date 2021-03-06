// chainOfResponsibility.cpp : Defines the entry point for the console application.
//

#include "header.h"

class Request {
	int m_level;
public:
	Request(int level) : m_level(level) {};
	int getLevel() {
		return m_level;
	}
};

class Handler {
	int m_limit;
	Handler* m_next;

public:
	Handler(int limit, Handler* next) : m_limit(limit), m_next(next) {};

	void handleRequest(Request& req) {
		int l = req.getLevel();

		if (l > m_limit) {
			m_next->handleRequest(req);
		}
		else {
			cout << "handled by Handler of limit: " << m_limit << endl;
		}
	}
};

int main()
{
	Request req(2);

	Handler* h2 = new Handler(2, nullptr);
	Handler* h1 = new Handler(1, h2);

	h1->handleRequest(req);

    return 0;
}

