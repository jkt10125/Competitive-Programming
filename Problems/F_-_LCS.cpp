#include <iostream>
using namespace std;

#define ll long long

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    int dp[n+1][m+1];
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<=m; i++) dp[0][i] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string ans;
    int p1=n, p2=m;
    while(p1>0 && p2>0) {
        if(dp[p1][p2] == dp[p1-1][p2-1] + 1 && s[p1-1] == t[p2-1]) {
            ans += s[p1-1];
            p1--; p2--;
        }
        else if(dp[p1][p2] == dp[p1][p2-1]) p2--;
        else p1--;
    }

    for(int i=ans.size()-1; i>=0; i--) cout<<ans[i];
}