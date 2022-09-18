#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin >> q;
    int ctr = 0;
    map<int, vector<int>> A;
    while(q--) {
        int a;
        cin >> a;
        if(a == 1) {
            int b;
            cin >> b;
            A[b].push_back(ctr++);
        }
        else {
            int b, c;
            cin >> b >> c;
            if(b == c) continue;
            if(A[b].size() > A[c].size()) A[b].swap(A[c]);
            for(int i : A[b]) A[c].push_back(i);
            A[b].clear();
        }
    }
    vector<int> ans(ctr, 0);
    for(auto it : A) {
        for(int iit : it.second) {
            ans[iit] = it.first;
        }
    }
    for(int i : ans) cout<<i<<" ";
}