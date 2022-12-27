/*
** Date: 26/12/2022 | Time: 23:04:22
** Written By: JKT
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    size_t idx;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        A[i] = stoi(s, &idx, 2);
    }

    int hmm = k;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            hmm = min(hmm, __builtin_popcount(A[i] ^ A[j]));
        }
    }

    cout << hmm;
}