#include <bits/stdc++.h>
using namespace std;

#define int long long

map<int, int> M, vis;

map<int, vector<int>> A;

int ans, tmp;

void dfs (int x) {
    vis[x] = true;
    tmp += x * M[x];
    for (int it : A[x]) {
        if (!vis[it]) {
            dfs(it);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sum += x;
        M[x]++;
        if(x > 0 && x < m - 1) {
            A[x + 1].push_back(x);
            A[x - 1].push_back(x);
        }
        else if (x == 0) {
            A[m - 1].push_back(0);
            A[1].push_back(0);
        }
        else {
            A[0].push_back(m - 1);
            A[m - 2].push_back(m - 1);
        }
    }

    ans = 0;
    for (auto [a, b] : M) {
        if (!vis[a]) {
            tmp = 0;
            dfs(a);
            ans = max(ans, tmp);
        }
    }

    cout << sum - ans;
}