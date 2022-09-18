#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string A, B;
        cin >> A >> B;

        if(A == B) {
            cout<<"YES\n";
            continue;
        }

        bool f = false;
        for(int i=0; i<n; i++) if(A[i] == '1') f = true;
        if(!f) {
            cout<<"NO\n";
            continue;
        }

        string C = A, D = A;
        for(int i=0; i<n; i++) {
            if(i & 1) {
                C[i] = '0';
                D[i] = '1';
            }
            else {
                C[i] = '1';
                D[i] = '0';
            }
        }

        if(B == C || B == D) {
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }
    }
}