#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> g(16, vector<int> (16, 0));
    for(int i=1; i<=15; i++) {
        g[i][1] = 1;
        g[i][15] = 1;
    }
    for(int j=1; j<=15; j++) {
        g[1][j] = 1;
        g[15][j] = 1;
    }

    for(int i=3; i<=13; i++) {
        g[i][3] = 1;
        g[i][13] = 1;
    }
    for(int j=3; j<=13; j++) {
        g[3][j] = 1;
        g[13][j] = 1;
    }

    for(int i=5; i<=11; i++) {
        g[i][5] = 1;
        g[i][11] = 1;
    }
    for(int j=5; j<=11; j++) {
        g[5][j] = 1;
        g[11][j] = 1;
    }

    for(int i=7; i<=9; i++) {
        g[i][7] = 1;
        g[i][9] = 1;
    }
    for(int j=7; j<=9; j++) {
        g[7][j] = 1;
        g[9][j] = 1;
    }

    int r, c;
    cin >> r >> c;
    if(g[r][c]) cout<<"black";
    else cout<<"white";
}