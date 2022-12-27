/*
** Date: 26/12/2022 | Time: 23:43:32
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(0, INT_MAX);

template <typename T>
class item {
    public:
    int priority, cnt;
    T key, F, G;
    bool rev;
    item<T> *l, *r;
    item(T k, int p = uid(rng)) {
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
    cout << t->key << " ";
    output(t->r);
}

int main() {
    int n, q;
    cin >> n >> q;
    item<int> *t;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        item<int> *a = new item<int>(x);
        insert(t, i, a);
    }
    while (q--) {
        int tt, a, b;
        cin >> tt >> a >> b;
        a--, b--;
        if (tt == 1) {
            reverse(t, a, b);
        }
        else {
            cout << query(t, a, b) << endl;
        }
    }
}