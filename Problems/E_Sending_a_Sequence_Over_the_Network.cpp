#include <bits/stdc++.h>
using namespace std;

// #define int long long

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

#define vT vector<T>
#define vvT vector<vT>
#define pTT pair<T, T>
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
istream& operator>>(istream &is, vT &v) {
	for_all(v) is >> it;
	return is;
}

template <typename T>
istream& operator>>(istream &is, pTT &p) {
	is >> p.ff >> p.ss;
	return is;
}

template <typename T>
ostream& operator<<(ostream &os, const vT &v) {
	for_all(v) os << it << ' ';
	return os;
}

template <typename T>
ostream& operator<<(ostream &os, const pTT &p) {
	os << p.ff << ' ' << p.ss;
	return os;
}

// !---> Code starts <---!

void solve() {
	int n;
    cin >> n;
    vi A(n);
    cin >> A;

    vi dp(n, 0), dp_rev(n, 0);
    dp[n-1] = 0; dp_rev[0] = 0;
    for(int i=n-2; i>=0; i--) {
        if(A[i] + i >= n) dp[i] = 0;
        else if(A[i] + i == n-1) dp[i] = 1;
        else dp[i] = dp[i + A[i] + 1];
    }

    for(int i=1; i<n; i++) {
        if(i - A[i] < 0) dp_rev[i] = 0;
        else if(i - A[i] == 0) dp_rev[i] = 1;
        else dp_rev[i] = dp_rev[i - A[i] - 1];
    }

    if(dp[0] || dp_rev[n-1]) cout<<"YES";
    else {
        int a = false;
        for(int i=1; i<n; i++) {
            if(dp[i] && dp_rev[i-1]) a = true;
        }
        if(a) cout<<"YES";
        else cout<<"NO";
    }

    cerr<<dp<<endl<<dp_rev<<endl;
}

signed main()
{
	fastIO;
	int t = 1;
	cin >> t;
	F1R(_i, t) {
		// cout << "Case #" << _i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// !---> Code Ends <---!
