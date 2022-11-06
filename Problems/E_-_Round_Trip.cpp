#include <bits/stdc++.h>
using namespace std;

bool ok = false;
vector<string> A;
char c;
int n, m;

bool d(int x, int y) {
    if(A[x][y] == c) return false;
    return (A[x][y] == '1') || (A[x][y] == '2') || (A[x][y] == '3') || (A[x][y] == '4');
}

void dfs(int x, int y) {
    if(ok) return;
    A[x][y] = c;

    if(y < m-1) {
        if(d(x, y+1)) ok = true;
        if(A[x][y+1] == '.') dfs(x, y+1);
    }
    if(y > 0) {
        if(d(x, y-1)) ok = true;
        if(A[x][y-1] == '.') dfs(x, y-1);
    }
    if(x < n-1) {
        if(d(x+1, y)) ok = true;
        if(A[x+1][y] == '.') dfs(x+1, y);
    }
    if(x > 0) {
        if(d(x-1, y)) ok = true;
        if(A[x-1][y] == '.') dfs(x-1, y);
    }

}

int main() {
    cin >> n >> m;
    A.resize(n);
    for(int i=0; i<n; i++) cin >> A[i];
    int x, y; 
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(A[i][j] == 'S') {
                x = i;
                y = j;
                break;
            }
        }
    }

    c = '1';
    if(x > 0) dfs(x-1, y);
    
    c = '2';
    if(x < n-1) dfs(x+1, y);
    
    c = '3';
    if(y > 0) dfs(x, y-1);
    
    c = '4';
    if(y < m-1) dfs(x, y+1);

    if(ok) cout << "Yes";
    else cout << "No";
}   