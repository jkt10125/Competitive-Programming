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

vector<int> suffix_array(string &s) {
    s.push_back('$');
    int n = s.size();
    vector<int> eq_class(n), p(n);
    
    {
        vector<pair<char, int>> A(n);
        for(int i=0; i<n; i++) {
            A[i] = {s[i], i};
        }
        sort(A.begin(), A.end());
        for(int i=0; i<n; i++) p[i] = A[i].second;
        eq_class[p[0]] = 0;
        for(int i=1; i<n; i++) {
            if(A[i].first == A[i-1].first) {
                eq_class[p[i]] = eq_class[p[i-1]];
            } else {
                eq_class[p[i]] = eq_class[p[i-1]] + 1;
            }
        }
    }

    int k = 0;
    while((1 << k) < n) {
        vector<pair<pair<int, int>, int>> A(n);
        for(int i=0; i<n; i++) {
            A[i] = {{eq_class[i], eq_class[(i + (1 << k)) % n]}, i};
        }
        sort(A.begin(), A.end());
        for(int i=0; i<n; i++) p[i] = A[i].second;
        eq_class[p[0]] = 0;
        for(int i=1; i<n; i++) {
            if(A[i].first == A[i-1].first) {
                eq_class[p[i]] = eq_class[p[i-1]];
            } else {
                eq_class[p[i]] = eq_class[p[i-1]] + 1;
            }
        }
        k++;
    }

    return p;
}

int main()
{
	fastIO;
    string t = input<string>();
    int n = input<int>();
    vector<int> A = suffix_array(t);
    while(n--) {
        string s = input<string>();
        int l = 0, r = t.size()-1;
        int flag = 0;
        while(l <= r) {
            int m = (l+r)/2;
            if(t.substr(A[m], s.size()) < s) {
                l = m+1;
            } else {
                if(t.substr(A[m], s.size()) == s) {
                    flag = 1; break;
                } else {
                    r = m-1;
                }
            }
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

// !---> Code Ends <---!