#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A;
vector<int> cyc, vis;
int n;

int ctr = 0;
void dfs(int x) {
    vis[x] = true;
    ctr++;
    for (int it : A[x]) {
        if(!vis[it]) {
            dfs(it);
        }
    }
}

int f(int x) {

    if(binary_search(cyc.begin(), cyc.end(), x)) return 0;
    
    int l = 0, r = cyc.size()-1;
    while(l < r) {
        if(cyc[l] + cyc[r] == x) return 1;
        if(cyc[l] + cyc[r] > x) r--;
        else l++;
    }
    
    int ctra = 0;
    int fc = cyc.size()-1;
    while(fc > 0) {
        if(x <= cyc[fc]) {
            if(binary_search(cyc.begin(), cyc.begin() + fc + 1, x)) return ctra;
            else return ctra + 1;
        }
        x -= cyc[fc];
        ctra++;
        if(x < 0) return ctra;
        fc--;
    }
    return cyc.size() - 1;
}

int main() {
    int t;
    cin >> t;
    for (int _i = 1; _i <= t; _i++) {
        cout << "Case #" << _i << ": ";

        cin >> n;
        A.assign(n+1, vector<int> ());
        cyc.clear();
        vis.assign(n+1, 0);

        for(int i=1; i<=n; i++) {
            int x;
            cin >> x;
            A[i].push_back(x);
        }

        for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                ctr = 0;
                dfs(i);
                cyc.push_back(ctr);                
            }
        }
        sort(cyc.begin(), cyc.end());
        for(int i=1; i<=n; i++) {
            cout << f(i) << " ";
        }
        // for(auto it : cyc) cerr << it << ' ';
        // cerr << endl;
        cout << endl;
    }
}