#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
int f(int a, int b) {
	return max(a, b);
}

class LazySegTree {
    int data, value;
    pair<int, int> range;
    LazySegTree *left, *right;
  public:
    LazySegTree(vector<int> &A, pair<int, int> R) {
        range = R;
        value = 0;
        if(R.first == R.second) { data = A[R.first]; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new LazySegTree(A, {R.first, mid});
            right = new LazySegTree(A, {mid+1, R.second});
            data = left->data + right->data;
        }
    }

    void push() {
        if(!value) return;
        if(left) {
            left->data += value * (left->range.second - left->range.first + 1);
            left->value += value;
        }
        if(right) {
            right->data += value * (right->range.second - right->range.first + 1);
            right->value += value;
        }
        value = 0;
    }

    void update(pair<int, int> R, int val) {
        if(range == R) {
            data += val * (range.second - range.first + 1);
            value += val;
            return;
        }
        data += val * (R.second - R.first + 1);
        push();
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) right->update(R, val);
        else if(R.second <= mid) left->update(R, val);
        else {
            left->update({R.first, mid}, val);
            right->update({mid+1, R.second}, val);
        }
    }

    int query(pair<int, int> R) {
        if(range == R) return (data > (n >> 1)) ? (n-data) : data;
        push();
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return (right->query(R) + n) % n;
        else if(R.second <= mid) return (left->query(R) + n) % n;
        else return (left->query({R.first, mid}) + right->query({mid+1, R.second}) + n) % n;
    }

    void print() {
        cout<<range.first<<" "<<range.second<<" : "<<data<<" "<<value<<endl;
        if(left) left->print();
        if(right) right->print();
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    LazySegTree LST(A, {0, n-1});

}