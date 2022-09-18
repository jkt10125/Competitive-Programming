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

#define mp make_pair
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

// !---> Code starts <---!


vi x, y, P;

int calculate(int i1, int i2) {
    int dist = abs(x[i1] - x[i2]) + abs(y[i1] - y[i2]);
    if(dist % P[i1]) return dist / P[i1] + 1;
    else return dist / P[i1];
}

void solve() 
{
	int n = input();
    x.resize(n);
    y.resize(n);
    P.resize(n);
    F0R(i, n) cin >> x[i] >> y[i] >> P[i];

    int ans = INT_MAX;

    vvi dist(n, vi(n, INT_MAX));
    F0R(i, n) {
        F0R(j, n) {
            if(i == j) continue;
            dist[i][j] = calculate(i, j);
        }
    }

    F0R(i, n) {
        vi tdist = dist[i];
        int idx = min_element(all(dist[i])) - dist[i].begin();
        F0R(j, n) {
            if(j == i) continue;
            if(j == idx) continue;
            int aa = dist[i][j];
            F0R(k, n) {
                aa = min(aa, dist[k][j]);
            }
            
        }
    }

    for_all(dist) cerr<<it<<"\n";
}

int main()
{
	fastIO;
	int t = 1;
	F1R(i, t) {
		// cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// !---> Code Ends <---!