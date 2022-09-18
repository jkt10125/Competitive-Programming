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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T = int>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;




// !---> Code starts <---!

vi parent;
void make_set(int n) {
    parent.resize(n);
    F0R(i, n) parent[i] = i;
}
int find_Set(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find_Set(parent[x]);
}

void solve() 
{
    int n, k;
    cin >> n >> k;
    map<int, int> M;
    ll sum = 0;
    for(int i=0; i<n; i++) {
        int a = input();
        sum += a / k;
        M[a % k]++;
    }

    vi A, B;
    for(int i=1; i<=(k-1)/2; i++) {
        while(M[i]--) A.pb(i);
    }
    for(int i=(k-1)/2+1; i<k; i++) {
        while(M[i]--) B.pb(i);
    }

    // cout<<A<<endl<<B;

    int p1=0, p2=B.size()-1;
    while(p1 < A.size() && p2 >= 0) {
        if(A[p1] + B[p2] >= k) {
            sum++;
            p1++;
            p2--;
        }
        else {
            if(M[0] % 2 != 0) {
                M[0]--;
                p1++;
            }
            else p1+=2;
        }
    }
    // cout<<"p2: "<<p2;
    sum = sum + ((p2+1)/2);

    cout<<sum;
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