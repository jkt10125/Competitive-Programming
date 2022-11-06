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
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        vector<int> tmp;
        int ans = 0, ctr = 0;

        for(; ctr < n; ctr++) {
            if(s[ctr] == '0') break;
            ans += A[ctr];
        }

        for(int i=ctr; i<n; i++) {
            if(s[i] == '0') {
                tmp.push_back(A[i]);
                int j = i+1;
                for(; j<n; j++) {
                    if(s[j] == '0') break;
                    tmp.push_back(A[j]);
                }
                ans += accumulate(tmp.begin(), tmp.end(), 0);
                ans -= *min_element(tmp.begin(), tmp.end());
                i = j-1;
                tmp.clear();
            }
        }

        cout << ans << endl;
    }
}