#include <bits/stdc++.h>
using namespace std;

#define ll long long

template <typename T>
class LazySegTree {
    T value;
    pair<int, int> range;
    LazySegTree *left, *right;
    public:
    LazySegTree(vector<T> &A, pair<int, int> R) {
        range = R;
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

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> A(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        LazySegTree<ll> segTree(A, {0, n-1});
        long long ans = 0;
        for(int i=0; i<n-1; i++) {
            ll a = segTree.value_at_index(i)-segTree.value_at_index(i+1);
            if(a > 0) {
                segTree.update({0, i}, -a);
            }
            else {
                segTree.update({i+1, n-1}, a);
            }
            ans += abs(a);
        }
        ll a = segTree.value_at_index(n-1);
        ans += abs(a);
        cout << ans<<"\n";
    }
}