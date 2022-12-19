#include <bits/stdc++.h>
using namespace std;

#define int long long

template <typename T>
T MIN(T a, T b) {
    return min (a, b);
}

template <typename T, T (*func) (T, T)>
class SegTree {
    pair<int, int> range;
    T data;
    SegTree *left, *right;
  public:
    SegTree(vector<pair<int, T>> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) { data = A[R.first].second; left = right = NULL; }
        else {
            int mid = (R.first + R.second) / 2;
            left = new SegTree(A, {R.first, mid});
            right = new SegTree(A, {mid+1, R.second});
            data = func(left->data, right->data);
        }
    }

    void update(int idx, T val) {
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
        if (R.first > R.second) return 0;
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return func(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, signed>> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> A[i].second;
        }

        sort(A.begin(), A.end());
        SegTree<signed, MIN> st(A, {0, n - 1});

        int dmg = 0;
        int left = n;
        while (k > 0 && left > 0) {
            dmg += k;
            int idx = upper_bound(A.begin(), A.end(), make_pair(dmg, INT_MAX)) - A.begin();
            int min_power = st.query({idx, n - 1});
            k -= min_power;
            left = n - idx;
        }

        if (k <= 0) {
            int idx = upper_bound(A.begin(), A.end(), make_pair(dmg, -1)) - A.begin();
            left = n - idx;
        }

        if (left > 0) cout << "NO\n";
        else cout << "YES\n";
    }
}