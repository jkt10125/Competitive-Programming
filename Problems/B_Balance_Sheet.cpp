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
ostream& operator<<(ostream &os, const vT &v) {
	for_all(v) os << it << " ";
	return os;
}

ostream& operator<<(ostream &os, const bool &b) {
	(b) ? os << Yes : os << No;
	return os;
}

// !---> Code starts <---!

bool cmp(pii a, pii b) {
	return a.ss < b.ss;
}

void solve() 
{
	int n, k;
	cin >> n >> k;
	map<int, vpii> B, S;
	for(int i=1; i<=n; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		B[a].pb({i, x});
		S[b].pb({i, y});
	}
	// now we need to make a profit tree
	vvpii A(n+1);
	for_all(B) sort(all(it.ss), cmp);
	for_all(S) sort(all(it.ss), cmp);

	for_all(B) {
		cerr<<it.ff<<" : ";
		for(auto it1 : it.ss) cerr<<"{"<<it1.ff<<", "<<it1.ss<<"} ";
		cerr<<endl;
	}
	cerr<<endl;

	for_all(S) {
		cerr<<it.ff<<" : ";
		for(auto it1 : it.ss) cerr<<"{"<<it1.ff<<", "<<it1.ss<<"} ";
		cerr<<endl;
	}
	cerr<<endl;
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