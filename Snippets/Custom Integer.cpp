#include <bits/stdc++.h>
using namespace std;

constexpr int P = 998244353;
class mint {
    int M, x;
    
    int norm (int val) const {
        return (val + M) % M;
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

    int val () const { return x; }

    mint inv () const {
        return power(*this, M - 2);
    }

    mint operator - () const {
        return mint (M, -x);
    }

    mint &operator *= (const mint &rhs) {
        assert (M == rhs.M);
        x = (long long)x * rhs.x % M;
        return *this;
    }

    mint &operator /= (const mint &rhs) {
        assert (M == rhs.M);
        return *this *= rhs.inv();
    }

    mint &operator += (const mint &rhs) {
        assert (M == rhs.M);
        x = norm(x + rhs.x);
        return *this;
    }

    mint &operator -= (const mint &rhs) {
        assert (M == rhs.M);
        x = norm(x - rhs.x);
        return *this;
    }

    mint operator * (const mint &rhs) {
        mint res = *this;
        return res *= rhs;
    }

    mint operator / (const mint &rhs) {
        mint res = *this;
        return res /= rhs;
    }

    mint operator + (const mint &rhs) {
        mint res = *this;
        return res += rhs;
    }

    mint operator - (const mint &rhs) {
        mint res = *this;
        return res -= rhs;
    }

    bool operator == (const mint &rhs) {
        /* Only x is compared and not M */
        return this->x == rhs.x;
    }

    mint &operator = (const mint &rhs) {
        x = rhs.x;
        M = rhs.M;
        return *this;
    }

    bool operator == (const int &rhs) {
        return this->x == rhs;
    }

    friend bool operator == (const int &lhs, const mint &rhs) {
        return lhs == rhs.x;
    }

    void operator = (const int &val) {
        x = norm(val);
    }

    mint &operator *= (const int val) {
        return *this *= mint(M, val);
    }
    
    mint &operator /= (const int val) {
        return *this /= mint(M, val);
    }
    
    mint &operator += (const int val) {
        return *this += mint(M, val);
    }
    
    mint &operator -= (const int val) {
        return *this -= mint(M, val);
    }

    mint operator * (const int &val) {
        mint res = *this;
        return res *= mint(M, val);
    }

    mint operator / (const int &val) {
        mint res = *this;
        return res /= mint(M, val);
    }
    
    mint operator + (const int &val) {
        mint res = *this;
        return res += mint(M, val);
    }

    mint operator - (const int &val) {
        mint res = *this;
        return res -= mint(M, val);
    }

    friend mint operator * (const int &lhs, const mint &rhs) {
        mint res(rhs.M, lhs);
        return res *= rhs;
    }

    friend mint operator / (const int &lhs, const mint &rhs) {
        mint res(rhs.M, lhs);
        return res /= rhs;
    }

    friend mint operator + (const int &lhs, const mint &rhs) {
        mint res(rhs.M, lhs);
        return res += rhs;
    }

    friend mint operator - (const int &lhs, const mint &rhs) {
        mint res(rhs.M, lhs);
        return res -= rhs;
    }

    friend ostream &operator << (ostream &os, const mint &rhs) {
        return os << rhs.x;
    }

    // friend istream &operator >> (istream &is, mint &rhs) {
    //     int val;
    //     is >> val;
    //     rhs = mint(???, val);
    //     return is;
    // } 
};

int main() {
    int a = 21;
    mint b(7, 6), c(13, 7), d(17, 5);
    b = a;
    d = a;
    c = a;
    b = c = d;
    cout << b << c << d;
}