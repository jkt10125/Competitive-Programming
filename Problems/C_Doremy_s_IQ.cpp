#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, iq;
        cin >> n >> iq;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            if(A[i] <= iq) ans[i]++;
        }

        int iiq = 0;
        for(int i=n-1; i>=0; i--) {
            if(iiq == iq) break;
            if(A[i] > iiq) iiq++;
            ans[i] = 1;
        }

        for(int i=0; i<n; i++) {
            cout<<ans[i];
        }
        cout<<endl;
    }
}