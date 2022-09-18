#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];
        vector<char> s(m+1, 'B');

        for(int i=0; i<n; i++) {
            if(A[i] < m+1-A[i]) {
                if(s[A[i]] == 'B') s[A[i]] = 'A';
                else s[m+1-A[i]] = 'A';
            }
            else {
                if(s[m+1-A[i]] == 'B') s[m+1-A[i]] = 'A';
                else s[A[i]] = 'A';
            }
        }

        for(int i=1; i<=m; i++) cout<<s[i];
        cout<<endl;
    }
}