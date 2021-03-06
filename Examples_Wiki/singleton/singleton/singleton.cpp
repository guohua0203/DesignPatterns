// singleton.cpp : Defines the entry point for the console application.
//

#include "header.h"

// Static getInstance method 

class StringSingleton {
public:
	static StringSingleton* m_instance;
	string m_string;

	static StringSingleton* getInstance(const string& s) {
		static StringSingleton* instance = new StringSingleton(s);
		m_instance = instance;
		return m_instance;
	}

private:
	StringSingleton(const string& s) : m_string(s) {};
};

StringSingleton* StringSingleton::m_instance = nullptr;

int main()
{
	string s1 = "the Only";
	StringSingleton* sgt1 = StringSingleton::getInstance(s1);

	string s2 = "Another";
	StringSingleton* sgt2 = StringSingleton::getInstance(s2);

	cout << sgt1->m_string << endl;
	cout << sgt2->m_string << endl;
    return 0;
}

