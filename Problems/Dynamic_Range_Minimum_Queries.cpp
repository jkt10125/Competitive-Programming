#include <bits/stdc++.h>
using namespace std;

class segtree {
    int range_min;
    pair<int, int> range;
    segtree *left, *right;
    public:
    segtree(vector<int> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            range_min = A[R.first];
            left = right = nullptr;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new segtree(A, {R.first, mid});
            right = new segtree(A, {mid+1, R.second});
            range_min = min(left->range_min, right->range_min);
        }
    }

    void update(int idx, int val) {
        if(range.first == range.second) range_min = val;
        else {
            int mid = (range.first + range.second) / 2;
            if(idx > mid) right->update(idx, val);
            else left->update(idx, val);
            range_min = min(left->range_min, right->range_min);
        }
    }

    int query(pair<int, int> R) {
        if(range == R) return range_min;
        else {
            int mid = (range.first + range.second) / 2;
            if(R.second <= mid) return left->query(R);
            else if(R.first > mid) return right->query(R);
            else {
                return min(left->query({R.first, mid}), right->query({mid+1, R.second}));
            }
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
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) T.update(--b, c);
        else cout << T.query({--b, --c}) << "\n";
    }
}