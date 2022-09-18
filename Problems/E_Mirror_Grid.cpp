#include <bits/stdc++.h>
using namespace std;

int f(vector<string> &A, int i, int j) {
    int n = A.size();
    int ctr = 0;
    ctr += (A[i][j] == '1');
    ctr += (A[j][n-i-1] == '1');
    ctr += (A[n-j-1][i] == '1');
    ctr += (A[n-i-1][n-j-1] == '1');
    return min(ctr, 4-ctr);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        int ans = 0;
        if(n % 2 == 0) {
            for(int i=0; i<n/2; i++) {
                for(int j=0; j<n/2; j++) {
                    ans += f(A, i, j);
                }
            }
        }  
        else {
            for(int i=0; i<=n/2; i++) {
                for(int j=0; j<n/2; j++) {
                    ans += f(A, i, j);
                }
            }
        }

        cout<<ans<<endl;
    }
}