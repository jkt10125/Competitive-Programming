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


void solve() 
{
    vi row(4), col(4);
    F1R(i, 3) cin >> row[i];
    F1R(i, 3) cin >> col[i];
    if(accumulate(all(row), 0) != accumulate(all(col), 0)) {
        cout << "0";
        return;
    }
    ll ans = 0;
    int a3, b1, b3, c1, c2;
    F1R(a1, 30) {
        F1R(a2, 30) {
            F1R(b2, 30) {
                F1R(c3, 30) {
                    a3 = row[1] - a1 - a2;
                    b3 = col[3] - a3 - c3;
                    c2 = col[2] - a2 - b2;
                    b1 = row[2] - b2 - b3;
                    c1 = row[3] - c3 - c2;

                    if(a1 > 0 && a2 > 0 && a3 > 0 && b1 > 0 && b2 > 0 && b3 > 0 && c1 > 0 && c2 > 0 && c3 > 0) {
                        ans += 1;
                    }
                }
            }
        }
    }
    cout<<ans;
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