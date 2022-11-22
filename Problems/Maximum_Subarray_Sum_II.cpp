#include <bits/stdc++.h>
using namespace std;

struct d {
    int s, mps, mss, msubs;
};

d f(d a, d b) {
    d c;
    c.s = a.s + b.s;
    c.mps = max(a.mps, a.s+b.mps);
    c.mss = max(b.mss, b.s+a.mss);
    c.msubs = max({c.mps, c.mss, a.mss+b.mps});
    return c;
}

class segtree {
    int l, r;
    d data;
    segtree *left, *right;
    public:
    segtree(vector<int> &A, int L, int R) {
        l = L; r = R;
        if (l == r) {
            if (A[l] > 0) data = {A[l], A[l], A[l], A[l]};
            else data = {A[l], 0, 0, 0};
            left = right = nullptr;
        }
        else {
            int m = (l + r) / 2;
            left = new segtree(A, L, m);
            right = new segtree(A, m+1, R);
            data = f(left->data, right->data);
        }
    }

    d query(int L, int R) {
        if (l == L && r == R) return data;
        else {
            int m = (l + r) / 2;
            if (L > m) return right->query(L, R);
            else if (R <= m) return left->query(L, R);
            else return f(left->query(L, m), right->query(m+1, R));
        }
    }
};

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    segtree st(A, 0, n-1);
    cout << st.query(--a, --b).msubs;
}