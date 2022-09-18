#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<long long> R(n+1), B(n+1);
    R[1] = 0; B[1] = 1;
    for(int i=2; i<=n; i++) {
        R[i] = (x+1)*R[i-1] + x*y*B[i-1];
        B[i] = R[i-1] + y*B[i-1];
    }
    cout<<R[n];
}