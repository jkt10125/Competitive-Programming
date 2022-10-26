#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        if(n & 1) cout << -1 << endl;
        else {
            vector<pair<int, int>> v;
            v.push_back({0, 0});
            for(int i=1; i<n; i+=2) {
                if(A[i] == A[i-1]) v.back().second++;
                else v.push_back({i, i});

                if(i+1 < n) v.push_back({i+1, i+1});
            }

            cout << v.size() << endl;
            for(auto p : v) cout << p.first + 1 << ' ' << p.second + 1 << endl;
        }
    }
}