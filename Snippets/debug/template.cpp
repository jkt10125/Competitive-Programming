#include <bits/stdc++.h>
using namespace std;

// #define int long long

#define fastIO ios::sync_with_stdio(0); cin.tie(0)

const string YES = "YES";
const string Yes = "Yes";
const string NO = "NO";
const string No = "No";

template <typename T>
istream &operator >> (istream &is, vector<T> &v) {
	for (T &x : v) is >> x;
	return is;
}

template <typename T, size_t n>
istream &operator >> (istream &is, array<T, n> &a) {
    for (int i = 0; i < n; i++) is >> a[i];
    return is;
} 

template <typename T, typename S>
istream &operator >> (istream &is, pair<T, S> &p) {
	is >> p.first >> p.second;
	return is;
}

template <typename T>
ostream &operator << (ostream &os, const set<T> &s) {
    for (auto it = s.begin(); it != s.end(); it++) {
        os << *it;
        if (it != (--s.end())) {
            os << ' ';
        }
    }
    return os;
}

template <typename T, size_t n>
ostream &operator << (ostream &os, const array<T, n> &a) {
    for (int i = 0; i < n - 1; i++) {
        os << a[i] << ' ';
    }
    os << a[n - 1];
    return os;
}

// template <typename T>
// ostream &operator << (ostream &os, const ordered_set<T> &s) {
//     for (auto it = s.begin(); it != s.end(); it++) {
//         os << *it;
//         if (it != (--s.end())) {
//             os << ' ';
//         }
//     }
//     return os;
// }

template <typename T>
ostream &operator << (ostream &os, const multiset<T> &s) {
    for (auto it = s.begin(); it != s.end(); it++) {
        os << *it;
        if (it != (--s.end())) {
            os << ' ';
        }
    }
    return os;
}

template <typename T>
ostream &operator << (ostream &os, const vector<T> &v) {
	for (auto it = v.begin(); it != v.end(); it++) {
        os << *it;
        if (it != (--v.end())) {
            os << ' ';
        }
    }
	return os;
}

template <typename T, typename S>
ostream &operator << (ostream &os, const pair<T, S> &p) {
	os << p.first << ' ' << p.second;
	return os;
}

template <typename T, typename S>
ostream &operator << (ostream &os, const map<T, S> &m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        os << it->first << " : " << it->second;
        if (it != (m.end())) {
            os << '\n';
        }
    }
    return os;
}

ostream &operator << (ostream &os, const bool &b) {
    os << ((b) ? YES : NO);
    return os;
}

/* !---> code starts <---! */

void precompute() {

}

void solve() {

}

signed main() {
    fastIO();
    precompute();
    signed t = 1;
    cin >> t;
    for (signed __ = 1; __ <= t; __++) {
        // cout << "Case #" << __ << ": ";
        solve();
    }
}

/* !--->  code ends  <---! */