/*
** Date: 30/12/2022 | Time: 20:39:37
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        int a = n;
        for (int i = 0; i < n; i += 2) {
            A[i] = a--;
        }
        a = 1;
        for (int i = 1; i < n; i += 2) {
            A[i] = a++;
        }

        for (int i = 0; i < n; i++) cout << A[i] << ' ';
        cout << endl;
    }
}