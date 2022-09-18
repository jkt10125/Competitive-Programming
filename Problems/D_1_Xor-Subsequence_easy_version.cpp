#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];
        vector<int> dp(n, 1);

        for(int i=1; i<n; i++) {
            for(int j=max(0, i-257); j<i; j++) {
                if((A[j]^i) < (A[i]^j)) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        cout<<*max_element(dp.begin(), dp.end())<<endl;
    }
}