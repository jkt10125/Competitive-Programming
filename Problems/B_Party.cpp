#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<long long, int>> uh(n);
        vector<long long> uuh(n+1);
        vector<vector<int>> c(n+1);
        for(int i=0; i<n; i++) {
            cin >> uh[i].first;
            uh[i].second = i+1;
            uuh[i+1] = uh[i].first;
        }

        for(int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            c[u].push_back(v);
            c[v].push_back(u);
        }

        if(m % 2 == 0) {
            cout<<0<<endl;
        }
        else {
            sort(uh.begin(), uh.end());
            long long rans = INT_MAX;
            for(int i=0; i<n; i++) {
                long long ans = INT_MAX;
                for(int it : c[uh[i].second]) {
                    if(c[it].size() % 2 == 0) {
                        ans = min(ans, uuh[uh[i].second] + uuh[it]);
                    }
                }
                rans = min(rans, ans);
            }
            for(int i=0; i<n; i++) {
                if(c[uh[i].second].size() & 1) {
                    rans = min(rans, uuh[uh[i].second]);
                    break;
                }
            }
            cout<<rans<<endl;
        }
    }
}