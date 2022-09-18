#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> A(2, vector<int> (n, 0));
        for(int i=0; i<n; i++) cin >> A[0][i];
        for(int i=0; i<n; i++) cin >> A[1][i];

        int max_ele = A[0][0];
        int x=0, y=0;

        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                if(A[x][y] < A[i][j]) {
                    x = i; y = j;
                }
            }
        }
    }
}