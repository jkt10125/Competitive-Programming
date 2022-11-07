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

vector<array<int, 2>> divisors (int n) {
    vector<int> p;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            p.push_back(i);
            while(n % i == 0) n /= i;
        }
    }
    if (n > 1) p.push_back(n);
    n = p.size();
    vector<array<int, 2>> a(1 << n);
    a[0] = {1, 1};
    for (int i = 1; i < (1 << n); i++) {
        int j = __builtin_ctz(i);
        auto [x, y] = a[i ^ (1 << j)];
        a[i] = {x * p[j], -y};
    }
    return a;
}

cint f(int a, int m) {
    // #gcd(a, x) = 1 : 1 <= x <= m
    cint res = 0;
    for(auto [x, y] : divisors(a)) {
        res += y * (m / x);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        cint ans = 1;
        for(int i=1; i<n; i++) {
            if(A[i-1] % A[i]) {
                ans = 0;
                break;
            }
            else ans *= f((A[i-1]/A[i]), (m/A[i]));
        }
        cout << ans << endl;
    }
}