#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool ok = true;
    map<string, int> A;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'H' || s[0] == 'D' || s[0] == 'C' || s[0] == 'S') {
            if((s[1] <= '9' && s[1] >= '2') || s[1] == 'A' || s[1] == 'T' || s[1] == 'J' || s[1] == 'Q' || s[1] == 'K') {
                A[s]++;
            }
            else ok = false;
        }
        else ok = false;
    } 

    for (auto [str, x] : A) {
        if (x != 1) ok = false;
    }

    if (ok) cout << "Yes";
    else cout << "No";
}