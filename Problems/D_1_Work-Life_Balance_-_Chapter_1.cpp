#include <bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i, a, b, c) for(int i=(int)a; i<=(int)b; i+=(int)c)
#define F0R(i, n) for(int i=0; i<(int)n; i++)
#define F1R(i, n) for(int i=1; i<=(int)n; i++)
#define FORn(i, a, b, c) for(int i=(int)a; i>=(int)b; i+=(int)c)
#define F0Rn(i, n) for(int i=(int)n-1; i>=0; i--)
#define F1Rn(i, n) for(int i=(int)n; i>=1; i--)
#define for_all(A) for(auto &it : A)

#define fastIO ios::sync_with_stdio(0); cin.tie(0)
#define output(a) { cout<<a; return; }

typedef vector<int> vi;
typedef vector<vi> vvi;
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
ostream& operator<<(ostream &os, const vT &v) {
	for_all(v) os << it << " ";
	return os;
}

ostream& operator<<(ostream &os, const bool &b) {
	(b) ? os << Yes : os << No;
	return os;
}

// !---> Code starts <---!

vi f(vi a, vi b) {
	vi c(4);
	F0R(i, 4) c[i] = a[i] + b[i];
	return c;
}

class SegTree {
    pair<int, int> range;
    vector<int> val;
    SegTree *left, *right;
  public:
    SegTree(vector<int> &A, pair<int, int> R) {
        range = R;
		val.assign(4, 0);
        if(R.first == R.second) { val[A[R.first]]++; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new SegTree(A, {R.first, mid});
            right = new SegTree(A, {mid+1, R.second});
            val = f(left->val, right->val);
        }
    }

    void update(int idx, int v) {
        if(range.first == range.second) {
            val = vi(4, 0);
			val[v]++;
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx, v);
        else left->update(idx, v);
		val = f(left->val, right->val);
    }

    vector<int> query(pair<int, int> R) {
        if(range == R) return val;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return f(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }

    void print() {
        cout<<range.first<<" "<<range.second<<" : "<<val<<endl;
        if(left) left->print();
        if(right) right->print();
    }
};

void solve() 
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	for(int i=1; i<=n; i++) cin >> a[i];
	SegTree A(a, {1, n});
	int q = 0;
	while(m--) {
		int x, y, z;
		cin >> x >> y >> z;
		A.update(x, y);
		vector<int> l = A.query({1, z});
		vector<int> r = A.query({z+1, n});

		int sl = 0, sr = 0;
		for(int i=0; i<4; i++) {
			sl += i * l[i];
			sr += i * r[i];
		}

		int diff = abs(sl - sr);
		if(diff & 1) { q--; continue; }
		else {
			int swaps = 0;
			if(sl > sr) {
				int s4 = 0;
				int req4 = diff / 4;
				int ach4 = min({req4, l[3], r[1]});
				l[3] -= ach4;
				r[1] -= ach4;
				s4 += ach4;
				diff = diff - ach4 * 4;

				int s2 = 0;
				int req2 = diff / 2;
				int ach2 = min({req2, l[3], r[2]});
				l[3] -= ach2;
				r[2] -= ach2;
				req2 -= ach2;
				s2 += ach2;
				diff = diff - ach2 * 2;

				ach2 = min({req2, l[2], r[1]});
				l[2] -= ach2;
				r[1] -= ach2;
				req2 -= ach2;
				s2 += ach2;
				diff = diff - ach2 * 2;

				if(diff != 0) { q--; continue; }
				else q += (s4 + s2);
			}
			else {
				int s4 = 0;
				int req4 = diff / 4;
				int ach4 = min({req4, r[3], l[1]});
				r[3] -= ach4;
				l[1] -= ach4;
				s4 += ach4;
				diff = diff - ach4 * 4;

				int s2 = 0;
				int req2 = diff / 2;
				int ach2 = min({req2, r[3], l[2]});
				r[3] -= ach2;
				l[2] -= ach2;
				req2 -= ach2;
				s2 += ach2;
				diff = diff - ach2 * 2;

				ach2 = min({req2, r[2], l[1]});
				r[2] -= ach2;
				l[1] -= ach2;
				req2 -= ach2;
				s2 += ach2;
				diff = diff - ach2 * 2;

				if(diff != 0) { q--; continue; }
				else q += (s4 + s2);
			}
		}
	}
	cout<<q;
}

signed main()
{
	fastIO;
	int t = 1;
	cin >> t;
	F1R(_i, t) {
		cout << "Case #" << _i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// !---> Code Ends <---!