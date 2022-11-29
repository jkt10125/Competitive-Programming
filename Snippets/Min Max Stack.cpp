#include <bits/stdc++.h>
using namespace std;

int f (int a, int b) {
	return min (a, b);
}

struct elem {
	int v, x;
};

class Mstack {
	vector<elem> stack;
	public:
	int size () const {
		return stack.size();
	}
	bool empty () const {
		return size();
	}
	void push (int v) {
		int x = v;
		if (size()) {
			x = f (x, stack.back().x);
		}
		stack.push_back({v, x});
	}

	void pop () {
		stack.pop_back();
	}

	int feature () {
		return stack.back().x;
	}

	int top () {
		return stack.back().v;
	}

	friend ostream & operator << (ostream &os, const Mstack &S) {
		int n = S.stack.size();
		for (int i = n - 1; i > 0; i--) os << S.stack[i].v << ' ';
		if (!S.empty()) os << S.stack.front().v;
		return os;
	}
};
