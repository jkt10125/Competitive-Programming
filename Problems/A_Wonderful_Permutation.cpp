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

        int ctr = 0;
        for(int i=0; i<k; i++) {
            if(A[i] > k) ctr++;
        }

        cout<<ctr<<endl;
    }
}