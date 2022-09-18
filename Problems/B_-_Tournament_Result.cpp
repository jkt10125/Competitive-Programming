#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    char A[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> A[i][j];
        }
    }

    int f = false;
    for(int i=0; i<n; i++) {
        if(A[i][i] != '-') f = true;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(A[i][j] == 'W' && A[j][i] != 'L') f = true;
            if(A[i][j] == 'L' && A[j][i] != 'W') f = true;
            if(A[i][j] == 'D' && A[j][i] != 'D') f = true;
            
        }
    }

    if(f) cout<<"incorrect";
    else cout<<"correct";
}