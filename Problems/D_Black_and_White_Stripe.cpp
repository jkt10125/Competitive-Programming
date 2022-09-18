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


template <typename T>
T func(T a, T b) {
    return a + b;
}

template <typename T, T (*func) (T, T)>
class SegTree {
    pair<int, int> range;
    T data;
    SegTree *left, *right;
  public:
    SegTree(vector<T> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) { data = A[R.first]; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new SegTree(A, {R.first, mid});
            right = new SegTree(A, {mid+1, R.second});
            data = func(left->data, right->data);
        }
    }

    void update(int idx, int val) {
        if(range.first == range.second) {
            data = val;
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx, val);
        else left->update(idx, val);
        data = func(left->data, right->data);
    }

    T query(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return func(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }

    void print() {
        cout<<range.first<<" "<<range.second<<" : "<<data<<endl;
        if(left) left->print();
        if(right) right->print();
    }
};



void solve() 
{
    int n, k;
    cin >> n >> k;
    vi A(n);
    string s;
    cin >> s;
    for(int i=0; i<n; i++) {
        A[i] = (s[i] == 'B') ? 0 : 1;
    }
    SegTree<int, func> st(A, {0, n-1});
    int ans = INT_MAX;
    for(int i=0; i<n-k+1; i++) {
        ans = min(ans, st.query({i, i+k-1}));
    }
    cout<<ans;
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