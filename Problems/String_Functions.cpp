/*
** Date: 29/12/2022 | Time: 02:51:05
** Written By: JKT
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction (string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0) {
            if (s[i] == s[j]) break;
            j = pi[j - 1];
        }
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> zFunction (string &s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min (r - i + 1, z[i - l]);
        }
        while (i + z[i] < n) {
            if (s[z[i]] != s[i + z[i]]) break;
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;

    for (int i : zFunction(s)) cout << i << ' ';
    cout << endl;
    for (int i : prefixFunction(s)) cout << i << ' ';
    cout << endl;
}