#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ctr = 0;
    for(char c : s) {
        ctr += (c - '0');
    }
    if(ctr & 1) { cout<<"NO"; return; }
    cout<<"YES\n";

    vector<pair<int, int>> ans;
    for(int i=2; i<n; i++) {
        if(s[i-1] == '0') {
            int j = i+1;
            while(s[j-1] == '0' && j < n) { ans.push_back({i, j}); j++; }
            ans.push_back({i, j});
            i = j;
        }
    }
    for(int i=2; i<n; i++) {
        if(s[i-1] == '1') {
            ans.push_back({1, i});
        }
    }

    for(auto p : ans) {
        cout<<p.first<<" "<<p.second<<"\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
}