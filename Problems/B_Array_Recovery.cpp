#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int d[n];
        for(int i=0; i<n; i++) cin >> d[i];

        int A[n] = {d[0]};
        int sum = d[0];
        for(int i=1; i<n; i++) {
            if(d[i] == 0) {
                A[i] = A[i-1];
                continue;
            }
            if(d[i] <= sum) A[0] = -1;
            A[i] = A[i-1] + d[i];
            sum += d[i];
        }

        if(A[0] == -1) cout<<-1<<endl;
        else {
            for(int i=0; i<n; i++) cout<<A[i]<<" ";
            cout<<endl;
        }
    }
}