#include <bits/stdc++.h>
using namespace std;

vector<int> vis, cap, ans;
vector<vector<int>> A;

void dfs(int n) {
    if(ans[n]) return;
    for (int it : A[n]) {
        dfs(it);
        ans[n] += ans[it] + 1;
    }
}

int main() {
    int t;
    cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        cout << "Case #" << _i << ": ";

        int n;
        cin >> n;
        cap.assign(n+1, 0);
        ans.assign(n+1, 0);
        vis.assign(n+1, 0);
        A.assign(n+1, vector<int>());
        for (int i=1; i<=n; i++) cin >> cap[i];
        for (int i=1; i<n; i++) {
            int x, y;
            cin >> x >> y;
            if (cap[x] > cap[y]) { 
                A[x].push_back(y);
            }
            else if (cap[y] > cap[x]) {
                A[y].push_back(x);
            }
        }

        for(int i=1; i<=n; i++) {
            if(ans[i] == 0) {
                dfs(i);
            }
        }

        cout << *max_element(ans.begin(), ans.end()) + 1<< endl;
    }
}