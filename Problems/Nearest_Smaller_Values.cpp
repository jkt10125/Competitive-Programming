#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> A;
    vector<int> ans;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        int ctr = 0;
        while(!A.empty() && A.back().first >= x) {
            ctr = A.back().second;
            A.pop_back();
        }
        if(A.empty()) ans.push_back(0);
        else ans.push_back(A.back().second);
        A.push_back({x, i+1});
    }

    for(auto it : ans) cout<<it<<" ";
}