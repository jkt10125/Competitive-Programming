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
        int ctr = 1;
        for(int i=0; i<n; i+=2) {
            if((A[i]-A[0])&1) ctr = 0;
        }
        for(int i=1; i<n; i+=2) {
            if((A[i]-A[1])&1) ctr = 0;
        }
        if(ctr) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}