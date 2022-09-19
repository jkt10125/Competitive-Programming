#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];
        map<int, vector<int>> M;
        for(int i=0; i<n; i++) {
            M[i%k].push_back(A[i]);
        }

        int sum = 0; 
        for(int i=0; i<k; i++) {
            sum += *max_element(M[i].begin(), M[i].end());
        }
        cout<<sum<<endl;
    }
}