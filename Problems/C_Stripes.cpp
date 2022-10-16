#include <bits/stdc++.h>
using namespace std;

char A[8][8];

int f(int x, int y, bool h) {
    if(h) {
        char a = A[x][0];
        for(int i=0; i<8; i++) {
            if(a != A[x][i]) return 0;
        }
        return (a == 'R') ? 2 : (a == 'B') ? 1 : 0;
    }
    else {
        char a = A[0][y];
        for(int i=0; i<8; i++) {
            if(a != A[i][y]) return 0;
        }
        return (a == 'R') ? 2 : (a == 'B') ? 1 : 0;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                cin >> A[i][j];
            }
        }
        char ans = '?';
        
        for(int i=0; i<8; i++) {
            bool ok = true;
            for(int j=0; j<8; j++) {
                if(A[i][j] != 'R') ok = false;
            }
            if(ok) {
                ans = 'R';
                break;
            }
        }
        for(int j=0; j<8; j++) {
            bool ok = true;
            for(int i=0; i<8; i++) {
                if(A[i][j] != 'B') ok = false;
            }
            if(ok) {
                ans = 'B';
                break;
            }
        }
        cout << ans << endl;
    }
}