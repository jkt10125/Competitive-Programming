#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> A;

int count(int x, int y) {
    int ctr = 0;
    for(int i=max(0, x-1); i<=min(n-1, x+1); i++) {
        for(int j=max(0, y-1); j<=min(m-1, y+1); j++) {
            ctr += (A[i][j] == '*');
        }
    }
    return ctr;
}

bool check(int x, int y) {
    if(count(x, y) != 3) return false;
    
    if(x < n-1 && y < m-1) {
        if(A[x+1][y+1] == '*') {
            A[x][y] = A[x+1][y+1] = '.';
            if(A[x][y+1] == '*' || A[x+1][y] == '*') {
                A[x][y+1] = A[x+1][y] = '.';
                return true;
            }
            else return true;
        }
    }
    if(x > 0 && y < m-1) {
        if(A[x-1][y+1] == '*') {
            A[x][y] = A[x-1][y+1] = '.';
            if(A[x-1][y] == '*' || A[x][y+1] == '*') {
                A[x-1][y] = A[x][y+1] = '.';
                return true;
            }
            else return true;
        }
    }

    return true;
} 

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        A.resize(n);
        for(int i=0; i<n; i++) cin >> A[i];

        bool a = true;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(A[i][j] == '*') {
                    if(count(i, j) != 3) a = false;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(A[i][j] == '*') {
                    check(i, j);
                }
            }
        }
        // a = true;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(A[i][j] == '*') {
                    a = false;
                    break;
                }
            }
        }

        if(a) cout<<"YES\n";
        else cout<<"NO\n";
    } 
}