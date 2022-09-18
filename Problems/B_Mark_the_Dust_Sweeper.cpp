#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) {
            cin >> A[i];
        }

        int ctr = 0;
        while(A[ctr] == 0 && ctr < n-1) ctr++;
        if(ctr == n-1) {
            cout<<"0\n";
            continue;
        }
        long long sum = 0;
        for(int i=ctr; i<n-1; i++) {
            sum += A[i];
        }

        int no0 = 0;
        for(int i=ctr; i<n-1; i++) {
            if(A[i] == 0) no0++;
        }

        cout<<sum+no0<<"\n";
    }
}