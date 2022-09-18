#include <bits/stdc++.h>
using namespace std;

// Timur, miurT, Trumi, mriTu

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string a = "Timur";
        sort(a.begin(), a.end());
        sort(s.begin(), s.end());
        if(s == a) cout<<"YES\n";
        else cout<<"NO\n";
    }
}