#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 7;

int ans[N], a[N], b[N];

vector<int> tmp;
vector<vector<int>> A;
int ctr;

void dfs(int n) {
    if(n == 1) tmp.push_back(b[1]);
    else {
        int i = upper_bound(tmp.begin(), tmp.end(), ctr) - tmp.begin();
        ans[n] = i - 1;
    }

    for(int it : A[n]) {
        tmp.push_back(tmp.back() + b[it]);
        ctr += a[it];
            
        dfs(it);
            
        ctr -= a[it];
        tmp.pop_back();
    }
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        tmp.clear();
        A.assign(n+1, vector<int> ());
        ctr = 0;
        for(int i=2; i<=n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            A[x].push_back(i);
            a[i] = y; b[i] = z;
        }

        dfs(1);
        for(int i=2; i<=n; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}