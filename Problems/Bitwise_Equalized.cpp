#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, c) for(int i=(int)a; i<=(int)b; i+=(int)c)
#define F0R(i, n) for(int i=0; i<(int)n; i++)
#define F1R(i, n) for(int i=1; i<=(int)n; i++)
#define FORn(i, a, b, c) for(int i=(int)a; i>=(int)b; i+=(int)c)
#define F0Rn(i, n) for(int i=(int)n-1; i>=0; i--)
#define F1Rn(i, n) for(int i=(int)n; i>=1; i--)
#define for_all(A) for(auto &it : A)

#define space ' '
#define newl '\n'
#define ERROR throw("ERROR")

#define precision(a) cout << setprecision(a)
#define fastIO ios::sync_with_stdio(0); cin.tie(0)

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
#define msi map<string, int>
#define ppiipii pair<pii, pii>
#define vpipii vector<pair<int, pii>>
#define vppiii vector<pair<pii, int>>
#define vvppiii vector<vppiii>
#define vvppiipii vector<vector<ppiipii>>

#define all(a) a.begin(), a.end()

template <typename T>
int SGN(T a) { return (a == 0) ? 0 : (a > 0) ? 1 : -1; }

template <typename T>
void SWAP(T &a, T &b) { T t = a; a = b; b = t; }

template <typename T>
T MAX(T a, T b) { return (a > b) ? a : b; }

template <typename T>
T MIN(T a, T b) { return (a < b) ? a : b; }

template <typename T>
T SUM(T a, T b) { return (a + b); }

template <typename T>
T GCD(T a, T b) { return (b == 0) ? a : GCD(b, a % b); }

template <typename T>
T LCM(T a, T b) { return (a / GCD(a, b)) * b; }

template <typename T = int>
T input() { T a; cin >> a; return a; }

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

template <typename T>
istream& operator>>(istream &is, deque<T> &d) {
    for(auto &it : d) is >> it;
    return is;
}

// CONSTANTS
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ld PI = 2 * acos(0);

// REAL WORK STARTS FROM HERE

template <typename T>
T Extended_GCD(T a, T b, T &x, T &y) {
	if(b == 0) { x=1; y=0; return a; }
	T x1, y1, hcf;
	hcf = Extended_GCD(b, a % b, x1, y1);
	x = y1; y = x1 - y1 * (a / b);
	return hcf;
}

template <typename T>
T POWER(T a, T b, ll mod=0) {	
	T pow = 1;
	while(b > 0) {
		if(b & 1) pow *= a;
		b = b >> 1;	a = a * a;
		if(mod) { pow %= mod; a %= mod; }
	}
	return pow;
}

ll temp;

void solve() 
{
    ll n;
    cin >> n;
    ll z = 0, nz = 0;
    F0R(i, n) { input<ll>() ? nz++ : z++; }
    
    ll ans = (nz + POWER(2ll, z, MOD2) + MOD2 - 1ll) % MOD2;
    ll pown = (POWER(2ll, n, MOD2) - 1ll + MOD2) % MOD2;
    ll gcd = GCD(ans, pown);
    // ans /= gcd; pown /= gcd;
    ll mmi = -10125;
    Extended_GCD(pown, MOD2, mmi, temp);
    mmi = (mmi + MOD2) % MOD2;
    ans = (ans * mmi) % MOD2;
    cout << ans;
}

int main()
{
	fastIO;
    int t;
    cin >> t;
    F0R(i, t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
	return 0;
}

// Okay Done :)