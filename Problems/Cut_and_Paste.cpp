/*
** Date: 26/12/2022 | Time: 23:15:13
** Written By: JKT
*/

#include <bits/stdc++.h>
using namespace std;

typedef char treap_data_type;
struct item {
	int prior, cnt;
	treap_data_type value;
	item *l, *r;
	bool rev;
	item () { }
	item (treap_data_type value, int prior) : value(value), prior(prior), l(NULL), r(NULL), rev(0) { }
};

typedef item * pitem;

int cnt (pitem it) {
	return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
	if(!it) return;
	it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
	if(it && it->rev) {
		it->rev = false;
		swap(it->l, it->r);
		if(it->l) {
			it->l->rev ^= true;
		}
		if(it->r) {
			it->r->rev ^= true;
		}
	}
}

void merge (pitem &t, pitem l, pitem r) {
	push(l);
	push(r);
	if (!l || !r) {
		t = l ? l : r;
	}
	else if (l->prior > r->prior) {
		merge(l->r, l->r, r), t = l;
	}
	else {
		merge(r->l, l, r->l), t = r;
	}
	upd_cnt(t);
}

void split (pitem t, pitem &l, pitem &r, int key, int add = 0) { // apparantly splits (< T) and (>= T)
	if (!t) return void( l = r = 0 );
	push(t);
	int cur_key = add + cnt(t->l);
	if (key <= cur_key) {
		split(t->l, l, t->l, key, add), r = t;
	}
	else {
		split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
	}
	upd_cnt(r);
	upd_cnt(l);
	upd_cnt(t);
}

void insert (pitem &t, treap_data_type val, int prior, int i) { // inserts before the i-th index (This will become the i-th index);
	pitem t1, t2, it = new item(val, prior);
	split(t, t1, t2, i);
	merge(t1, t1, it);
	merge(t, t1, t2);
}

void reverse (pitem &t, int l, int r) {
	pitem t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r-l+1);
	t2->rev ^= true;
	merge(t, t1, t2);
	merge(t, t, t3);
}

void erase (pitem &t, int i){
	pitem t1, t2, t3;
	split(t, t1, t2, i);
	split(t2, t2, t3, 1);
	merge(t, t1, t3);
	delete t2;
}

void append (pitem &t, treap_data_type val, int prior){
	pitem it = new item(val, prior);
	it->cnt = 1;
	t ? merge(t, t, it) : (t = it, upd_cnt(t));
}

void right_cyclic_shift (pitem &t, int l, int r, int qty) {
    qty = qty % (r-l+1);
    pitem L, M, R;
    split(t, M, R, r+1);
    split(M, L, M, l);
    pitem a, b;
    split(M, a, b, r-l+1-qty);
    merge(M, b, a);
    merge(M, L, M);
    merge(t, M, R);
}

void left_cyclic_shift (pitem &t, int l, int r, int qty) {
    qty = qty % (r-l+1);
    right_cyclic_shift(t, l, r, r-l+1-qty);
}

void output (pitem t) {
	if (!t) return;
	push(t);
	output(t->l);
	cout << t->value;
	output(t->r);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(0, INT_MAX);

// generates a random priority array [0 ... n-1]
vector<int> rand_perm(int n) {
    vector<int> A(n);
    for(int i=0; i<n; i++) A[i] = i;
    while(n) {
        int idx = uid(rng) % n;
        swap(A[idx], A[n-1]);
        n--;
    }
    return A;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> A = rand_perm(n);
	string s;
    cin >> s;
    pitem t = nullptr;

    for (int i = 0; i < n; i++) {
        append(t, s[i], A[i]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        // l--, r--;
        pitem L, M, R;
        split (t, M, R, r);
        split (M, L, M, l - 1);
        merge (L, L, R);
        merge (t, L, M);
    }

    output (t);
}