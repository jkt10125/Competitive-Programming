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

pii func(pii a, pii b) {
    if(a.ff > b.ff) return a;
    return b;
}

template <typename T>
class SegTree {
    pair<int, int> range;
    T data_gcd;
    pii data_max;
    SegTree *left, *right;
  public:
    SegTree(vector<T> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            data_gcd = A[R.first];
            data_max = {A[R.first], R.first};
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new SegTree(A, {R.first, mid});
            right = new SegTree(A, {mid+1, R.second});
            data_gcd = __gcd(left->data_gcd, right->data_gcd);
            data_max = func(left->data_max, right->data_max);
        }
    }

    T GCD(pair<int, int> R) {
        if(R.ss < R.ff) return 0;
        if(range == R) return data_gcd;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->GCD(R);
        else if(R.second <= mid) return left->GCD(R);
        return __gcd(left->GCD({R.first, mid}), right->GCD({mid+1, R.second}));
    }
    
    pii MAX(pair<int, int> R) {
        if(R.ss < R.ff) return mp(INT_MIN, 10125);
        if(range == R) return data_max;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->MAX(R);
        else if(R.second <= mid) return left->MAX(R);
        return func(left->MAX({R.first, mid}), right->MAX({mid+1, R.second}));
    }
};

SegTree<int> *T = nullptr;

int MXDV(int l, int r) {
    pii A = T->MAX({l, r});
    pii Aa = T->MAX({l, A.ss-1});
    pii Ab = T->MAX({A.ss+1, r});
    pii Ac = func(Aa, Ab);
    int B = __gcd(T->GCD({l, A.ss-1}), T->GCD({A.ss+1, r}));
    int C = __gcd(T->GCD({l, Ac.ss-1}), T->GCD({Ac.ss+1, r}));
    return max(A.ff - B, Ac.ff - C);
}


bool f(int len, int n, int k) {
    for(int i=0; i<n-len; i++) {
        if(MXDV(i, i+len) >= k) return true;
    }
    return false;
}


void solve() 
{
	int n, k;
    cin >> n >> k;
    vi A(n);
    cin >> A;
    
    if(n == 2) {
        if(abs(A[0] - A[1]) >= k) output(2)
        else output(-1)
    }
    T = new SegTree<int>(A, {0, n-1});

    int l = 1, r = n-1;
    int ans_len = -1;
    while(l <= r) {
        int len = (l + r) / 2;
        if(f(len, n, k)) { ans_len = len; r = len-1; }
        else l = len+1;
    }
    if(ans_len == -1) output(-1)
    cout<<ans_len+1; 
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