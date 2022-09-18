#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        sort(A.begin(), A.end());
        int mx = A.back() / k;
        int mn = A.front();

        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++) {
            v[i] = {A[i]/k, A[i]};
        }
        
    }
}