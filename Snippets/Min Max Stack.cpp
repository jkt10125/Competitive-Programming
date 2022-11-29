#include <bits/stdc++.h>
using namespace std;

class MinMaxSTACK {
	vector<array<int, 3>> stack;
	public:
	int size () const {
		return stack.size();
	}
	bool empty () const {
		return size();
	}
	void push (int a) {
		int b = a, c = a;
		if (size()) {
			b = std::min(b, stack.back()[1]);
			c = std::max(c, stack.back()[2]);
		}
		stack.push_back({a, b, c});
	}

	void pop () {
		stack.pop_back();
	}

	int max () {
		return stack.back()[2];
	}

	int min () {
		return stack.back()[1];
	}

	int top () {
		return stack.back()[0];
	}

	friend ostream & operator << (ostream &os, const MinMaxSTACK &S) {
		int n = S.stack.size();
		for (int i = n - 1; i > 0; i--) os << S.stack[i][0] << ' ';
		if (!S.empty()) os << S.stack.front()[0];
		return os;
	}
};