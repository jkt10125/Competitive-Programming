/*
** Date: 27/12/2022 | Time: 18:32:41
** Written By: JKT
*/

#include <bits/stdc++.h>
using namespace std;

bool t1(char c) {
    if (c == '1' || c == '2') return true;
    return false;
}

bool t2(char c) {
    if (t1(c)) return false;
    else return true;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        bool ok = true;
        int x = 0, y = 0;
        while (x < n) {
            if (!y) {
                if (t1(s[x])) x++;
                else y++;
            }
            else {
                if (t1(s[x])) x++;
                else y--;
            }
        }
    }
}