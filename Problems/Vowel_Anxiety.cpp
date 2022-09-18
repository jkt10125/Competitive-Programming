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
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;

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

template <typename T>
class item {
    public:
    int priority, cnt;
    T key, F, G;
    bool rev;
    item<T> *l, *r;
    item(T k, int p = rand()) {
        cnt = 1;
        rev = false;
        F = G = 0;
        l = r = NULL;
        key = k;
        priority = p;
    }
};

template <typename T>
int cnt(item<T> *t) { return (!t) ? 0 : t->cnt; }

template <typename T>
void update_cnt(item<T> *t) { if(t) t->cnt = 1 + cnt(t->l) + cnt(t->r); }

template <typename T>
T F(item<T> *t) { return (!t) ? 0 : t->F; }

template <typename T>
void f(item<T> *&t) { if(t) t->F = t->key + F(t->l) + F(t->r); }

template <typename T> // splits into ( < key) & ( >= key)
void split(item<T> *t, item<T> *&l, item<T> *&r, int key, int add = 0) {
    push_rev(t); push_data(t);
    if(!t) return void( l = r = 0 );
    int cur_key = add + cnt(t->l);
    if(key <= cur_key) split(t->l, l, t->l, key, add), r = t;
    else split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
    update_cnt(l); f(l);
    update_cnt(r); f(r);
}

template <typename T>
void merge(item<T> *&t, item<T> *l, item<T> *r) {
    push_rev(l); push_data(l);
    push_rev(r); push_data(r);
    if(!l || !r) t = l ? l : r;
    else if (l->priority > r->priority) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    update_cnt(t); f(t);
}

template <typename T>
void insert(item<T> *&t, int pos, item<T> *ky) {
    item<T> *L, *R;
    split(t, L, R, pos); // => ([0 ... pos-1]) & ([1 ... size-pos])
    merge(L, L, ky); // => ([0 ... pos-1], ky) & ([1 ... size-pos])
    merge(t, L, R); // => ([0 ... size+ky.size])
}

template <typename T>
void erase(item<T> *&t, int l, int r) {
    item<T> *L, *M, *R;
    split(t, M, R, r+1);
    split(M, L, M, l);
    merge(t, L, R);
    delete M;
}

template <typename T>
void push_rev(item<T> *&t) {
    if(!t || !t->rev) return;
    swap(t->l, t->r);
    if(t->l) t->l->rev ^= 1;
    if(t->r) t->r->rev ^= 1;
    t->rev = 0;
}

template <typename T>
void push_data(item<T> *&t) {
    if(!t || !t->G) return;
    if(t->l) { t->l->G = t->G; t->l->key = t->G; }
    if(t->r) { t->r->G = t->G; t->r->key = t->G; }
    t->G = 0;
}

template <typename T>
void reverse(item<T> *&t, int l, int r) {
    item<T> *L, *M, *R;
    split(t, M, R, r+1);
    split(M, L, M, l);
    M->rev ^= 1;
    merge(M, L, M);
    merge(t, M, R);
}

template <typename T>
void right_cyclic_shift(item<T> *&t, int l, int r, int qty) {
    qty = qty % (r-l+1);
    item<T> *L, *M, *R;
    split(t, M, R, r+1);
    split(M, L, M, l);
    item<T> *a, *b;
    split(M, a, b, r-l+1-qty);
    merge(M, b, a);
    merge(M, L, M);
    merge(t, M, R);
}

template <typename T>
void left_cyclic_shift(item<T> *&t, int l, int r, int qty) {
    qty = qty % (r-l+1);
    right_cyclic_shift(t, l, r, r-l+1-qty);
}

template <typename T>
void range_update(item<T> *&t, int l, int r, int val) {
    item<T> *L, *M, *R;
    split(t, M, R, r+1);
    split(M, L, M, l);
    M->G = val;
    M->key = val;
    merge(M, L, M);
    merge(t, M, R);
}

template <typename T>
T query(item<T> *&t, int l, int r) {
    item<T> *L, *M, *R;
    split(t, M, R, r+1);
    split(M, L, M, l);
    T ans = F(M);
    merge(M, L, M);
    merge(t, M, R);
    return ans;
}

template <typename T>
void output(item<T> *t) {
    if(!t) return;
    push_rev(t); push_data(t);
    output(t->l);
    cout << t->key << "";
    output(t->r);
}

bool isvowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


void solve() 
{
	int n = input();
    string s = input<string>();
    item<char> *t = nullptr;
    int ctr = 0;
    for(char c: s) {
        insert(t, ctr++, new item(c));
    }
    for(int i=1; i<n; i++) {
        if(isvowel(s[i])) {
            reverse(t, 0, i-1);
        }
    }
    output(t);
}

int main()
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