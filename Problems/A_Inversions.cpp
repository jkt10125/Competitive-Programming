#include <bits/stdc++.h>
using namespace std;

class segtree {
    pair<int, int> range;
    int data;
    segtree *left, *right;
    public:
    segtree(pair<int, int> R) {
        range = R;
        data = 0;
        if(R.first == R.second) { left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new segtree({R.first, mid});
            right = new segtree({mid+1, R.second});
        }
    }

    void update(int idx) {
        if(range.first == range.second) { data = 1; return; }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx);
        else left->update(idx);
        data = left->data + right->data;
    }

    int query(pair<int, int> R) {
        if(R.first > R.second) return 0;
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        else {
            return (left->query({R.first, mid}) + right->query({mid+1, R.second}));
        }
    }

    void print() {
        cerr << range.first << " " << range.second << " " << data << endl;
        if(left) left->print();
        if(right) right->print();
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    // for(int i=0; i<n; i++) cout << A[i];

    segtree st({0, n});
    for(int i=0; i<n; i++) {
        cout<<st.query({A[i]+1, n})<<" ";
        st.update(A[i]);
    }
    // st.print();
}