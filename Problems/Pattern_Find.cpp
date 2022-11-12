#include <bits/stdc++.h>
using namespace std;

class mint {
    int M, x;
    
    int norm (int val) const {
        if (val < 0)  val += M;
        if (val >= M) val -= M;
        return val;
    }

    public:
    mint power (mint a, int b) const {
        mint res(a.M, 1);
        for (; b; b >>= 1, a *= a) {
            if (b & 1) res *= a;
        }
        return res;
    }

    mint (int mod, int val = 0) : M(mod), x(norm(val)) { }
    mint (int mod, long long val) : M(mod), x(norm(val % M)) { }

    int val () { return x; }

    mint operator - () const {
        return mint (M, M - x);
    }

    mint inv () const {
        return power(*this, M - 2);
    }

    mint &operator *= (const mint &rhs) {
        assert(M == rhs.M);
        x = (long long)x * rhs.x % M;
        return *this;
    }

    mint &operator /= (const mint &rhs) {
        assert(M == rhs.M);
        return *this *= rhs.inv();
    }

    mint &operator += (const mint &rhs) {
        assert(M == rhs.M);
        x = norm(x + rhs.x);
        return *this;
    }

    mint &operator -= (const mint &rhs) {
        assert(M == rhs.M);
        x = norm(x - rhs.x);
        return *this;
    }

    mint operator * (const mint &rhs) {
        mint res = *this;
        res *= rhs;
        return res;
    }

    mint operator / (const mint &rhs) {
        mint res = *this;
        res /= rhs;
        return res;
    }

    mint operator + (const mint &rhs) {
        mint res = *this;
        res += rhs;
        return res;
    }

    mint operator - (const mint &rhs) {
        mint res = *this;
        res -= rhs;
        return res;
    }
    
    template <typename T>
    void operator = (const T val) {
        x = norm(val);
    }

    template <typename T>
    mint &operator *= (const T val) {
        return *this *= mint(M, val);
    }
    
    template <typename T>
    mint &operator /= (const T val) {
        return *this /= mint(M, val);
    }
    
    template <typename T>
    mint &operator += (const T val) {
        return *this += mint(M, val);
    }
    
    template <typename T>
    mint &operator -= (const T val) {
        return *this -= mint(M, val);
    }

    template <typename T>
    mint operator * (const T val) {
        mint res = *this;
        res *= mint(M, val);
        return res;
    }

    template <typename T>
    mint operator / (const T &val) {
        mint res = *this;
        res /= mint(M, val);
        return res;
    }
    
    template <typename T>
    mint operator + (const T &val) {
        mint res = *this;
        res += mint(M, val);
        return res;
    }

    template <typename T>
    mint operator - (const T &val) {
        mint res = *this;
        res -= mint(M, val);
        return res;
    }

    bool operator == (const mint &A) {
        return (this->x == A.x && this->M == A.M);
    }

    friend ostream &operator << (ostream &os, const mint &rhs) {
        return os << rhs.x;
    }
};

const int m1 = 1000000007;
const int m2 = 1000000009;
const int hash_exp = 31;

array<mint, 2> string_hash (string &s) { // O(n)
    mint h1(m1, 0), exp1(m1, 1);
    mint h2(m2, 0), exp2(m2, 1);
    
    for (char c : s) {
        h1 += exp1 * (c - 'a' + 1);
        h2 += exp2 * (c - 'a' + 1);
        exp1 *= hash_exp;
        exp2 *= hash_exp;
    }

    return {h1, h2};
}

vector<array<mint, 2>> p_hash;
void generate_hash(string &s) { // O(n)
    mint h1(m1, 0), exp1(m1, 1);
    mint h2(m2, 0), exp2(m2, 1);

    p_hash.assign(s.size(), {0, 0});
    int i=0;
    for (char c : s) {
        h1 += exp1 * (c - 'a' + 1);
        h2 += exp2 * (c - 'a' + 1);
        exp1 *= hash_exp;
        exp2 *= hash_exp;
        p_hash[i++] = {h1, h2};
    }
}

array<mint, 2> substring_hash (int l, int r) { // O(log n)
    if (!l) return p_hash[r];
    mint f1(m1, hash_exp), f2(m2, hash_exp);
    f1 = (p_hash[r][0] - p_hash[l-1][0]) * f1.power(f1, l).inv();
    f2 = (p_hash[r][1] - p_hash[l-1][1]) * f2.power(f2, l).inv();
    return {f1, f2};
}

// bool f(array<mint, 2> a, array<mint, 2> b) {
//     return (a[0] == b[0]) && (a[1] == b[1]);
// }



signed main() {
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        generate_hash(s);
        array<mint, 2> key = string_hash(t);

        vector<int> A;
        for (int i = 0; i <= s.size() - t.size(); i++) {
            auto [x, y] = substring_hash(i, i + t.size() - 1);
            auto [a, b] = key;
            if (x == a && y == b) {
                A.push_back(i + 1);
            }
            // if (substring_hash(i, i + t.size() - 1) == key) {
            //     A.push_back(i + 1);
            // }
        }

        if (A.empty()) cout << "Not Found";
        else {
            cout << A.size() << endl;
            for (int i : A) cout << i << ' ';
        }
        cout << endl << endl;
    }
}
