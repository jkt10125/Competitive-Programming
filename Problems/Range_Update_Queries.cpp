#include <bits/stdc++.h>
using namespace std;

class lazysegtree {
    long long value, add_factor;
    pair<int, int> range;
    lazysegtree *left, *right;
    public:
    lazysegtree(vector<int> &A, pair<int, int> R) {
        range = R;
        add_factor = 0;
        if(R.first == R.second) {
            value = A[R.first];
            left = right = nullptr;
        }
        else {
            value = 0;
            int mid = (R.first + R.second) / 2;
            left = new lazysegtree(A, {R.first, mid});
            right = new lazysegtree(A, {mid+1, R.second});
        }
    }

    void push() {
        if(!add_factor) return;
        if(range.first == range.second) {
            value += add_factor;
        } 
        else {
            left->add_factor += add_factor;
            right->add_factor += add_factor;
        }
        add_factor = 0;
    }

    long long query(int idx) {
        push();
        if(range.first == range.second) return value;
        int mid = (range.first + range.second) / 2;
        if(idx > mid) return right->query(idx);
        else return left->query(idx);
    }

    void range_update(pair<int, int> R, int val) {
        if(range == R) add_factor += val;
        else {
            // push();
            int mid = (range.first + range.second) / 2;
            if(R.first > mid) right->range_update(R, val);
            else if(R.second <= mid) left->range_update(R, val);
            else {
                left->range_update({R.first, mid}, val);
                right->range_update({mid+1, R.second}, val);
            } 
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    lazysegtree T(A, {0, n-1});
    while(q--) {
        int a, b, u, k, c;
        cin >> c;
        if(c == 1) {
            cin >> a >> b >> u;
            T.range_update({--a, --b}, u);
        }
        else {
            cin >> k;
            cout << T.query(--k) << endl;
        }
    }
}