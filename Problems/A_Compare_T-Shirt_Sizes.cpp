#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        if(s.back() != t.back()) {
            if(s.back() == 'S' || t.back() == 'L') cout << '<';
            else cout << '>';
        }
        else if(s.back() == 'S') {
            if(s.size() > t.size()) cout << '<';
            else if(s.size() < t.size()) cout << '>';
            else cout << '=';
        }
        else {
            if(s.size() < t.size()) cout << '<';
            else if(s.size() > t.size()) cout << '>';
            else cout << '=';
        }
        cout << endl;
    }
}