#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b, c) for(int i=(int)a; i<=(int)b; i+=(int)c)
#define F0R(i, n) for(int i=0; i<(int)n; i++)
#define F1R(i, n) for(int i=1; i<=(int)n; i++)
#define FORn(i, a, b, c) for(int i=(int)a; i>=(int)b; i+=(int)c)
#define F0Rn(i, n) for(int i=(int)n-1; i>=0; i--)
#define F1Rn(i, n) for(int i=(int)n; i>=1; i--)
#define for_all(A) for(auto &it : A)

#define fastIO ios::sync_with_stdio(0); cin.tie(0)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;

#define vT vector<T>
#define vvT vector<vT>
#define all(a) a.begin(), a.end()

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second

template <typename T = int>
T input() { T a; cin >> a; return a; }

template <typename T>
istream& operator>>(istream &is, vT &v) {
	for_all(v) is >> it;
	return is;
}

template <typename T>
ostream& operator<<(ostream &os, const vT &v) {
	for_all(v) os << it << " ";
	return os;
}

// !---> Code starts <---!
const int N = 5e4 + 1;

ll n, m, k;
vi a(N), b(N);

vpll func(vi &a, int n) {
    vpll A;
    for(int i=0; i<n; i++) {
        ll tmp = m;
        while(a[i] % tmp == 0) tmp = tmp * m;
        tmp /= m;
        if(A.size() == 0) A.pb({a[i]/tmp, tmp});
        else if(A.back().ff == a[i]/tmp) A.back().ss += tmp;
        else A.pb({a[i]/tmp, tmp});
    }
    return A;
}

void solve() 
{

	cin >> n >> m;
    F0R(i, n) cin >> a[i];
    cin >> k;
    F0R(i, k) cin >> b[i];

    if(func(a, n) == func(b, k)) cout<<"Yes";
    else cout<<"No";
}

int main()
{
	fastIO;
	int t = input();
	F1R(i, t) {
		// cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// !---> Code Ends <---!