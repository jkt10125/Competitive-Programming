#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        vector<int> A;

        cin >> n >> s;
        A.resize(n+1);
        for(int i=1; i<=n; i++) cin >> A[i];

        vector<vector<int>> period;
        vector<int> temp;
        vector<bool> vis(n+1, false);
        for(int i=1; i<=n; i++) {
            temp.clear();
            if(vis[i]) continue;
            vis[i] = true;
            temp.push_back(i);
            i = A[i];
            while(i != temp.front()) {
                vis[i] = true;
                temp.push_back(i);
                i = A[i];
            }
            period.push_back(temp);
        }

        // for(auto it : period) {
        //     for(auto i : it) cout<<i<<" ";
        //     cout<<"\n";
        // }

        ll ans = 1;
        for(auto it : period) {
            bool flag = true;
            for(int i=0; i<it.size(); i++) {
                if(s[it[i]-1] != s[it[0]-1]) {
                    flag = false;
                    break;
                }
            }
            if(!flag) ans = lcm(ans, it.size());
        }
        cout<<ans<<"\n";
    }
}