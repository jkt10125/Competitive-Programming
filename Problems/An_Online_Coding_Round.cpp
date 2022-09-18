#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int, vector<int>> factors_hash;

void factors(long long n) {
    if(!factors_hash[n].empty()) return;
    int _a = n;
    vector<long long> factorization(1, 1);
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if(n > 1) factorization.push_back(n);
    factors_hash[_a] = factorization;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        vector<int> dp(n, (long long)1000000000000000);
        dp[0] = 0;
        for(int i=0; i<n-1; i++) {
            factors(A[i]);
            for(auto j : factors_hash[A[i]]) {
                if(i + j >= n) break;
                dp[i+j] = min(dp[i+j], dp[i]+abs(A[i]-A[i+j]));
            }
        }
        cout<<dp[n-1]<<endl;
    }
}