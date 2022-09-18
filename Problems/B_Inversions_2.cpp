#include <bits/stdc++.h>
using namespace std;

pair<int, int> func(pair<int, int> L, pair<int, int> R) {
    if(R.second == -1) return L;
    return make_pair(R.first+L.first, R.second);
}

class segtree {
    pair<int, int> range;
    pair<int, int> data;
    segtree *left, *right;
    public:
    segtree(pair<int, int> R) {
        range = R;
        if(R.first == R.second) {
            data = {1, R.second};
            left = right = NULL;
        }
        else {
            int mid = (R.first + R.second) / 2;
            left = new segtree({R.first, mid});
            right = new segtree({mid+1, R.second});
            data = func(left->data, right->data);
        }
    }

    void update(int idx) {
        if(range.first == range.second) {
            data = {0, -1};
            return;
        }
        int mid = (range.first + range.second) / 2;
        if(idx > mid) right->update(idx);
        else left->update(idx);
        data = func(left->data, right->data);
    }

    int query(int sum) {
        if(sum == 0) return range.second;
        if(range.first == range.second) return range.first;
        int mid = (range.first + range.second) / 2;
        if(right->data >= sum) return right->query(sum);
        else return left->query(sum - right->data);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    segtree st({0, n});
    cout << st.query(1);
}