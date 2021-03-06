// State.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "header.h"

class Solution {
public:
	string makeLargestSpecial(string S) {
		int n = S.length();
		vector<string> segments(0);
		int i = 0;
		int j = 0;
		int cnt = 0;
		while (j < n) {
			cnt += S[j] == '1' ? 1 : -1;
			if (cnt == 0) {
				string ss = S.substr(i + 1, j - i - 1);
				string subRes = makeLargestSpecial(ss);
				segments.push_back("1" + subRes + "0");
				i = j + 1;
			}
			j++;
		}

		sort(segments.begin(), segments.end());
		string res = "";
		for (string& s : segments) {
			res += s;
		}

		return res;
	}
};

int main()
{
}

