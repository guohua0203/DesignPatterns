#include "stdafx.h"
#include "Calculator.h"

// This is Model;

int Calculator::evaluate(CString s)
{
	int x = s[0] - '0';
	int y = s[1] - '0';
	int res = x + y;
	return res;
}