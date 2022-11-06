#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n+1];
    for(int i=1; i<=n; i++) cin >> A[i];

    int B[2*n+2] = {0};
    int ctr = 2;
    for(int i=1; i<=n; i++) {
        B[ctr] = B[ctr+1] = B[A[i]] + 1;
        ctr += 2;
    }

    for(int i=1; i<=2*n+1; i++) {
        cout << B[i] << endl;
    }
}