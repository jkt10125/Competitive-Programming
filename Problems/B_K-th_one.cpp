#include <bits/stdc++.h>
using namespace std;

pair<int, int> func(pair<int, int> L, pair<int, int> R) {
    if(R.second == -1) return L;
    return {L.first + R.first, R.second};
}

class segtree {
    pair<int, int> range;
    pair<int, int> data;
    segtree *left, *right;
    public:
    segtree(vector<int> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            data = (A[R.first] == 1) ? make_pair(1, R.first) : make_pair(0, -1);
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new segtree(A, {R.first, mid});
            right = new segtree(A, {mid+1, R.second});
            data = func(left->data, right->data);
        }
    }

    void update(int idx) {
        if(range.first == range.second) {
            data = (data.first == 0) ? make_pair(1, idx) : make_pair(0, -1);
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx);
        else left->update(idx);
        data = func(left->data, right->data);
    }

    pair<int, int> q(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->q(R);
        else if(R.second <= mid) return left->q(R);
        else return func(left->q({R.first, mid}), right->q({mid+1, R.second}));
    }
    
    int query(pair<int, int> R, int k) {
        if(k > data.first) return -1;
        if(k == data.first) return data.second;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R, k);
        else if(R.second <= mid) return left->query(R, k);
        else {
            pair<int, int> L = left->q({R.first, mid});
            if(L.first >= k) return left->query({R.first, mid}, k);
            else return right->query({mid+1, R.second}, k - L.first);
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    segtree st(A, {0, n-1});
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 1) st.update(b);
        else cout << st.query({0, n-1}, b+1) << endl;
    }
}