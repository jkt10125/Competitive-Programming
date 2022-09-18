#include <bits/stdc++.h>
using namespace std;

class segtree {
    pair<int, int> range;
    long long data;
    segtree *left, *right;
    public:
    segtree(vector<long long> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            data = A[R.first];
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new segtree(A, {R.first, mid});
            right = new segtree(A, {mid+1, R.second});
            data = left->data + right->data;
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
            data = left->data + right->data;
        }
    }

    long long query(pair<int, int> R) {
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        else {
            return left->query({R.first, mid}) + right->query({mid+1, R.second});
        }
    }

    void print() {
        cout << range.first << " " << range.second << " " << data << endl;
        if(left) left->print();
        if(right) right->print();
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    segtree T(A, {0, n-1});
    // T.print();
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) T.update(b, c);
        else cout << T.query({b, c-1}) << endl;
    }
}