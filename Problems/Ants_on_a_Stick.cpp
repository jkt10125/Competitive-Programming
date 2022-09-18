#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, c) for(int i=(int)a; i<=(int)b; i+=(int)c)
#define F0R(i, n) for(int i=0; i<(int)n; i++)
#define F1R(i, n) for(int i=1; i<=(int)n; i++)
#define FORn(i, a, b, c) for(int i=(int)a; i>=(int)b; i+=(int)c)
#define F0Rn(i, n) for(int i=(int)n-1; i>=0; i--)
#define F1Rn(i, n) for(int i=(int)n; i>=1; i--)
#define for_all(i, A) for(auto &i : A)

#define space ' '
#define newl '\n'
#define ERROR throw("ERROR")

#define precision(a) cout << setprecision(a)
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL)

#define ll long long
#define ld long double
#define ull unsigned long long

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second

#define vT vector<T>
#define vvT vector<vT>
#define dqT deque<T>

#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvll vector<vll>
#define si set<int>
#define sll set<ll>
#define dqi deque<int>
#define dqll deque<ll>
#define pii pair<int, int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int, int>
#define mllll map<ll, ll>
#define misi map<int, set<int>>
#define mivi map<int, vi>
#define mllvi map<ll, vi>
#define mllvll map<ll, vll>
#define msi map<string, int>
#define ppiii pair<pii, int>
#define vpipii vector<pair<int, pii>>
#define vppiii vector<pair<pii, int>>
#define vvpipii vector<vpipii>

#define all(a) a.begin(), a.end()

template <typename T>
int SGN(T a) { return (a==0) ? 0 : (a>0) ? 1 : -1; }

template <typename T>
void SWAP(T &a, T &b) { T t = a; a = b; b = t; }

template <typename T>
T MAX(T a, T b) { return (a > b) ? a : b; }

template <typename T>
T MIN(T a, T b) { return (a < b) ? a : b; }

//OUTPUT FUNCTIONS
template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); it++) {
        os << *it; if(it != --v.end()) os << " ";
    } 
    os << "]\n";
    return os;
}

template <typename T>
ostream& operator<<(ostream &os, const deque<T> &v) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); it++) {
        os << *it; if(it != --v.end()) os << " ";
    }
    os << "]\n";
    return os;
}

template <typename T>
ostream& operator<<(ostream &os, const set<T> &s) {
    os << "[";
    for(auto it = s.begin(); it != s.end(); it++) {
        os << *it; if(it != --s.end()) os << " ";
    }
    os << "]\n";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream &os, const map<T, S> &m) {
    for(auto it : m) {
        os << it.first << " : " << it.second << "\n";
    }
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream &os, const pair<T, S> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

// INPUT FUNCTIONS
template <typename T, typename S>
istream& operator>>(istream &is, pair<T, S> &p) {
    is >> p.first >> p.second;
    return is;
}

template <typename T>
istream& operator>>(istream &is, vector<T> &v) {
    for(auto &it : v) is >> it;
    return is;
}

const ll MOD = 1e9 + 7;
const ld PI = 2*acos(0);

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.ff == b.ff) return a.ss < b.ss;
    return a.ff < b.ff;
}

void solve() 
{
    ll n, l;
    cin >> n >> l;
    vppiii A(n);
    F0R(i, n) {
        ll x, y;
        cin >> x >> y;
        A[i] = {{x, y}, i};
    }

    sort(all(A));
    vpii Time(n);
    F0Rn(i, n) {
        if(A[i].ff.ss == 0) {
            int ctr = 0;
            F0R(j, i) ctr += A[j].ff.ss;

            Time[i - ctr] = {A[i].ff.ff, A[i-ctr].ss};
        }
    }

    F0R(i, n) {
        if(A[i].ff.ss) {
            int ctr = 0;
            FOR(j, i+1, n-1, 1) ctr += (1 - A[j].ff.ss);

            Time[i + ctr] = {l - A[i].ff.ff, A[i+ctr].ss};
        }
    }
    sort(all(Time), cmp);
    // cerr << Time;
    for_all(it, Time) {
        cout <<it.ss + 1<<" ";
    }
}

int main()
{
	fastIO;
    int t;
    cin >> t;
    F0R(i, t) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
	return 0;
}
