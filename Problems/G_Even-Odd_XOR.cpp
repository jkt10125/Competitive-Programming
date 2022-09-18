#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        if(n & 1) {
            for(int i=1; i<n; i++) {
                A[i] = i+1;
            }
            A[0] = ((n >> 1) & 1);
        }

        else {
            if((n >> 1) % 2 == 0) {
                for(int i=0; i<n; i++) A[i] = i;
            }
            else {
                A[0] = 4;
                A[1] = 1;
                A[2] = 2;
                A[3] = 12;
                A[4] = 3;
                A[5] = 8;
                for(int i=6; i<n; i++) {
                    A[i] = (1 << 29) + i;
                }
            }
        }

        for(int i=0; i<n; i++) cout<<A[i]<<" ";
        cout<<endl;
    }
}
