#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 998244353;

int main(){
    int n;
    cin >> n;
    int A[n + 1];

    for(int i = 1; i <= n; ++i){
        cin >> A[i];
    }

    ll dp[n + 1][n + 1][n + 1];
    ll ans = 0;
    
    for(int s = 1; s <= n; ++s){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                for(int k = 0; k < s; ++k){
                    if(i < j){
                        dp[i][j][k] = 0;
                        continue;
                    }
                    if(i == 1){
                        dp[1][j][k] = 0;
                        dp[1][1][A[1] % s] = 1;
                    }else if(j == 1){
                        dp[i][j][k] = dp[i - 1][j][k] + (A[i] % s == k ? 1 : 0);
                    }else{
                        dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][(k - A[i] % s + s) % s];
                    }
                    dp[i][j][k] %= MOD;
                    // cerr << "(" << s << ")dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << '\n';
                }
            }
        }
        ans = (ans + dp[n][s][0]) % MOD;
    }

    cout << ans << '\n';
}