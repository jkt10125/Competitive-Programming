/*
** Date: 26/12/2022 | Time: 20:53:38
** Written By: JKT
*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<array<int, 2>> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i][0] >> A[i][1];
    }

    int a = 1, b = 1, c1 = 1, c = 1;
    for (int i = 0; i < n; i++) {
        a = a * (A[i][1] + 1) % mod;
        b = b * power(A[i][0], A[i][1] + 1) % mod * power(A[i][0] - 1, mod - 2) % mod;
        c1 = c1 * (A[i][1] + 1) % (mod - 1);
    }

    for (int i = 0; i < n; i++) {
        if (A[i][1] & 1) {
            int c2 = c1 * 
        }
        else {
            c = c * power(A[i][0], (A[i][1] / 2) * c1 % (mod - 1)) % mod;
        }
    }
}