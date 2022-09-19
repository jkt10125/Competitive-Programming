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

void dfs(int n, vector<int> &lvl, vvi &A) {
    for(int it : A[n]) {
        if(lvl[it] == -1) {
            lvl[it] = lvl[n] + 1;
            dfs(it, lvl, A);
        }
    }
}

void solve() 
{
	int n, q;
    cin >> n >> q;
    vector<vector<int>> A(n+1);
    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    for(int i=0; i<q; i++) {
        int x;
        cin >> x;
    }
    vector<int> lvl(n+1, -1);
    lvl[1] = 0;
    dfs(1, lvl, A);
    map<int, int> M;
    F1R(i, n) M[lvl[i]]++;
    int ctr = 0, ans = 0;
    while(true) {
        if(M[ctr] > q) break;
        if(!M[ctr]) break;
        q = q - M[ctr];
        ans += M[ctr];
        ctr++;
    }
    cout<<ans;
}

signed main()
{
	fastIO;
	int t = 1;
	cin >> t;
	F1R(_i, t) {
		cout << "Case #" << _i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// !---> Code Ends <---!