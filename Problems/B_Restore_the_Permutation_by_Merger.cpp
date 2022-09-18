#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(2*n), hsh(n+1), ans;
        for(int i=0; i<2*n; i++) cin >> A[i];
        for(int i=0; i<2*n; i++) {
            if(hsh[A[i]]) continue;
            hsh[A[i]] = true;
            ans.push_back(A[i]);
        }

        for(int i=0; i<n; i++) cout << ans[i] << " ";
        cout<<"\n";
    }
    
}