#include <bits/stdc++.h>
using namespace std;

#define int long long

int func(int a, int b) {
    return min(a, b);
}

template <typename T, T (*func) (T, T)>
class SegTree {
    pair<int, int> range;
    T data;
    SegTree *left, *right;
  public:
    SegTree(vector<T> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) { data = A[R.first]; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new SegTree(A, {R.first, mid});
            right = new SegTree(A, {mid+1, R.second});
            data = func(left->data, right->data);
        }
    }

    void update(int idx, int val) {
        if(range.first == range.second) {
            data = val;
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx, val);
        else left->update(idx, val);
        data = func(left->data, right->data);
    }

    T query(pair<int, int> R) {
        if(R.first > R.second) return 1e16;
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return func(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }

    void print() {
        cout<<range.first<<" "<<range.second<<" : "<<data<<endl;
        if(left) left->print();
        if(right) right->print();
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    vector<int> B = A, C = A;
    for(int i=0; i<n; i++) B[i] += i, C[i] -= i;
    SegTree<int, func> BB(B, {0, n-1});
    SegTree<int, func> CC(C, {0, n-1});

    while(q--) {
        int a;
        cin >> a;
        if(a == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            A[x] = y;
            BB.update(x, y+x);
            CC.update(x, y-x);
        }
        else {
            int x;
            cin >> x;
            x--;
            cout << min({A[x], BB.query({x+1, n-1})-x, CC.query({0, x-1})+x});
            cout << endl;
        }
    }
}