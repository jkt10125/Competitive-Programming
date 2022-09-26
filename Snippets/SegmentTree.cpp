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


// Classical Segment Tree
template <typename T, T (*func) (T, T)>
class SegTree {
    pair<int, int> range;
    T data;
    SegTree *left, *right;
  public:
    SegTree(vector<T> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) { data = A[R.first]; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new SegTree(A, {R.first, mid});
            right = new SegTree(A, {mid+1, R.second});
            data = func(left->data, right->data);
        }
    }

    void update(int idx, T val) {
        if(range.first == range.second) {
            data = val;
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx, val);
        else left->update(idx, val);
        data = func(left->data, right->data);
    }

    T query(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return func(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }
};

// Different Combiner Functions 
    // -> GCD / LCM
    // -> Min / Max
    // -> Sum / Product

    // Function which stores the maximum and its frequency in the array
    // pii MX_Frequency(pii A, pii B) {
    //     if(A.ff == B.ff) return {A.ff, A.ss + B.ss};
    //     return (A.ff > B.ff) ? A : B;
    // } 

    // Function which stores the max_subsegment_sum over a range
    // template <typename T = int>
    // class Data {
    // public:
    //     T sum, max_psum, max_ssum, max_subseg_sum;
    //     Data(T current_segment_sum=0, T max_prefix_sum=0, T max_suffix_sum=0, T max_subsegment_sum=0) 
    //     {
    //         sum = current_segment_sum;
    //         max_psum = max_prefix_sum;
    //         max_ssum = max_suffix_sum;
    //         max_subseg_sum = max_subsegment_sum;
    //     }
    //     T get_ans() { 
    //         return max_subseg_sum;
    //     }
    // };
    // template <typename T = int>
    // Data<T> func(Data<T> L, Data<T> R) {
    //     Data<T> res;
    //     res.sum = L.sum + R.sum;
    //     res.max_psum = MAX(L.max_psum, L.sum + R.max_psum);
    //     res.max_ssum = MAX(R.max_ssum, R.sum + L.max_ssum);
    //     res.max_subseg_sum = MAX(MAX(L.max_subseg_sum, R.max_subseg_sum), L.max_ssum + R.max_psum);
    //     return res;
    // }

    // Function to find kth zero
    // Function to find the ith element such that the prefix sum is equal to the given value(x)
    // int find_that_element(pii R, int k) {
    //     if(k > data) return -1;
    //     if(range.ff == range.ss) return range.ff;
    //     int mid = (range.ff + range.ss) / 2;
    //     if(R.ff > mid) return right->find_that_element(R, k);
    //     if(R.ss <= mid) return left->find_that_element(R, k);
    //     int l = left->query({R.ff, mid});
    //     if(l >= k) return left->find_that_element({R.ff, mid}, k);
    //     return right->find_that_element({mid + 1, R.ss}, k - l);
    // }

    // Searching for the first element greater than a given amount
    // -> We only need to modify the last statement of the above function
    // --> We do not need to subtract l from k in the last line.