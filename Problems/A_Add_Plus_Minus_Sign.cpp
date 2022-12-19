#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        int ctr = s[0] - '0';
        for (int i = 1; i < n; i++) {
            if(ctr) {
                ans.push_back('-');
                ctr -= (s[i] - '0');
            }
            else {
                ans.push_back('+');
                ctr += (s[i] - '0');
            }
        }

        cout << ans << endl;
    }
}