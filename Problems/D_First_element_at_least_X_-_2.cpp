#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define ff first
#define ss second

pii f(pii L, pii R) {
    return (R > L) ? R : L;
}

class segtree {
    pii range;
    pii data;
    segtree *left, *right;
    public:
    segtree(pii R, vi &A) {
        range = R;
        if(R.ff == R.ss) {
            data = {A[R.ff], R.ff};
            left = right = NULL;
        }
        else {
            int mid = (R.ff + R.ss) / 2;
            left = new segtree({R.ff, mid}, A);
            right = new segtree({mid + 1, R.ss}, A);
            data = f(left->data, right->data);
        }
    }
    
    void update(int idx, int x) {
        if(range.ff == range.ss) data = {x, idx};
        else {
            int mid = (range.ff + range.ss) / 2;
            if(idx <= mid) left->update(idx, x);
            else right->update(idx, x);
            data = f(left->data, right->data);
        }
    }

    int q(pii R) {
        if(range.ff == range.ss) return data.ff;
        if(range == R) return data.ff;
        int mid = (range.ff + range.ss) / 2;
        if(R.ff > mid) return right->q(R);
        else if(R.ss <= mid) return left->q(R);
        else {
            return max(left->q({R.ff, mid}), right->q({mid + 1, R.ss}));
        } 
    }

    int query(pii R, int x) {
        // cerr << "query " << range.ff << " " << range.ss << " " << x << endl;
        if(data.ff < x) return -1;
        if(range.ff == range.ss) return data.ss;
        if(range == R) {
            int mid = (range.ff + range.ss) / 2;
            if(x <= left->data.ff) return left->query({R.ff, mid}, x);
            else return right->query({mid + 1, R.ss}, x);
        }
        else {
            int mid = (range.ff + range.ss) / 2;
            if(R.ss <= mid) return left->query(R, x);
            else if(R.ff > mid) return right->query(R, x);
            else {
                int l = left->q({R.ff, mid});
                if(l >= x) return left->query({R.ff, mid}, x);
                else {
                    return right->query({mid + 1, R.ss}, x);
                }
            }
        }
    }

    void print() {
        cout << range.ff << " " << range.ss << " " << data.ff << " " << data.ss << endl;
        if(left) left->print();
        if(right) right->print();
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vi A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    segtree T({0, n - 1}, A);
    // T.print();
    // T.query({2, 4}, 3);
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) T.update(b, c);
        else cout << T.query({c, n-1}, b) << endl;

    }
}