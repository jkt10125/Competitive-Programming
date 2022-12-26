#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

#define F0R(i, n) for (size_t i = 0; i < n; i++)
#define F1R(i, n) for (size_t i = 1; i <= n; i++)

#define all(A) A.begin(), A.end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

template <size_t n, typename T = int>
using arr = array<T, n>;

const string out[] = {"NO", "YES"};

/* !---> code starts <---! */

void do_once() {
    /* Functions that are called only once */
    
}

void solve() {
    int n;
    cin >> n;
    vector<arr<3>> A(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        A[i] = {x, y, i};
    }

    sort(A.begin(), A.end(), [] (arr<3> a, arr<3> b) {
        if (a[0] == b[0]) return (a[1] > b[1]);
        return (a[0] < b[0]);
    });

    ordered_set<arr<2>> o;
    for (int i = 0; i < n; i++) {
        o.insert({A[i][1], A[i][2]});
    }

    vi A1(n), A2(n);
    for (int i = 0; i < n; i++) {
        o.erase({A[i][1], A[i][2]});
        A1[A[i][2]] = o.order_of_key({A[i][1] + 1, -1});
    }

    sort(A.begin(), A.end(), [] (arr<3> a,  arr<3> b) {
        if (a[1] == b[1]) return (a[0] < b[0]);
        return (a[1] > b[1]);
    });

    o.clear();
    F0R(i, n) {
        o.insert({A[i][0], A[i][2]});
    }
    for (int i = n - 1; i >= 0; i--) {
        o.erase({A[i][0], A[i][2]});
        A2[A[i][2]] = o.order_of_key({A[i][0], n});
    }

    cout << A1 << endl << A2;
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
