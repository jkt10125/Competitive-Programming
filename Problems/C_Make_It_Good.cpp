#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        A.resize(n);
        for(int i=0; i<n; i++) cin >> A[i];
        int ctr = 0;
        for(int i=0; i<n-1; i++) {
            if(A[i] < A[i+1]) ctr = i+1;
        }

        while(ctr > 0) {
            if(A[ctr-1] > A[ctr]) break;
            ctr--;
        }

        cout<<ctr<<endl;
    }
}