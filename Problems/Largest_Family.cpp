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

        sort(A.begin(), A.end());
        int i, sum = 0, ctr = 0;
        for(i=0; i<n; i++) {
            sum += A[i];
            if(sum >= n) break;
        }
        cout<<i<<endl;
    }
}