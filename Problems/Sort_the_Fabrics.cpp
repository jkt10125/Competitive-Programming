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

bool cmp1(pair<string, pair<int, int>> A, pair<string, pair<int, int>> B) {
    if(A.first == B.first) return A.ss.ss < B.ss.ss;
    return A.ff < B.ff;
}

bool cmp2(pair<string, pair<int, int>> A, pair<string, pair<int, int>> B) {
    if(A.ss.ff == B.ss.ff) return A.ss.ss < B.ss.ss;
    return A.ss.ff < B.ss.ff;
}

void solve() 
{
	int n;
    cin >> n;

    vector<pair<string, pair<int, int>>> A(n);
    F0R(i, n) {
        cin >> A[i].ff >> A[i].ss.ff >> A[i].ss.ss;
    }
    auto B = A;
    sort(all(B), cmp1);
    sort(all(A), cmp2);
    int ctr = 0;
    F0R(i, n){
        if(A[i] == B[i]) ctr++;
    }
    cout<<ctr;
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