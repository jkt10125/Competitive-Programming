#include <bits/stdc++.h>
using namespace std;

class ds {
    public:
    long long current, prefix, suffix, max_sum;
    ds(long long a = 0ll) {
        prefix = suffix = max_sum = max(a, 0ll);
        current = a;
    } 
};

ds func(ds L, ds R) {
    ds A;
    A.current = L.current + R.current;
    A.prefix = max(L.prefix, L.current + R.prefix);
    A.suffix = max(R.suffix, R.current + L.suffix);
    A.max_sum = max(max(L.max_sum, R.max_sum), L.suffix + R.prefix);
    return A;
}


class segtree {
    pair<int, int> range;
    ds data;
    segtree *left, *right;
    public:
    segtree(vector<long long> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            data = ds(A[R.first]);
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new segtree(A, {R.first, mid});
            right = new segtree(A, {mid+1, R.second});
            data = func(left->data, right->data);
        }
    }

    void update(int idx, long long val) {
        if(range.first == range.second) {
            data = ds(val);
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx, val);
        else left->update(idx, val);
        data = func(left->data, right->data);
    }

    ds query(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return func(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    segtree T(A, {0, n-1});
    cout<<T.query({0, n-1}).max_sum<<endl;
    for(int i=0; i<m; i++) {
        long long a, b;
        cin >> a >> b;
        T.update(a, b);
        cout << T.query({0, n-1}).max_sum << endl;
    }
}