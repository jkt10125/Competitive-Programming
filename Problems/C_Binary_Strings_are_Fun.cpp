#include <bits/stdc++.h>
using namespace std;

constexpr int P = 998244353;

class mint {
    int M, x;
    public:

    int norm (long long v) {
        return (v % M + M) % M;
    }

    mint (int mod, long long v = 0) {
        M = mod;
        x = norm(v);
    }

    mint () {
        M = x = 0;
    }

    mint power (mint a, long long b) const {
        mint res (a.M, 1);
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

    mint operator - () const {
        return mint(M, -x);
    }

    mint inv () const {
        return power (*this, M - 2);
    }

    int val () const {
        return x;
    }

    mint &operator *= (const mint &rhs) {
        x = (long long)x * rhs.x % M;
        return *this;
    }

    mint &operator += (const mint &rhs) {
        x = norm (x + rhs.x);
        return *this;
    }

    mint &operator -= (const mint &rhs) {
        x = norm (x - rhs.x);
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

    bool operator == (const mint &rhs) const {
        return x == rhs.x;
    }

    mint operator = (const long long &rhs) {
        x = norm(rhs);
        return *this;
    }

    friend ostream &operator << (ostream &os, const mint &rhs) {
        os << rhs.val();
        return os;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        mint ans(P, 0), curr(P, 1);
        int last = 0;
        for (char c : s) {
            if (last != c) curr = 1;
            else curr *= 2;
            ans += curr;
            last = c;
        }
        cout << ans << endl;
    }
}