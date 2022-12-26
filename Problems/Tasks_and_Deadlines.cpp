/*
**  Date: {{.date}} | Time: {{.time}}
**  User: JKT
*/

#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(0); cin.tie(0)

/* !---> input  operations <---! */

template <typename T, size_t n>
istream &operator >> (istream &is, array<T, n> &a) {
    for (size_t i = 0; i < n; i++) is >> a[i];
    return is;
} 

template <typename T>
istream &operator >> (istream &is, vector<T> &v) {
	for (T &x : v) is >> x;
	return is;
}

template <typename T, typename S>
istream &operator >> (istream &is, pair<T, S> &p) {
	is >> p.first >> p.second;
	return is;
}

/* !---> output operations <---! */

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
    for (size_t i = 0; i < n - 1; i++) {
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

template <typename T>
ostream &operator << (ostream &os, const deque<T> &v) {
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

/* !---> important constants & macros <---! */

#define F0R(i, n) for (int i = 0; i < n; i++)
#define F1R(i, n) for (int i = 1; i <= n; i++)

#define all(A) A.begin(), A.end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

template <size_t n, typename T = int>
using arr = array<T, n>;

const string out[] = {"NO", "YES"};

#define x64 long long

/* !---> code starts <---! */

void do_once() {
    /* Functions that are called only once */
    
}

void solve() {
    int n;
    cin >> n;
    vector<arr<2>> A(n);
    cin >> A;

    sort(A.begin(), A.end());
    x64 ans = 0, time_sum = 0;
    F0R(i, n) {
        time_sum += A[i][0];
        ans += (A[i][1] - time_sum);
    }

    cout << ans;
}

signed main() {
    fastIO;
    do_once();
    signed t = 1;
    // cin >> t;
    for (signed __ = 1; __ <= t; __++) {
        // cout << "Case #" << __ << ": ";
        solve();
    }
}

/* !--->  code ends  <---! */
