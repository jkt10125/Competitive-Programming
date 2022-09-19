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
#define output(a) { cout<<a; return; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

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

const int mod = 1000000007;

vector<pair<int, int>> factors(int n) {
	vector<pair<int, int>> factor(1);
	for(int i=2; i*i <= n; i++) {
		while(n % i == 0) {
			if(factor.back().first == i) factor.back().second++;
			else factor.push_back({i, 1});
			n /= i;
		}
	}
	if(n > 1) factor.push_back({n, 1});
	return factor;
}

int power(int a, int b, int mod=0) {
	int pow = 1;
	while(b > 0) {
		if(b & 1) pow *= a;
		b = b >> 1;	a *= a;
		if(mod) pow %= mod, a %= mod;
	}
	return pow;
}

int f(int n, int k, int a) {
    int exp = (power(2, k, mod-1) * a + 1) % (mod - 1);
    int aa = power(n, exp, mod);
    int b = power(n, a, mod);
    int num = (aa - b + mod) % mod;
    int den = power(n - 1, mod-2, mod);
    // cerr<<den % mod<<" ";
    return num * den % mod;
}

void solve() 
{
    int n, k;
    cin >> n >> k;
    vpii __factor = factors(n);
    int ans = 1;
    for(int i=1; i<(int)__factor.size(); i++) {
        ans = (ans * f(__factor[i].first, k, __factor[i].second)) % mod;
    }
    // for_all(__factor) cerr<<it.ff <<" "<<it.ss<<endl;
    cout<<ans;
    // cerr<<endl;
}

signed main()
{
	fastIO;
	int t = input<int>();
	F1R(i, t) {
		// cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// !---> Code Ends <---!