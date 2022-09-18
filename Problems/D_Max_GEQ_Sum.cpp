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

class segtree {
    pii range;
    ll data;
    segtree *left, *right;
    public:
    segtree(vi &A, pii R) {
        range = R;
        if(R.ff == R.ss) {
            data = A[R.ff];
            left = right = NULL;
        }
        else {
            int mid = (R.ff + R.ss) / 2;
            left = new segtree(A, mp(R.ff, mid));
            right = new segtree(A, mp(mid+1, R.ss));
            data = left->data + right->data;
        }
    }

    ll query(pii R) {
        if(range == R) return data;
        int mid = (range.ff + range.ss) / 2;
        if(R.ff > mid) return right->query(R);
        else if(R.ss <= mid) return left->query(R);
        else return left->query(mp(R.ff, mid)) + right->query(mp(mid+1, R.ss));
    }
};

bool is_valid(vi &A) {
    int n = A.size();
    segtree T(A, mp(0, A.size()-1));
    vi idx;
    idx.pb(0);
    F1R(i, n-1) { if(A[i] >= A[idx.back()]) idx.pb(i); }


}

void solve() 
{
    int n = input();
    vi A(n); cin >> A;
    segtree T(A, mp(0, n-1));

    vi idx;
    idx.pb(0);
    F1R(i, n-1) { if(A[i] >= A[idx.back()]) idx.pb(i); }
    cerr << idx <<endl;
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