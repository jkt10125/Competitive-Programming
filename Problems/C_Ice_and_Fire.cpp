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

        int z = 0, o = 0;
        int oblz = -1, zblo = -1;
        vector<int> ans(n - 1);
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1') {
                if (oblz == -1) {
                    ans[i] = 1;
                }
                else {
                    ans[i] = z + oblz + 1;
                }
                zblo = z;
            }
            else {
                if (zblo == -1) {
                    ans[i] = 1;
                }
                else {
                    ans[i] = o + zblo + 1;
                }
                oblz = o;
            }
            if (s[i] == '0') {
                z++;
            }
            else {
                o++;
            }
        }

        for (int i : ans) cout << i << " ";
        cout << endl;
    }
}