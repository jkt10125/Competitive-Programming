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

vvi A;
vpii sq;
int n, m;

void f(int x, int y) {
    queue<pii> Q;
    Q.push({x, y});
    while(!Q.empty()) {
        pii a = Q.front();
        Q.pop();
        for(pii p : sq) {
            if(a.ff+p.ff <= n) {
                if(a.ss+p.ss <= n) {
                    if(A[a.ff+p.ff][a.ss+p.ss] == -1) {
                        A[a.ff+p.ff][a.ss+p.ss] = A[a.ff][a.ss] + 1;
                        Q.push({a.ff+p.ff, a.ss+p.ss});
                    }
                }
                if(a.ss-p.ss >= 1) {
                    if(A[a.ff+p.ff][a.ss-p.ss] == -1) {
                        A[a.ff+p.ff][a.ss-p.ss] = A[a.ff][a.ss] + 1;
                        Q.push({a.ff+p.ff, a.ss-p.ss});
                    }
                }
            }
            if(a.ff-p.ff >= 1) {
                if(a.ss+p.ss <= n) {
                    if(A[a.ff-p.ff][a.ss+p.ss] == -1) {
                        A[a.ff-p.ff][a.ss+p.ss] = A[a.ff][a.ss] + 1;
                        Q.push({a.ff-p.ff, a.ss+p.ss});
                    }
                }
                if(a.ss-p.ss >= 1) {
                    if(A[a.ff-p.ff][a.ss-p.ss] == -1) {
                        A[a.ff-p.ff][a.ss-p.ss] = A[a.ff][a.ss] + 1;
                        Q.push({a.ff-p.ff, a.ss-p.ss});
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    int a = sqrt(m) + 4;
    for(int i=1; i<a; i++) {
        int r = m - i * i;
        if(r < 0) break;
        int v = sqrt(r);
        if(v * v == r) {
            sq.push_back({i, v});
            sq.push_back({v, i});
        }
    }

    A = vvi((n+1), vi(n+1, -1));
    A[1][1] = 0;
    f(1, 1);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

}

signed main()
{
	fastIO;
	int t = 1;
	// cin >> t;
	F1R(_i, t) {
		// cout << "Case #" << _i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// !---> Code Ends <---!
