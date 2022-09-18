#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        int p1=0, p2=0;
        while(p1<s.size() && p2<t.size()) {
            if(s[p1] == t[p2]) p2++;
            p1++;
        }

        if(p2 == t.size()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}