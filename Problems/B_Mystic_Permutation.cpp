#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

void make_set(int n) {
    parent.resize(n);
    for(int i=0; i<n; i++) {
        parent[i] = i;
    }
}

int find_set(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find_set(parent[x]);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n+1);
        for(int i=1; i<=n; i++) cin >> A[i];
        
        if(n == 1) {
            cout<<"-1\n";
            continue;
        }
        
        vector<int> ans(n+1);
        vector<bool> used(n+1);

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(!used[j] && A[i] != j) {
                    ans[i] = j;
                    used[j] = true;
                    break;
                }
            }
        }
        if(ans[n] == 0) {
            ans[n] = n;
            swap(ans[n-1], ans[n]);
        }

        for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}