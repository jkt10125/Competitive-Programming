#include <bits/stdc++.h>
using namespace std;

class segtree {
    pair<int, int> range;
    int data;
    segtree *left, *right;
    public:
    segtree(vector<int> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            data = A[R.first];
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new segtree(A, {R.first, mid});
            right = new segtree(A, {mid+1, R.second});
            data = min(left->data, right->data);
        }
    }

    void update(int idx, int val) {
        if(range.first == range.second) {
            data = val;
            return;
        }
        else {
            int mid = (range.first + range.second) / 2;
            if(idx > mid) right->update(idx, val);
            else left->update(idx, val);
            data = min(left->data, right->data);
        }
    }

    int query(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return min(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i=0; i< n; i++) cin >> A[i];
    segtree st(A, {0, n-1});
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) st.update(b, c);
        else cout << st.query({b, c-1}) << endl;
    }
}