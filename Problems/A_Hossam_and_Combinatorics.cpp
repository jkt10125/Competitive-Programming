#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> A;
        for(int i = 0; i<n; i++) {
            int x;
            cin >> x;
            A[x]++;
        }

        if (A.size() != 1) 
        cout << (A.begin()->second ) * 2 * (A.rbegin()->second) << endl;
        else {
            cout << (A.begin()->second) * (A.rbegin()->second - 1) << endl;
        }
    }
}