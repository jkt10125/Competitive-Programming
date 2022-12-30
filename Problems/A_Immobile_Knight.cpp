/*
** Date: 29/12/2022 | Time: 13:35:19
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n == 1 || m == 1) cout << "1 1\n";
        else cout << "2 2\n";
    }
}