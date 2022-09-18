#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> A;
int dfs(int n) {
    if(dp[n] != -1) return dp[n];
    dp[n] = 0;
    for(int i : A[n]) {
        dp[n] += dfs(i);
    }
    return ++dp[n];
}


int main() {
    int n;
    cin >> n;
    A.resize(n+1);
    dp.resize(n+1, -1);

    for(int i=2; i<=n; i++) {
        int x;
        cin >> x;
        A[x].push_back(i);
    }

    dfs(1);

    for(int i=1; i<=n; i++) cout<<dp[i]-1<<" ";
}