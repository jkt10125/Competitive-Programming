#include <bits/stdc++.h>
using namespace std;
#define int long long

#define FOR(i, a, b, c) for(int i=(int)a; i<=(int)b; i+=(int)c)
#define F0R(i, n) for(int i=0; i<(int)n; i++)
#define F1R(i, n) for(int i=1; i<=(int)n; i++)
#define FORn(i, a, b, c) for(int i=(int)a; i>=(int)b; i+=(int)c)
#define F0Rn(i, n) for(int i=(int)n-1; i>=0; i--)
#define F1Rn(i, n) for(int i=(int)n; i>=1; i--)
#define for_all(A) for(auto &it : A)

#define fastIO ios::sync_with_stdio(0); cin.tie(0)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define all(a) a.begin(), a.end()

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second

const string YES = "YES";
const string Yes = "Yes";
const string NO = "NO";
const string No = "No";

template <typename T>
istream &operator >> (istream &is, vector<T> &v) {
	for_all (v) is >> it;
	return is;
}

template <typename T, typename S>
istream &operator >> (istream &is, pair<T, S> &p) {
	is >> p.ff >> p.ss;
	return is;
}

template <typename T>
ostream &operator << (ostream &os, const set<T> &s) {
    for (auto it = s.begin(); it != s.end(); it++) {
        os << *it;
        if (it != (--s.end())) {
            cout << ' ';
        }
    }
    return os;
}

template <typename T>
ostream &operator << (ostream &os, const vector<T> &v) {
	for (auto it = v.begin(); it != v.end(); it++) {
        os << *it;
        if (it != (--v.end())) {
            cout << ' ';
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
        os << it->first << ' : ' << it->second;
        if (it != (--m.end())) {
            cout << '\n';
        }
    }
    return os;
}
