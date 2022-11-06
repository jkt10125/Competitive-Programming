#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int idx = 1, ctr = 3*n;
        vector<pair<int, int>> A;
        while(idx < ctr) {
            A.push_back({idx, ctr});
            ctr -= 3;
            idx += 3;
        }
        cout << A.size() << endl;
        for(auto p : A) {
            cout << p.first << ' ' << p.second << endl;
        }
    }
}