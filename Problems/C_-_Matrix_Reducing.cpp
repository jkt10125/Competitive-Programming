#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int> (W, 0));
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> A[i][j];
        }
    }

    int h, w;
    cin >> h >> w;
    vector<vector<int>> B(h, vector<int> (w, 0));
    for(int i=1; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> B[i][j];
        }
    }

    vector<bool> i_row(H, true), i_coloumn(W, true);
    int c_row = 0;
    for(int i=0; i<H; i++) {
        int p1=0, p2=0;
        while(p1 < W && p2 < w) {
            if(B[curr_row])
        }
    }
}