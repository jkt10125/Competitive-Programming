/*
Reference : https://cp-algorithms.com/data_structures/treap.html
huge thanks to anubhavdhar for helping me in writing this code 
Instructions: 	
	PRIORITIES SHOULD BE DISTINCT 
		I don't know why, but for some reason t2 in reverse() becomes NULL if there is a collision in priority
		Make sure you do this my generating a random permutation of the sequence {1, 2, .. , N + Q} maybe
	
	* In the first line change the typedef from int to char if you want to use this on a string
	** always initialize your treap pointer with NULL
*/

typedef int treap_data_type;
struct item {
	int prior, cnt;
	treap_data_type value;
	item *l, *r;
	bool rev;
	item() { }
	item(treap_data_type value, int prior) : value(value), prior(prior), l(NULL), r(NULL), rev(0) { }
};

typedef item * pitem;

// helper functions
// ------------------------------------------------
int cnt(pitem it) {
	return it ? it->cnt : 0;
}

void upd_cnt(pitem it) {
	if(!it) return;
	it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push(pitem it) {
	if(it && it->rev) {
		it->rev = false;
		swap(it->l, it->r);
		if(it->l) it->l->rev ^= true;
		if(it->r) it->r->rev ^= true;
	}
}
// -----------------------------------------------

// O(logn)
void merge(pitem &t, pitem l, pitem r) {
	push(l);
	push(r);
	if(!l || !r)
		t = l ? l : r;
	else if(l->prior > r->prior)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

// O(logn)
void split(pitem t, pitem &l, pitem &r, int key, int add = 0) { // apparantly splits (< T) and (>= T)
	if(!t) return void( l = r = 0 );
	push(t);
	int cur_key = add + cnt(t->l);
	if(key <= cur_key)
		split(t->l, l, t->l, key, add), r = t;
	else
		split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
	upd_cnt(r);
	upd_cnt(l);
	upd_cnt(t);
}

// O(logn)
void insert(pitem &t, treap_data_type val, int prior, int i) { // inserts before the i-th index (This will become the i-th index);
	pitem t1, t2, it = new item(val, prior);
	split(t, t1, t2, i);
	merge(t1, t1, it);
	merge(t, t1, t2);
}

// O(logn)
void reverse(pitem &t, int l, int r) {
	pitem t1, t2, t3;
	split(t, t1, t2, l);
	split(t2, t2, t3, r-l+1);
	t2->rev ^= true;
	merge(t, t1, t2);
	merge(t, t, t3);
}

// O(logn)
void erase(pitem &t, int idx, int len = 1) {
	pitem t1, t2, t3;
	split(t, t1, t2, idx);
	split(t2, t2, t3, len);
	merge(t, t1, t3);
	delete t2;
}

// O(logn)
void append(pitem &t, treap_data_type val, int prior){
	pitem it = new item(val, prior);
	it->cnt = 1;
	t ? merge(t, t, it) : (t = it, upd_cnt(t));
}

// O(logn)
void right_cyclic_shift(pitem &t, int l, int r, int qty = 1) { 
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

// O(logn)
void left_cyclic_shift(pitem &t, int l, int r, int qty = 1) { 
    qty = qty % (r-l+1);
    right_cyclic_shift(t, l, r, r-l+1-qty);
}

// O(n)
void output(pitem t) { 
	if(!t) return;
	push(t);
	output(t->l);
	cout << t->value << ' ';
	output (t->r);
}
