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
	int n = input();
    vi A(n);
    cin >> A;
    ll sum = 0;
    F0R(i, n) sum += A[i];
    vll psum(n, 0);
    psum[0] = A[0];
    F1R(i, n-1) psum[i] = psum[i-1] + A[i];

    int q = input();
    vpii Q(q);
    F0R(i, q) {
        cin >> Q[i].ff;
        Q[i].ss = i;
    }
    sort(all(Q));

    vi ans(q);
    int ctr = 0;
    ll temp = 0;
    F0R(i, q) {
        if(ctr >= n) break;
        while((ctr+1)*1ll*Q[i].ff >= psum[ctr] && ctr < n) {
            ctr++;
        }
        if(ctr < n) ans[Q[i].ss] = -1;
        else break;
    }

    F0R(i, q) {
        if(ans[Q[i].ss] == -1) continue;
        else {
            ll tmp = sum / Q[i].ff;
            if(sum % Q[i].ff != 0) tmp++;
            ans[Q[i].ss] = tmp;
        }
    }
    F0R(i, q) cout << ans[i] << endl;
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