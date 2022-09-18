#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int a, int b) {
	return max(a, b);
}

class segtree {
	pair<int, int> range;
	int data;
	segtree *left, *right;
	public:
	segtree(vector<int> &A, pair<int, int> R) {
		range = R;
		if(R.first == R.second) {
			data = A[R.first];
			left = right = nullptr;
		}
		else {
			int mid = (R.first + R.second) / 2;
			left = new segtree(A, {R.first, mid});
			right = new segtree(A, {mid+1, R.second});
			data = f(left->data, right->data);
		}
	}

	void update(int idx, int val) {
		if(range.first == range.second) data = val;
		else {
			int mid = (range.first + range.second) / 2;
			if(idx > mid) right->update(idx, val);
			else left->update(idx, val);
		}
	}

	int query(pair<int, int> R) {
		if(range.first == range.second) return data;
		else {
			int mid = (range.first + range.second) / 2;
			if(R.first > mid) return right->query(R);
			else if(R.second <= mid) return left->query(R);
			else {
				return f(left->query({R.first, mid}), right->query({mid+1, R.second}));
			}
		}
	}
};

class lazysegtree {
	pair<int, int> range;
	int data;
	lazysegtree *left, *right;
	public:
	lazysegtree(vector<int> &A, pair<int, int> R) {
		range = R;
		if(R.first == R.second) {
			data = A[R.first];
			left = right = nullptr;
		}
		else {
			data = 0;
			int mid = (R.first + R.second) / 2;
			left = new lazysegtree(A, {R.first, mid});
			right = new lazysegtree(A, {mid+1, R.second});
		}
	}

	void push() {
		if(range.first == range.second || !data) return;
		left->data += data;
		right->data += data;
		data = 0;
	}

	void update(pair<int, int> R, int val) {
		if(range == R) data += val;
		else {
			int mid = (range.first + range.second) / 2;
			if(R.first > mid) right->update(R, val);
			else if(R.second <= mid) left->update(R, val);
			else {
				left->update({R.first, mid}, val);
				right->update({mid+1, R.second}, val);
			}
		}
	}

	int query(pair<int, int> R) {
		
	}

	void print() {
		if(range.first == range.second) cout<<data<<" ";
		else {
			push();
			left->print();
			right->print();
		}
	}
};

signed main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i=0; i<n; i++) cin >> A[i];

	lazysegtree ST(A, {0, n-1});
	ST.update({3, 7}, 10);
	ST.print();
}