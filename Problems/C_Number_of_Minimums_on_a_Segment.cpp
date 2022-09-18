#include <bits/stdc++.h>
using namespace std;

pair<int, int> func(pair<int, int> L, pair<int, int> R) {
    if(L.first == R.first) return make_pair(L.first, L.second+R.second);
    return (L.first < R.first) ? L : R;
}

class segtree {
    pair<int, int> range;
    pair<int, int> data;
    segtree *left, *right;
    public:
    segtree(vector<int> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            data = {A[R.first], 1};
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new segtree(A, {R.first, mid});
            right = new segtree(A, {mid+1, R.second});
            data = func(left->data, right->data);
        }
    }

    void update(int idx, int val) {
        if(range.first == range.second) {
            data = {val, 1};
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx, val);
        else left->update(idx, val);
        data = func(left->data, right->data);
    }

    pair<int, int> query(pair<int, int> R) {
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
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    segtree st(A, {0, n-1});
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            st.update(b, c);
        }
        else {
            cout << st.query({b, c-1}).first << " " << st.query({b, c-1}).second << endl;
        }
    }
}