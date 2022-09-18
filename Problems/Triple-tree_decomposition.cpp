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
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define vT vector<T>
#define vvT vector<vT>
#define all(a) a.begin(), a.end()

#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second

template <typename T>
int sgn(T a) { return (a == 0) ? 0 : (a > 0) ? 1 : -1; } 

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

// Real Work starts from here

void solve() 
{
    int n = input();
    vvi tree(n+1);
    vb par(n+1, true); par[0] = false;
    F0R(i, n-1) {
        int u = input();
        int v = input();
        // cerr << u <<" "<< v << endl;
        tree[u].pb(v);
        par[v] = false;
    }
    
    if((n-1) % 3) { cout << "NO\n"; return; }
    
    int parnt = 2;
    F1R(i, n) if(par[i]) parnt = i;
    // cerr << par;

    vvi ans;
    queue<int> Q;
    Q.push(parnt);
    while(!Q.empty()) {
        int a = Q.front(); Q.pop();
        if(tree[a].size() % 3) { cout << "NO\n"; return; }
        vi A(4); A[0] = a;
        FOR(i, 0, tree[a].size()-1, 3) {
            A[1] = tree[a][i];
            A[2] = tree[a][i+1];
            A[3] = tree[a][i+2];
            ans.pb(A);
        }
        for_all(tree[a]) Q.push(it);
    }
    cout << "YES\n";
    for_all(ans) cout << it << endl;
}

int main()
{
	fastIO;
    int t = input();
    F0R(i, t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
        // cout << endl;
    }
	return 0;
}