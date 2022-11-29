#include <bits/stdc++.h>
using namespace std;

int f (int a, int b) {
	return min (a, b);
}

struct elem {
	int v, x;
};

class Mqueue {
	vector<elem> push_st, pop_st;
	void transfer () {
		while (!push_st.empty()) {
			int v, x;
			v = x = push_st.back().v;
			if (!pop_st.empty()) {
				x = f (x, pop_st.back().x);
			}
			pop_st.push_back({v, x});
			push_st.pop_back();
		}
	}

	public:

	int size () {
		return push_st.size() + pop_st.size();
	}

	bool empty () {
		return size ();
	}

	void push (int v) {
		int x = v;
		if (!push_st.empty()) {
			x = f (x, push_st.back().x);
		}
		push_st.push_back({v, x});
	}

	void pop () {
		if (pop_st.empty()) transfer();
		pop_st.pop_back();
	}

	int feature () {
		if (pop_st.empty()) return push_st.back().x;
		if (push_st.empty()) return pop_st.back().x;
		return f (push_st.back().x, pop_st.back().x);
	}

	int front () {
		if (pop_st.empty()) transfer();
		return pop_st.back().v;
	}

	friend ostream & operator << (ostream &os, const Mqueue &Q) {
		int n = Q.pop_st.size();
		for (int i = 0; i < n - 1; i++) os << Q.pop_st[i].v << ' ';
		if (!Q.pop_st.empty()) {
			cout << Q.pop_st.back().v;
			if (!Q.push_st.empty()) {
				cout << ' ';
			}
		}
		n = Q.push_st.size();
		for (int i = n - 1; i > 0; i--) os << Q.push_st[i].v << ' ';
		if (!Q.push_st.empty()) cout << Q.push_st.front().v;
		return os;
	}
};