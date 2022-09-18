#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s, t;
        cin >> s >> t;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        string ans;

        int c1=0, c2=0;
        int ctr1=0, ctr2=0;
        while(c1<n && c2<m) {
            if(ctr1 == k) {
                ans.push_back(t[c2++]);
                ctr2++;
                ctr1 = 0;
            }
            else if(ctr2 == k) {
                ans.push_back(s[c1++]);
                ctr1++;
                ctr2 = 0;
            }
            else if(s[c1] < t[c2]) {
                ans.push_back(s[c1++]);
                ctr1++;
                ctr2 = 0;
            }
            else {
                ans.push_back(t[c2++]);
                ctr2++;
                ctr1 = 0;
            }
        }

        cout<<ans<<endl;
    }
}