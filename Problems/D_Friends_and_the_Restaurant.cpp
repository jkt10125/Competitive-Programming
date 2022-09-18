#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b, c) for(int i=(int)a; i<=(int)b; i+=(int)c)
#define F0R(i, n) for(int i=0; i<(int)n; i++)
#define F1R(i, n) for(int i=1; i<=(int)n; i++)
#define FORn(i, a, b, c) for(int i=(int)a; i>=(int)b; i+=(int)c)
#define F0Rn(i, n) for(int i=(int)n-1; i>=0; i--)
#define F1Rn(i, n) for(int i=(int)n; i>=1; i--)
#define for_all(A) for(auto &it : A)
#define int long long
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
    vi A(n), B(n);
    cin >> A >> B;

    multiset<int> credit, debt;
    F0R(i, n) {
        if(A[i] > B[i]) debt.insert(A[i] - B[i]);
        else credit.insert(B[i] - A[i]);
    }

    int ans = 0;
    for(int i : credit) {
        auto it = debt.upper_bound(i);
        if(it == debt.begin() || debt.empty()) continue;
        it--;
        ans++;
        debt.erase(it);
    }
    cout<<ans + (credit.size()-ans)/2;

}   

signed main()
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