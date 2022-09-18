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

template <typename T>
class LazySegTree {
    T value;
    pair<int, int> range;
    LazySegTree *left, *right;
    public:
    LazySegTree(vector<T> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            value = A[R.first];
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new LazySegTree(A, {R.first, mid});
            right = new LazySegTree(A, {mid+1, R.second});
            value = 0;
        }
    }

    void push() {
        if(!value) return;
        if(range.first == range.second) return;
        left->value += value;
        right->value += value;
        value = 0;
    }

    void update(pair<int, int> R, T val) {
        if(range == R) {
            value += val;
            return;
        }
        push();
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) right->update(R, val);
        else if(R.second <= mid) left->update(R, val);
        else {
            left->update({R.first, mid}, val);
            right->update({mid+1, R.second}, val);
        }
    }

    T value_at_index(int idx) {
        if(range.first == range.second) return value;
        push();
        int mid = (range.first + range.second) / 2;
        if(idx > mid) return right->value_at_index(idx);
        else return left->value_at_index(idx);
    }
};

void solve() 
{
	int n = input();
    vi tmp(n);
    vb honest(n, false);
    LazySegTree<int> A(tmp, {0, n-1});
    for(int i=0; i<n; i++) {
        pii r;
        cin >> r.ff >> r.ss;
        r.ff--; r.ss--;
        if((i >= r.ff) && (i <= r.ss)) honest[i] = true;
        A.update(r, 1);
    }
    vi ans;
    for(int i=0; i<n; i++) if(A.value_at_index(i) == n-1 && !honest[i]) ans.pb(i+1);
    cout<<ans.size()<<"\n";
    for(int i : ans) cout<<i<<"\n";
}

int main()
{
	fastIO;
	int t = input<int>();
	F1R(i, t) {
		// cout << "Case #" << i << ": ";
		solve();
		// cout << endl;
	}
	return 0;
}

// !---> Code Ends <---!