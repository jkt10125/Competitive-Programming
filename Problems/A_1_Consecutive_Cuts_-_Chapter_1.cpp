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
	int n, k;
	cin >> n >> k;
	vi A(n), B(n);
	cin >> A >> B;

	if(k == 0) {
		if(A == B) cout<<"YES";
		else cout<<"NO";
		return;
	}
	if(n == 2) { 
		if(A[0] == A[1]) {
			cout<<"YES";
		}
		else {
			if(k & 1) { 
				if(A == B) cout<<"NO"; 
				else cout << "YES";
			}
			else {
				if(A == B) cout<<"YES";
				else cout<<"NO";
			}
		}
		return;
	}
	if(k == 1 && A == B) { cout<<"NO"; return; }
	int i=0, j=0;
	for(; i<n; i++) {
		if(A[i] == B[0]) break;
	}
	int a = 1;
	for(; 1; i=(i+1)%n) {
		if(A[i] != B[j++]) a = 0;
		if(A[i] == B[n-1]) break;
	}

	if(a) cout<<"YES";
	else cout<<"NO";
}

signed main()
{
	fastIO;
	int t = input<int>();
	F1R(i, t) {
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

// !---> Code Ends <---!