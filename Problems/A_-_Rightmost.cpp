#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int idx = -2;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'a') {
            idx = i;
        }
    }

    cout << idx + 1;
}