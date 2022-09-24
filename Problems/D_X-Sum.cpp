#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> A(202, vector<int> (202));

int f(int x, int y) {
    int sum = A[x][y];
    for(int i=1; i<201; i++) {
        int a = x+i, b = y+i;
        if(a >= n || b >= m) break;
        sum += A[a][b];
    }
    for(int i=1; i<201; i++) {
        int a = x-i, b = y-i;
        if(a < 0 || b < 0) break;
        sum += A[a][b];
    }
    for(int i=1; i<201; i++) {
        int a = x+i, b = y-i;
        if(a >= n || b < 0) break;
        sum += A[a][b];
    }
    for(int i=1; i<201; i++) {
        int a = x-i, b = y+i;
        if(a < 0 || b >= m) break;
        sum += A[a][b];
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> A[i][j];
            }
        }

        int mx = -1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                mx = max(mx, f(i, j));
            }
        }

        cout<<mx<<endl;
    }
}