#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ctr = 0;
    for (char &c : s) {
        if (c == '"') ctr++;
        else if(c == ',' && !(ctr & 1)) {
            c = '.';
        }
    }
    cout << s;
}