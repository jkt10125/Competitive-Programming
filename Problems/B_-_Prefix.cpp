#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int S=0;
    while(S < (int)s.size()) {
        if(s[S] != t[S]) {
            break;
        }
        S++;
    }
    if(S != (int)s.size()) cout<<"No";
    else cout<<"Yes";
}