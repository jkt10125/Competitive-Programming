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

mint f(int a, int m) {
    // #gcd(a, x) = 1 : 1 <= x <= m
    mint res(P);
    res = 0;
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

        mint ans(P);
        ans = 1;
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