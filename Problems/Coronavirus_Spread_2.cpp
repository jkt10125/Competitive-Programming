#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> pos(n, vector<int> (7, 0));
        for(int i=0; i<n; i++) pos[i][0] = i;
        for(int i=0; i<n; i++) {
            for(int j=1; j<7; j++) pos[i][j] = pos[i][j-1] + a[i];
        }
        int mx = INT_MIN, mn = INT_MAX;
        for(int j=0; j<7; j++) {
            map<int, int> AA;
            for(int i=0; i<n; i++) {
                AA[pos[i][j]]++;
            }
            int ctr = 0;
            for(auto it: AA) {
                ctr = max(ctr, it.second);
            }
            mx = max(mx, ctr);
            mn = min(mn, ctr);
        }
        cout<<mx<<" "<<mn<<"\n";
    }
}