#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b, c) for(int i=a; i<=b; i+=c)
#define F0R(i, n) FOR(i, 0, (int)n-1, 1)
#define F1R(i, n) FOR(i, 1, (int)n, 1)
#define FORn(i, a, b, c) for(int i=a; i>=b; i+=c)
#define F0Rn(i, n) FORn(i, (int)n-1, 0, -1)
#define F1Rn(i, n) FORn(i, (int)n, 1, -1)

#define space ' '
#define newl '\n'
#define ERROR throw("ERROR")

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

template <typename T>
T RANDOM(T a, T b) {
    srand(time(NULL));
    return (rand() % (b-a+1)) + a;
}

template <typename T>
int SGN(T a) { return (a==0) ? 0 : (a>0) ? 1 : -1; } // signum function

template <typename T>
void SWAP(T &a, T &b) { T t = a; a = b; b = t; }

template <typename T>
T MAX(T a, T b) { return (a > b) ? a : b; }

template <typename T>
T MIN(T a, T b) { return (a < b) ? a : b; }

//OUTPUT FUNCTIONS
template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); it++) {
        os << *it;
        if(it != --v.end()) os << " ";
    }
    os << "]\n";
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

vi _parent;
vi _size;

void make_set(int n) {
    _parent.resize(n);
    _size.resize(n, 1);
    F0R(i, n) _parent[i] = i;
}

int find_set(int x) {
    if (_parent[x] != x) { _parent[x] = find_set(_parent[x]); }
    return _parent[x];
}

bool is_same_set(int x, int y) {
    return find_set(x) == find_set(y);
}

bool union_set(int x, int y) {
    if(is_same_set(x, y)) return false; //union failed
    int x_root = find_set(x);
    int y_root = find_set(y);

    if(_size[x_root] < _size[y_root]) { SWAP(x_root, y_root); }
    _parent[y_root] = x_root;
    _size[x_root] += _size[y_root];

    return true;
}


void solve() 
{
    int n, m, k;
    cin >> n >> m >> k;
    vll A(n), B(n);
    cin >> A >> B;

    make_set(n);
    F0R(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        union_set(a, b);
    }

    F0R(i, n) {
        int a = find_set(i);
        if(a != i) {
            A[a] += A[i];
            B[a] += B[i];
        }
    }

    vector<pair<ll, ll>> ns(1);
    set<int> SS;
    ll ans = 0;
    F0R(i, n) {
        int a = find_set(i);
        if(SS.find(a) == SS.end()) {
            if(A[a] == 0) {
                ans += B[a];
            } else {
                ns.pb({A[a], B[a]});
            }
            // ns.pb({A[a], B[a]});
            SS.insert(a);
        }
    }

    n = ns.size()-1;
    vvll DP(n+1, vll(k+1, 0));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j >= ns[i].ff) {
                DP[i][j] = MAX(DP[i-1][j], DP[i-1][j-ns[i].ff] + ns[i].ss);
            }
            else DP[i][j] = DP[i-1][j];
        }
    }


    ll mx = INT_MIN;
    for(int i=0; i<=k; i++) {
        mx = MAX(mx, DP[n][i]);
    }
    cout << mx + ans;
}

int main()
{
    fastIO;
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout<<endl;
    }
    return 0;
}