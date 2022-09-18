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

class jkt_ka_data {
    public:
    int curr_sum, prefix, suffix, max_sum;
    jkt_ka_data(int a=0, int b=0, int c=0, int d=0) : curr_sum(a), prefix(b), suffix(c), max_sum(d) {}
};

jkt_ka_data func(jkt_ka_data L, jkt_ka_data R) {
    jkt_ka_data C;
    C.curr_sum = L.curr_sum ^ R.curr_sum;
    C.prefix = max(L.prefix, L.curr_sum ^ R.prefix);
    C.suffix = max(R.suffix, R.curr_sum ^ L.suffix);
    C.max_sum = max(max(L.max_sum, R.max_sum), L.suffix ^ R.prefix);
    return C;
}

class SegTree {
    pii R;
    jkt_ka_data D;
    SegTree *left, *right;
  public:
    SegTree(vi &A, pii range) {
        R = range;
        if(R.ff == R.ss) {
            D = jkt_ka_data(A[R.ff], A[R.ff], A[R.ff], A[R.ff]);
            left = right = NULL;
        }
        else {
            int mid = (R.ff + R.ss) / 2;
            left = new SegTree(A, mp(R.ff, mid));
            right = new SegTree(A, mp(mid+1, R.ss));
            D = func(left->D, right->D);
        }
    }

    jkt_ka_data query(pii range) {
        if(R == range) return D;
        int mid = (R.ff + R.ss) / 2;
        if(range.ff > mid) return right->query(range);
        else if(range.ss <= mid) return left->query(range);
        else return func(left->query(mp(range.ff, mid)), right->query(mp(mid+1, range.ss)));
    }
};

void solve() 
{
    int n = input();
    vi A(n); cin >> A;
    SegTree T(A, mp(0, n-1));
    cout << T.query(mp(0, n-1)).max_sum;
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