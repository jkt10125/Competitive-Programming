#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        for(int i=0; i<n; i++) {
            cin >> A[i];
        }
        map<int, int> M;
        for(int i=0; i<n; i++) M[A[i]]++;

        int ctr = 0;
        for(auto it : M) {
            if(it.second > 1) ctr++;
        }

        if(ctr == 0) {
            cout<<"0\n";
            continue;
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            ans++;
            M[A[i]]--;
            if(M[A[i]] == 1) ctr--;
            if(ctr == 0) break;
        }

        cout<<ans<<endl;

    }
}