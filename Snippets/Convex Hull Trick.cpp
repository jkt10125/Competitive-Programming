#include <bits/stdc++.h>
using namespace std;

#define int long long
struct line {
	mutable int m, c, p, isline;
	bool operator < (const line &L) const {
        return ((L.isline) ? (m < L.m) : (p < L.p));
    }
};
 
struct CHT : multiset<line> {
	int mode;
	CHT () {
        mode = 1;
    }
	inline void set_mode (string s) {
        transform (s.begin(), s.end(), s.begin(), ::tolower);
        if (s == "min") mode = -1;
    }
	int div (int a, int b) {
        return (a / b - ((a ^ b) < 0 && a % b));
    }
	bool isect (iterator x, iterator y){
		if (y == end()) {
            x->p = INT_MAX;
            return false;
        }
		x->p = (x->m == y->m) ? (x->c > y->c) ? INT_MAX : INT_MIN : div ((y->c - x->c), (x->m - y->m));
        return (x->p >= y->p);
	}
	void add (int sl, int in) {
		auto z = insert({mode * sl, mode * in, 0, 1});
        auto y = z++;
        auto x = y;
		while (isect(y, z)) {
            z = erase(z);
        }
		if(x != begin() && isect(--x, y)) {
            isect(x, y = erase(y));
        }
		while((y=x) != begin() && (--x)->p >= y->p)	{
            isect(x, erase(y));
        }
	}
	int query (int x) {
		assert (!empty());
		auto l = *lower_bound({0, 0, x, 0});
		return mode * (l.m * x + l.c);
	}
};