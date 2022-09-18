#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
    string s;
    cin >> s;

    string t = s;
    reverse(t.begin(), t.end());
    s = max(s, t);
    long long ans = 1;
    for(char it : s) {
        ans = ans * (26-it+'A');
        ans %= mod;
    }
    // cout << s;
    ans--;
    cout<<ans;
}