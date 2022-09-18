#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];
        cin >> m;
        vector<int> B(m);
        for(int i=0; i<m; i++) cin >> B[i];

        int a = *max_element(A.begin(), A.end());
        int b = *max_element(B.begin(), B.end());
        // cerr<<a<<" "<<b<<"\n";
        if(a == b) cout<<"Alice\nBob\n";
        else if(a > b) cout<<"Alice\nAlice\n";
        else cout<<"Bob\nBob\n";
    }
}