/*
** Date: 27/12/2022 | Time: 11:08:36
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

double f(int n, int m) {
    double a = 1;
    for (int i = m + n; i > m; i--) {
        a *= i;
    }
    for (int i = n; i > 0; i--) {
        a /= i;
        a /= 2;
    }
    for (int i = m; i > 0; i--) {
        a /= 2;
    }
    return a;
}

int main() {
    string s, t;
    cin >> s >> t;
    int p = 0, m = 0;
    for (char c : s) {
        if (c == '+') p++;
        else m++;
    }

    int pp = 0, mm = 0;
    for (char c : t) {
        if (c == '+') pp++;
        else if (c == '-') mm++;
    }
    cout << fixed;
    cout << setprecision(12);

    if (pp > p || mm > m) {
        cout << 0.0;
    }
    else {
        cout << f(p - pp, m - mm);
    }
}