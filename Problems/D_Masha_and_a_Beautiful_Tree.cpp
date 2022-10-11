#include <bits/stdc++.h>
using namespace std;

// #define int long long

#define FOR(i, a, b, c) for(int i=(int)a; i<=(int)b; i+=(int)c)
#define F0R(i, n) for(int i=0; i<(int)n; i++)
#define F1R(i, n) for(int i=1; i<=(int)n; i++)
#define FORn(i, a, b, c) for(int i=(int)a; i>=(int)b; i+=(int)c)
#define F0Rn(i, n) for(int i=(int)n-1; i>=0; i--)
#define F1Rn(i, n) for(int i=(int)n; i>=1; i--)
#define for_all(A) for(auto &it : A)

#define fastIO ios::sync_with_stdio(0); cin.tie(0)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define vT vector<T>
#define vvT vector<vT>
#define pTT pair<T, T>
#define all(a) a.begin(), a.end()

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second

const string YES = "YES";
const string Yes = "Yes";
const string NO = "NO";
const string No = "No";

template <typename T>
istream& operator>>(istream &is, vT &v) {
	for_all(v) is >> it;
	return is;
}

template <typename T>
istream& operator>>(istream &is, pTT &p) {
	is >> p.ff >> p.ss;
	return is;
}

template <typename T>
ostream& operator<<(ostream &os, const vT &v) {
	for_all(v) os << it << ' ';
	return os;
}

template <typename T>
ostream& operator<<(ostream &os, const pTT &p) {
	os << p.ff << ' ' << p.ss;
	return os;
}

// !---> Code starts <---!

int c = 0, ctr = 0;

template <typename T, T (*func) (T, T)>
class SegTree {
  public:
    pair<int, int> range;
    T data;
    SegTree *left, *right;
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

    T query(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return func(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }

    void process() {
        if(left) {
            if(left->data > right-> data) {
                ctr++;
                swap(left, right);
            }
            left->process();
            right->process();
        }
    }

    void print() {
        if(range.first == range.second) {
            if(data != c) ctr = -1;
            c++;
        }
        if(left) left->print();
        if(right) right->print();
    }
};

int Max(int a, int b) {
    return (a > b) ? a : b;
}

void solve() {
    int n;
    cin >> n;
    vi A(n);
    cin >> A;
    c = 1, ctr = 0;

    SegTree<int, Max> t(A, {0, n-1});

    t.process();
    t.print();
    // if(!t.check()) ctr = -1;
    cout << ctr;

}

signed main()
{
	fastIO;
	int t = 1;
	cin >> t;
	F1R(_i, t) {
		// cout << "Case #" << _i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// !---> Code Ends <---!
