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

        string s;
        cin >> s;

        map<int, char> M;
        bool ok = true;
        for(int i=0; i<n; i++) {
            if(!M[A[i]]) M[A[i]] = s[i];
            if(M[A[i]] != s[i]) { ok = false; }
        }

        if(ok) cout << "YES\n";
        else cout<<"NO\n";
    }
}