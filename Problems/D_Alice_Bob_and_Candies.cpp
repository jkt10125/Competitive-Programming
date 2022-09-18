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
	int n = input();
    vi A(n);
    cin >> A;

    int p1=0, p2=n-1;
    int a=0, b=0;
    int ctr=0;
    for(; p1<=p2; ctr++) {
        if((ctr & 1) == 0) {
            while(a <= b && p1 <= p2) {
                a += A[p1++];
            }
            b = 0;
        }
        else {
            while(b <= a && p1 <= p2) {
                b += A[p2--];
            }
            a = 0;
        }
        // if(p1 > p2) ctr++;
    }
    a=0, b=0;
    for(int i=0; i<p1; i++) a += A[i];
    for(int i=n-1; i>p2; i--) b += A[i];

    cout<<ctr<<" "<<a<<" "<<b;
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