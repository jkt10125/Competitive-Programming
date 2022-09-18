#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, c) for(int i=a; i<=b; i+=c)
#define F0R(i, n) FOR(i, 0, (int)n-1, 1)
#define F1R(i, n) FOR(i, 1, (int)n, 1)
#define FORn(i, a, b, c) for(int i=a; i>=b; i+=c)
#define F0Rn(i, n) FORn(i, (int)n-1, 0, -1)
#define F1Rn(i, n) FORn(i, (int)n, 1, -1)

#define precision(a) cout << setprecision(a)
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL)

#define ui unsigned int
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second

#define vT vector<T>
#define vvT vector<vT>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vvll vector<vll>
#define si set<int>
#define sll set<ll>
#define dqi deque<int>
#define dqll deque<ll>
#define pii pair<int, int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int, int>
#define mlli map<ll, int>
#define mill map<int, ll>
#define mllll map<ll, ll>
#define misi map<int, set<int>>
#define mivi map<int, vi>
#define mllvi map<ll, vi>
#define mllvll map<ll, vll>
#define msi map<string, int>
#define vpipii vector<pair<int, pii>>
#define vppiii vector<pair<pii, int>>
#define vvpipii vector<vpipii>

#define all(a) a.begin(), a.end()

//OUTPUT FUNCTIONS
template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    // os << "[";
    for(auto it = v.begin(); it != v.end(); it++) {
        os << *it;
        if(it != --v.end()) os << "\n";
    }
    // os << "]\n";
    return os;
}

template <typename T>
ostream& operator<<(ostream &os, const deque<T> &v) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); it++) {
        os << *it;
        if(it != --v.end()) os << " ";
    }
    os << "]\n";
    return os;
}

template <typename T>
ostream& operator<<(ostream &os, const set<T> &s) {
    os << "[";
    for(auto it = s.begin(); it != s.end(); it++) {
        os << *it;
        if(it != --s.end()) os << " ";
    }
    os << "]\n";
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream &os, const map<T, S> &m) {
    for(auto it : m) {
        os << it.first << " : " << it.second << "\n";
    }
    return os;
}

template <typename T, typename S>
ostream& operator<<(ostream &os, const pair<T, S> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

// INPUT FUNCTIONS
template <typename T, typename S>
istream& operator>>(istream &is, pair<T, S> &p) {
    is >> p.first >> p.second;
    return is;
}

template <typename T>
istream& operator>>(istream &is, vector<T> &v) {
    for(auto &it : v) is >> it;
    return is;
}

const int BLOCK_SIZE = 450;
vll H(1<<21);

void solve() 
{
	int n, m;
    cin >> n >> m;
    vll A(n);
    cin >> A;

    vvpipii B(n / BLOCK_SIZE + 1);
    F0R(i, m) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        B[l / BLOCK_SIZE].pb({r, {l, i}});
    }

    for(auto &it : B) sort(all(it));

    vll ans(m);
    F0R(i, B.size()) {
        int l, r;
        l = r = i * BLOCK_SIZE;
        // cerr << l << r;
        ll res = 0;
        for(auto &Q : B[i]) {
            while(r <= Q.ff) {
                res -= A[r] * H[A[r]] * H[A[r]];
                H[A[r]]++;
                res += A[r] * H[A[r]] * H[A[r]];
                r++;
            }
            while(l < Q.ss.ff) {
                res -= A[l] * H[A[l]] * H[A[l]];
                H[A[l]]--;
                res += A[l] * H[A[l]] * H[A[l]];
                l++;
            }
            while(l > Q.ss.ff) {
                l--;
                res -= A[l] * H[A[l]] * H[A[l]];
                H[A[l]]++;
                res += A[l] * H[A[l]] * H[A[l]];
            }
            // for(auto it : H) res += it.ss * it.ss * it.ff;

            ans[Q.ss.ss] = res;
        }
        F0R(i, n) H[A[i]] = 0; 
    }
    cout << ans;
}

int main()
{
    fastIO;
	solve();
	return 0;
}