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

ll mod = 1000000007;

void solve() 
{
	int n = input();
    vi A(n);
    F0R(i, n) {
        A[input()] = i;
    }
    if(n == 1) output(1)
    
    int left = min(A[0], A[1]), right = max(A[0], A[1]);
    vb fixed(n, 0);
    fixed[0] = fixed[1] = true;
    
    for(int i=2; i<n; i++) {
        if(A[i] < right && A[i] > left) { }
        else {
            fixed[i] = true;
            if(A[i] > right) right = A[i];
            else left = A[i];
        }
    }

    int fixed_counter = 2;
    left = min(A[0], A[1]), right = max(A[0], A[1]);
    vi choices(n, 1);
    for(int i=2; i<n; i++) {
        if(!fixed[i]) {
            choices[i] = right - left + 1 - fixed_counter;
        }
        else {
            if(A[i] > right) right = A[i];
            else left = A[i];
            fixed_counter++;
        }
    }
    // cerr<<choices<<"\n";
    ll ans = 1;
    int ctr = 0;
    for(int i=2; i<n; i++) {
        if(!fixed[i]) {
            ans *= (choices[i] - ctr++);
            ans %= mod;
        }
    }
    cout<<ans;
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