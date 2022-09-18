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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T = int>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() 
{
	int n = input();
    string s = input<string>();
    vi A(n);
    cin >> A;

    ordered_multiset<int> adult, child;
    F0R(i, n) {
        if(s[i]-'0') adult.insert(A[i]);
        else child.insert(A[i]);
    }
    int ans = 0;
    int ctr;
    F0R(i, n) {
        ctr = A[i];
        int tans = adult.order_of_key(ctr);
        tans = adult.size()-tans;
        tans += child.order_of_key(ctr);
        ans = max(ans, tans);
        ctr = A[i]+1;
        tans = adult.order_of_key(ctr);
        tans = adult.size()-tans;
        tans += child.order_of_key(ctr);
        ans = max(ans, tans);
        ctr = A[i]-1;
        tans = adult.order_of_key(ctr);
        tans = adult.size()-tans;
        tans += child.order_of_key(ctr);
        ans = max(ans, tans);
    }

    cout<<ans;
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