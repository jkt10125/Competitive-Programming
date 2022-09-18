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

void solve() 
{
	int n = input();
    vi A(n);
    cin >> A;
    int ctr = 1, lon_ctr = 1, var = A[0];
    for(int i=1; i<n; i++) {
        if(A[i] == A[i-1]) ctr++;
        else {
            if(ctr > lon_ctr) {
                lon_ctr = ctr;
                var = A[i-1];
                ctr = 1;
            }
        }
    }
    if(ctr > lon_ctr) {
        lon_ctr = ctr;
        var = A.back();
    }

    vb isdel(n);
    for(int i=1; i<n; i++) {
        if(A[i] != var && A[i-1] != var) {
            isdel[i] = isdel[i-1] = true;
            i++;
        }
    }
    
    cerr<<var<<"\n";
}

int main()
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