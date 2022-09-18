#include <bits/stdc++.h>
using namespace std;

pair<int, int> f(pair<int, int> A, pair<int, int> B) {
    return (A.first < B.first) ? B : A;
}

class segtree {
    pair<int, int> range, data;
    segtree *left, *right;
    public:
    segtree(vector<int> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            data = {A[R.first], R.first};
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
        if(idx == -1) return;
        if(range.first == range.second) {
            data.first -= val;
        }
        else {
            int mid = (range.first + range.second) / 2;
            if(idx > mid) right->update(idx, val);
            else left->update(idx, val);
            data = f(left->data, right->data);
        }
    }

    int max_in_range(pair<int, int> R) {
        if(range == R) return data.first;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->max_in_range(R);
        else if(R.second <= mid) return left->max_in_range(R);
        else return max(left->max_in_range({R.first, mid}), right->max_in_range({mid+1, R.second}));
    }

    int query(pair<int, int> R, int k) {
        if(data.first < k) return -1;
        if(range.first == range.second) return data.second;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R, k);
        else if(R.second <= mid) return left->query(R, k);
        else {
            if(left->max_in_range({R.first, mid}) >= k) return left->query({R.first, mid}, k);
            else return right->query({mid+1, R.second}, k);
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    
    segtree T(A, {0, n-1});
    while(q--) {
        int k;
        cin >> k;
        int a = T.query({0, n-1}, k);
        T.update(a, k);
        cout<<++a<<" ";
    }
}