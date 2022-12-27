/*
** Date: 26/12/2022 | Time: 21:17:58
** Written By: JKT
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;

int main() {
    int n;
    cin >> n;
    vector<int> A(N + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A[x]++;
    }
    int ans = 0, fctr = A[1];
    for (int i = 2; i < N; i++) {
        int ctr = 0;
        for (int j = i + i; j < N; j += i) {
            ctr += A[j];
        }
        fctr += A[i];
        ans += A[i] * (n - fctr - ctr);
    }

    cout << ans;
}