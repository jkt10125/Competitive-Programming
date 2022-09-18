#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n-1; i++) {
            A[i] = i+2;
        }
        A[n-1] = 1;

        for(int i=0; i<n; i++) cout<<A[i]<<" ";
        cout<<endl;
    }
}