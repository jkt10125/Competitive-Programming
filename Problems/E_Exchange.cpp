/*
** Date: 28/12/2022 | Time: 13:27:41
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if(b >= a) {
            cout << (n / a) + (n % a != 0);
        }
        else {
            cout << 1;
        }
        cout << endl;
    }
}