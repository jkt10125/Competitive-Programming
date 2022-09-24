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

void solve() 
{
	string s;
	int q, ctr = 0;
	cin >> s;
	int n = s.size();
	vector<vector<int>> A(n, vector<int> (26, 0));
	
	for(int i=0; i<n; i++) A[i][s[i]-'a']++;
	for(int i=0; i<26; i++) {
		for(int j=1; j<n; j++) {
			A[j][i] += A[j-1][i];
		}
	}

	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if((r-l+1) % 2 == 0) continue;
		int a = (l + r) / 2;
		vector<int> L(26), R(26);
		for(int i=0; i<26; i++) {
			if(l) L[i] = A[a][i] - A[l-1][i];
			else L[i] = A[a][i];
			R[i] = A[r][i] - A[a][i];
		}
		int diff = 0;
		for(int i=0; i<26; i++) {
			diff += abs(L[i] - R[i]);
		}
		if(diff == 1) ctr++;
		else {
			for(int i=0; i<26; i++) {
				if(l) L[i] = A[a-1][i] - A[l-1][i];
				else L[i] = A[a-1][i];
				R[i] = A[r][i] - A[a-1][i];
			}
			int diff = 0;
			for(int i=0; i<26; i++) {
				diff += abs(L[i] - R[i]);
			}
			if(diff == 1) ctr++;
		}
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