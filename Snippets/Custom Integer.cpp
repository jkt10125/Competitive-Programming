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

    int power (long long a, int b) const {
        int pow = 1;
        while (b) {
            if (b & 1) {
                pow = pow * a % M;
            } 
            a = a * a % M;
            b >>= 1;
        }
        return pow;
    }

    public:
    mint (int mod, int val = 0) : M(mod), x(norm(val)) { }
    mint (int mod, long long val) : M(mod), x(norm(val % M)) { }

    int val () { return x; }

    mint operator - () const {
        return mint (M, M - x);
    }

    mint inv () const {
        return mint (M, power(x, M - 2));
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
    mint &operator * (const T &val) {
        mint res = *this;
        res *= mint(M, val);
        return res;
    }

    template <typename T>
    mint &operator / (const T &val) {
        mint res = *this;
        res /= mint(M, val);
        return res;
    }
    
    template <typename T>
    mint &operator + (const T &val) {
        mint res = *this;
        res += mint(M, val);
        return res;
    }

    template <typename T>
    mint &operator - (const T &val) {
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