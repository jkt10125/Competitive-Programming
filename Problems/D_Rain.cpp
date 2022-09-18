#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LazySegTree {
	T value, triangle_value;
	pair<int, int> range;
	LazySegTree *left, *right;
	public:
	LazySegTree(vector<T> &A, pair<int, int> R) {
		range = R;
		triangle_value = -1;
		if(R.first == R.second) {
			value = A[R.first];
			left = right = NULL;
		}
		else {
			int mid = (R.first + R.second) / 2;
			left = new LazySegTree(A, {R.first, mid});
			right = new LazySegTree(A, {mid+1, R.second});
			value = 0;
		}
	}

	void push() {
		if(!value) return;
		if(range.first == range.second) return;
		left->value += value;
		right->value += value;
		value = 0;
	}

	void triangle_push() {
		if(triangle_value == -1) return;
		if(range.first == range.second) 
	}

	void update(pair<int, int> R, T val) {
		if(range == R) {
			value += val;
			return;
		}
		push();
		int mid = (range.first + range.second) / 2;
		if(R.first > mid) right->update(R, val);
		else if(R.second <= mid) left->update(R, val);
		else {
			left->update({R.first, mid}, val);
			right->update({mid+1, R.second}, val);
		}
	}

	T value_at_index(int idx) {
		if(range.first == range.second) return value;
		push();
		int mid = (range.first + range.second) / 2;
		if(idx > mid) return right->value_at_index(idx);
		else return left->value_at_index(idx);
	}
};