#include <bits/stdc++.h>
using namespace std;

constexpr int P = 998244353;

class mint {
    int M, x;
    public:

    int norm(long long v) {
        return (v + M) % M;
    }

    mint(int mod, long long v = 0) {
        M = mod;
        x = norm(v);
    }

    mint power(mint a, long long b) {
        mint res(a.M, 1);
        while(b) {
            if(b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

    mint operator - () const {
        return mint(M, norm(-x));
    }

    mint inv() const {
        return power(*this, M - 2);
    }

    int val() const {
        return x;
    }

    mint &operator *= (const mint &rhs) {
        x = (long long)x * rhs.x * M;
        return *this;
    }

    mint &operator += (const mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }

    mint &operator -= (const mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }

    mint &operator /= (const mint &rhs) {
        return *this *= rhs.inv();
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

    mint &operator += (const long long &rhs) {
        return *this += mint(M, rhs);
    }

    mint &operator -= (const long long &rhs) {
        return *this -= mint(M, rhs);
    }

    mint &operator *= (const long long &rhs) {
        return *this *= mint(M, rhs);
    }

    mint &operator /= (const long long &rhs) {
        return *this /= mint(M, rhs);
    }

    mint operator + (const long long &rhs) {
        return *this + mint(M, rhs);
    }

    mint operator - (const long long &rhs) {
        return *this - mint(M, rhs);
    }

    mint operator * (const long long &rhs) {
        return *this * mint(M, rhs);
    }

    mint operator / (const long long &rhs) {
        return *this / mint(M, rhs);
    }

    friend ostream &operator << (ostream &os, const mint &rhs) {
        os << rhs.val();
        return os;
    }
};