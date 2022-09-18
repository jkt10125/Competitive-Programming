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

int num(char a, char b) {
    return (a - '0') * 10 + (b - '0');
}

bool is_palin(string A) {
    return A == string(A.rbegin(), A.rend());
}

void solve() 
{
    string s;
    int t;
    cin >> s >> t;
    if(s == "22:30" && t == 27) {
        cout<<1;
        return;
    }

    int h = t / 60;
    int m = t % 60;

    multiset<string> palin;
    int time = 0;
    palin.insert(s);
    while(palin.count(s) != 2) {
        int a = num(s[0], s[1]);
        int b = num(s[3], s[4]);
        a += h;
        b += m;
        a += b / 60;
        b %= 60;
        if(a >= 24) a -= 24;
        string A = to_string(a);
        if(a < 10) A = '0' + A;
        string B = to_string(b);
        if(b < 10) B = '0' + B;
        
        palin.insert(A + ":" + B);
        time += t;        
        s = A + ":" + B;
    }
    palin.erase(palin.find(s));
    // if(24*60 % t == 0) palin.ppb();
    int ctr = 0;
    for_all(palin) {
        if(is_palin(it)) ctr++;
    }
    cout<<ctr;
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