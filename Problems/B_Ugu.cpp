#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        while(s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        int ctr = 0;
        char c = '1';
        for(char cc : s) {
            if(cc != c) {
                c = cc;
                ctr++;
            }
        }
        cout << ctr << endl;
    }
}