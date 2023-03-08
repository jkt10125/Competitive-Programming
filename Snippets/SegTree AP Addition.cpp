#include <bits/stdc++.h>

class segtree {
    int L, R;
    int base, diff;

    segtree *left, *right;
    public:
    segtree(int l, int r) {
        L = l, R = r;
        base = 0, diff = 0;
        if (l == r) left = right = nullptr;
        else {
            int m = (l + r) / 2;
            left = new segtree(l, m);
            right = new segtree(m + 1, r);
        }
    }
    void update(int l, int r, int b, int d) {
        int M = (L + R) / 2;
        if (l == L && r == R) {
            base += b;
            diff += d;
        }
        else if (M < l) right->update(l, r, b, d);
        else if (M >= r) left->update(l, r, b, d);
        else {
            left->update(l, M, b, d);
            right->update(M + 1, r, b + (M - l + 1) * d, d);
        }
    }

    void query(int i, int &val) {
        val += base + (i - L) * diff;
        if (L == R) { }
        else {
            int M = (L + R) / 2;
            if (M < i) { right->query(i, val); }
            else { left->query(i, val); }
        }
    }

    void print() {
        std::cout << L << ' ' << R << " : " << base << ' ' << diff << std::endl;
        if (L != R) {
            left->print();
            right->print();
        }
    }
};


int main() {
    segtree st(0, 15);
    st.update(10, 13, 0, 8);
    st.update(11, 14, 0, 3);

    st.print();

    int val[16] = {};
    for (int i = 0; i < 16; i++) {
        st.query(i, val[i]);

        std::cout << val[i] << ' ';
    }

    // std::cout << std::endl << val << std::endl;
}