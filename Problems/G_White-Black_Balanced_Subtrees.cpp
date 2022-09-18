#include <bits/stdc++.h>
using namespace std;

int b[4002];
vector<int> A[4002];
int vis[4002];

void dfs(int n) {
    vis[n] = true;
    for(int i : A[n]) {
        if(!vis[i]) {
            dfs(i);
            b[n] += b[i];
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i=1; i<=n; i++) A[i].clear(), vis[i] = false;
        for(int i=2; i<=n; i++) {
            int x;
            cin >> x;
            A[i].push_back(x);
            A[x].push_back(i);
        }

        string s;
        cin >> s;
        for(int i=0; i<n; i++) {
            b[i+1] = (s[i] == 'W') ? 1 : -1;
        }
        dfs(1);
        int ctr = 0;
        for(int i=1; i<=n; i++) ctr += (b[i] == 0);

        cout<<ctr<<endl;
    }
}