#include <bits/stdc++.h>
using namespace std;
vector<string> s(2);
int m;
bool f(int e) {
    bool ok = true;
    for (int i = 0; i < m - 1; i++) {
        if (s[1-e][i] == 'B') {
            s[e][i] = 'b';
            e = 1 - e;
        }
        if (s[e][i + 1] == 'B') {
            s[e][i] = 'b';
        }
        else {
            ok = false;
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        if(s[0][i] == 'b') s[0][i] = 'B';
        if(s[1][i] == 'b') s[1][i] = 'B';
    }

    if(s[e][m - 1] != 'B') ok = false;

    return ok;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        cin >> m;
        cin >> s[0] >> s[1];

        bool ok = false;
        if (s[0][0] == 'B') {
            ok = ok | f(0);
        }
        if (s[1][0] == 'B') {
            ok = ok | f(1);
        }
        if (ok) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}