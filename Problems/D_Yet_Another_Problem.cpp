#include <bits/stdc++.h>
using namespace std;

bool f(bool a, bool b) {
    return (a & b);
}

template <typename T, T (*func) (T, T)>
class SegTree {
    pair<int, int> range;
    T data;
    SegTree *left, *right;
  public:
    SegTree(vector<int> &A, pair<int, int> R) {
        range = R;
        if(R.first == R.second) { data = (A[R.first] == 0); left = right = NULL; }
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
        if(range == R) return data;
        int mid = (range.first + range.second) / 2;
        if(R.first > mid) return right->query(R);
        else if(R.second <= mid) return left->query(R);
        return func(left->query({R.first, mid}), right->query({mid+1, R.second}));
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n+1), a(n+1);
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        A[i] = (A[i-1] ^ x);
    } 
    SegTree<bool, f> ST(a, {0, n});
    map<pair<int, int>, int> m;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if(m[{l, r}] != 0) cout << m[{l, r}] << endl;
        else if((A[r] ^ A[l-1]) != 0) { m[{l, r}] = -1; cout << "-1\n"; continue; }
        else {
            while(!(len & 1)) len >>= 1;
            bool ok = true;
            int ctr = 0;
            for(int i=l; i+len-1 <= r; i+=len) {
                if((A[i+len-1] ^ A[i-1]) != 0) {
                    ok = false;
                    break;
                }
                else if(ST.query({i, i+len-1})) ;
                else ctr++;
            }
            if(!ok) m[{l, r}] = -1;
            else m[{l, r}] = ctr;

            cout << m[{l, r}] << endl;
        }
    }
}