#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<string> A;
vector<pair<int, int>> M;

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    A[x][y] = 'X';
    Q.push({x, y});
    while(!Q.empty()) {
        pair<int, int> a = Q.front();
        x = a.first, y = a.second;
        M.push_back(a);
        Q.pop();
        if(x > 0) if(A[x-1][y] == '.') Q.push({x-1, y}), A[x-1][y] = 'X';
        if(y > 0) if(A[x][y-1] == '.') Q.push({x, y-1}), A[x][y-1] = 'X';
        if(x < n-1) if(A[x+1][y] == '.') Q.push({x+1, y}), A[x+1][y] = 'X';
        if(y < m-1) if(A[x][y+1] == '.') Q.push({x, y+1}), A[x][y+1] = 'X';
    }   
}

int main() {
    cin >> n >> m >> k;
    A.resize(n);
    for(int i=0; i<n; i++) cin >> A[i];
    vector<string> B = A;
    bool s = true;
    for(int i=0; i<n; i++) {
        if(!s) break;
        for(int j=0; j<m; j++) {
            if(!s) break;
            if(A[i][j] == '.') { 
                bfs(i, j); 
                s = false; 
            }
        }
    }

    // for(auto it : M) {
    //     cerr<<it.first<<" : "<<it.second<<endl;
    // }
    
    while(k--) {
        pair<int, int> a = M.back();
        B[a.first][a.second] = 'X';
        M.pop_back();
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<B[i][j];
        }
        cout<<endl;
    }
}