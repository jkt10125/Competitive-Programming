#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string A[2];
        cin >> A[0] >> A[1];

        map<char, int> M;
        M[A[0][0]]++;
        M[A[0][1]]++;
        M[A[1][0]]++;
        M[A[1][1]]++;

        int mx = -1;
        for(auto ti : M) mx = max(mx, ti.second);

        if(M.size() == 1) cout<<"0\n";
        else if(M.size() == 2) {
            cout<<"1\n";
        }
        else if(M.size() == 3) cout<<"2\n";
        else cout<<"3\n";
    }
}