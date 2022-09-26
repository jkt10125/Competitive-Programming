#include <bits/stdc++.h>
using namespace std;

class LazySegTree {
	int L, R, data, val;
	LazySegTree *left, *right;
	
	void push() {
		if(!val) return;
		if(left) {
			left->data += val * (left->R - left->L + 1);
			right->data += val * (right->R - right->L + 1);
			left->val += val;
			right->val += val;
		}
		val = 0;
	}

  public:
	LazySegTree(vector<int> &A, int l, int r) {
		L = l, R = r; val = 0;
		if(l == r) {
			data = A[l];
			left = right = nullptr;
		}
		else {
			int m = (l + r) / 2;
			left = new LazySegTree(A, l, m);
			right = new LazySegTree(A, m+1, r);
			data = left->data + right->data;
		}
	}

	void update(int idx, int v) {
		if(R == L) data = v;
		else {
			int m = (R + L) / 2;
			if(idx <= m) left->update(idx, v);
			else right->update(idx, v);
			data = left->data + right->data;
		}
	}

	void update(int l, int r, int v) {
		data += v * (R - L + 1);
		if(L == l && R == r) {
			val += v;
		}
		else {
			int m = (R + L) / 2;
			if(r <= m) left->update(l, r, v);
			else if(l > m) right->update(l, r, v);
			else {
				left->update(l, m, v);
				right->update(m+1, r, v);
			}
		}
	}

	int query(int l, int r) {
		if(L == l && R == r) return data;
		else {
			push();
			int m = (L + R) / 2;
			if(r <= m) return left->query(l, r);
			else if(l > m) return right->query(l, r);
			else return left->query(l, m) + right->query(m+1, r);
		}
	}

	int query(int idx) { return query(idx, idx); }

	void print() {
		cout<<L<<" "<<R<<" : "<<data<<" "<<val<<endl;
		if(left) {
			left->print();
			right->print();
		}
	}
};

int main() {
	vector<int> A = {2, -4, 3, 6, 10, 6, -4, -8, -3, 5};
	LazySegTree AA(A, 0, 9);
	AA.update(0, 9, 5);
	cerr << AA.query(1);
	AA.print();
}