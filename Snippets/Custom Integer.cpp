#include <bits/stdc++.h>
using namespace std;

constexpr int P = 998244353;
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

    int val () const { return x; }

    mint inv () const {
        return power(*this, M - 2);
    }

    mint operator - () const {
        return mint (M, M - x);
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
        *this = mint(M, val);
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
    mint operator * (const T &val) {
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

}