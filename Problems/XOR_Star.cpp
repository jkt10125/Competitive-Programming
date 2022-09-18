#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, c) for(int i=a; i<=b; i+=c)
#define F0R(i, n) FOR(i, 0, (int)n-1, 1)
#define F1R(i, n) FOR(i, 1, (int)n, 1)
#define FORn(i, a, b, c) for(int i=a; i>=b; i+=c)
#define F0Rn(i, n) FORn(i, (int)n-1, 0, -1)
#define F1Rn(i, n) FORn(i, (int)n, 1, -1)

#define space ' '
#define newl '\n'
#define ERROR throw("ERROR")

#define precision(a) cout << setprecision(a)
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL)

#define ui unsigned int
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second

#define vT vector<T>
#define vvT vector<vT>
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
#define mlli map<ll, int>
#define mill map<int, ll>
#define mllll map<ll, ll>
#define misi map<int, set<int>>
#define mivi map<int, vi>
#define mllvi map<ll, vi>
#define mllvll map<ll, vll>
#define msi map<string, int>
#define vpipii vector<pair<int, pii>>
#define vppiii vector<pair<pii, int>>
#define vvpipii vector<vpipii>

#define all(a) a.begin(), a.end()

template <typename T>
T RANDOM(T a, T b) {
    srand(time(NULL));
    return (rand() % (b-a+1)) + a;
}

template <typename T>
int SGN(T a) { return (a==0) ? 0 : (a>0) ? 1 : -1; } // signum function

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
        os << *it;
        if(it != --v.end()) os << " ";
    }
    os << "]\n";
    return os;
}

template <typename T>
ostream& operator<<(ostream &os, const deque<T> &v) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); it++) {
        os << *it;
        if(it != --v.end()) os << " ";
    }
    os << "]\n";
    return os;
}

template <typename T>
ostream& operator<<(ostream &os, const set<T> &s) {
    os << "[";
    for(auto it = s.begin(); it != s.end(); it++) {
        os << *it;
        if(it != --s.end()) os << " ";
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

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vll A(n);
    cin >> A;

    vi expo(63);
    F0R(i, n) {
        int ctr = 0;
        while(A[i]) {
            if(A[i] & 1) expo[ctr]++;
            A[i] >>= 1;
            ctr++;
        }
    }

    ll ans = 0;
    ll ctr = 1;
    F0R(i, 63) {
        ans += (expo[i] * 1ll * (n-expo[i]) * ctr) % MOD;
        ctr <<= 1;
    }
    cout<<ans;
    // cerr <<= expo;
}


int main()
{
	// fastIO;
	int t;
    cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
	return 0;
}