#include <bits/stdc++.h>
using namespace std;

bool isNum(char c) {
    return c <= '9' && c >= '0';
}

bool isAlpha(char c) {
    return c <= 'Z' && c >= 'A';
}

int main() {
    string s;
    cin >> s;
    bool ok = (s.size() == 8);
    for(int i = 1; i<= 6; i++) {
        if (!isNum(s[i])) ok = false;
    }
    ok = (ok & isAlpha(s[0]) & isAlpha(s[7]));
    ok = ok & (s[1] != '0');
    if (ok) cout << "Yes";
    else cout << "No";
}