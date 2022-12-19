#include <bits/stdc++.h>
using namespace std;

int A[2][2];

bool c() {
    if (A[0][0] < A[0][1] && A[1][0] < A[1][1] && A[0][0] < A[1][0] && A[0][1] < A[1][1]) {
        return true;
    }
    else return false;
}

void rotate() {
    int temp = A[0][0];
    A[0][0] = A[1][0];
    A[1][0] = A[1][1];
    A[1][1] = A[0][1];
    A[0][1] = temp;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        
        cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];
        bool ok = false;
        for (int i = 0; i < 5; i++) {
            if(c()) ok = true;
            rotate();
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}