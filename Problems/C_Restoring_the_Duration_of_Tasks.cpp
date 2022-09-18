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
    int n;
    cin >> n;
    vi S(n), F(n);
    cin >> S >> F;

    vi ans(n);
    for(int i=0; i<n; i++) {
        if(i == 0) {
            ans[i] = F[i] - S[i];

        } else {
            ans[i] = F[i] - max(F[i-1], S[i]);
        }
    }

    F0R(i, n) cout << ans[i]<< " ";
}

int main()
{
	fastIO;
    int t = input();
    F0R(i, t) {
        // cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
	return 0;
}

// !---> Code Ends <---!