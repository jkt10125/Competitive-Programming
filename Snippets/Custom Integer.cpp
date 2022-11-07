#include <bits/stdc++.h>
using namespace std;

constexpr int P = 998244353;

int norm(int x) {
    if (x < 0) { x += P; }
    if (x >= P) { x -= P; }
    return x;
}

template <class T>
T power(T a, long long b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
class cint {
    int x;
    public:
    cint(int x = 0) : x(norm(x)) {}
    cint(long long x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }

    cint operator-() const {
        return cint(norm(P - x));
    }

    cint inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }

    cint &operator*=(const cint &rhs) {
        x = (long long)x * rhs.x % P;
        return *this;
    }

    cint &operator+=(const cint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }

    cint &operator-=(const cint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }

    cint &operator/=(const cint &rhs) {
        return *this *= rhs.inv();
    }

    friend cint operator*(const cint &lhs, const cint &rhs) {
        cint res = lhs;
        res *= rhs;
        return res;
    }

    friend cint operator+(const cint &lhs, const cint &rhs) {
        cint res = lhs;
        res += rhs;
        return res;
    }

    friend cint operator-(const cint &lhs, const cint &rhs) {
        cint res = lhs;
        res -= rhs;
        return res;
    }

    friend cint operator/(const cint &lhs, const cint &rhs) {
        cint res = lhs;
        res /= rhs;
        return res;
    }

    friend std::istream &operator>>(std::istream &is, cint &a) {
        long long v;
        is >> v;
        a = cint(v);
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const cint &a) {
        return os << a.val();
    }
};

