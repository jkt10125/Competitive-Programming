#include <bits/stdc++.h>
using namespace std;

class MinMaxQUEUE {
	vector<array<int, 3>> push_st, pop_st;
	void transfer () {
		while (!push_st.empty()) {
			auto [a, b, c] = push_st.back();
			if (!pop_st.empty()) {
				b = std::min(b, pop_st.back()[1]);
				c = std::max(c, pop_st.back()[2]);
			}
			pop_st.push_back({a, b, c});
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

	void push (int a) {
		int b = a, c = a;
		if (!push_st.empty()) {
			b = std::min(b, push_st.back()[1]);
			c = std::max(c, push_st.back()[2]);
		}
		push_st.push_back({a, b, c});
	}

	void pop () {
		if (pop_st.empty()) transfer();
		pop_st.pop_back();
	}

	int min () {
		if (pop_st.empty()) return push_st.back()[1];
		if (push_st.empty()) return pop_st.back()[1];
		return std::min(push_st.back()[1], pop_st.back()[1]);
	}

	int max () {
		if (pop_st.empty()) return push_st.back()[2];
		if (push_st.empty()) return pop_st.back()[2];
		return std::max(push_st.back()[2], pop_st.back()[2]);
	}

	int front () {
		if (pop_st.empty()) transfer();
		return pop_st.back()[0];
	}

	friend ostream & operator << (ostream &os, const MinMaxQUEUE &Q) {
		int n = Q.pop_st.size();
		for (int i = 0; i < n - 1; i++) os << Q.pop_st[i][0] << ' ';
		if (!Q.pop_st.empty()) {
			cout << Q.pop_st.back()[0];
			if (!Q.push_st.empty()) {
				cout << ' ';
			}
		}
		n = Q.push_st.size();
		for (int i = n - 1; i > 0; i--) os << Q.push_st[i][0] << ' ';
		if (!Q.push_st.empty()) cout << Q.push_st.front()[0];
		return os;
	}
};