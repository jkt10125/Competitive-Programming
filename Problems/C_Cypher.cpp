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
        // for(int i=0; i<n; i++) cerr<<A[i]<<" ";
        // cerr<<endl;
        for(int i=0; i<n; i++) {
            int m;
            string s;
            cin >> m >> s;
            for(int j=0; j<m; j++) {
                if(s[j] == 'D') A[i]++;
                else A[i]--;
            }
        }

        for(int i=0; i<n; i++) {
            cout<<(A[i] + 1000) % 10<<" ";
        }

        cout<<endl;
    }
}