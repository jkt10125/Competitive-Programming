#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int hsh[26] = {0}, eq[26] = {0};
        for(int i=0; i<n; i++) {
            string s;
            cin >> s;
            hsh[s[0]-'a']++;
            if(s[0] == s[1]) eq[s[0]-'a']++;
            else hsh[s[1]-'a']++;
        }
        int ans = 0;
        for(int i=0; i<26; i++) {
            ans += hsh[i] * (hsh[i] - 1) / 2;
            ans -= eq[i] * (eq[i] - 1) / 2;
        }
        cout<<ans<<endl;
    }
}