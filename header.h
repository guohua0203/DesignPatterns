#pragma once
#include <iostream>
#include <istream>
#include <sstream>
#include <time.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <omp.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <math.h>
#include <limits>
#include <bitset>
#include <memory>
#include <bitset>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

template <class T>
void printVector(vector<T> v)
{
	for (auto e : v)
	{
		cout << e << endl;
	}
}

template<class T>
void printVector2d(vector<vector<T>> v) {
	for (auto ev : v) {
		for (auto e : ev) {
			cout << e << ", ";
		}
		cout << endl;
	}
}

void printList(ListNode* l) {
	ListNode* p = l;
	while (p) {
		cout << p->val << endl;
		p = p->next;
	}
}