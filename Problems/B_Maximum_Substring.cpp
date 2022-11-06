#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        char c = s[0];
        int ctr = 0;
        int z = 0, o = 0;
        int mz = 0, mo = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '0') z++;
            else o++;

            if(s[i] == c) ctr++;
            else {
                if(c == '0') mz = max(mz, ctr);
                else mo = max(mo, ctr);

                c = s[i];
                ctr = 1;
            }
        }
        if(c == '0') mz = max(mz, ctr);
        else mo = max(mo, ctr);

        cout << max({mz*mz, mo*mo, o*z})<<endl;
    }
}