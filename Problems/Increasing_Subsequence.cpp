#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<int> dp(1, A[0]);
    for (int i = 1; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), A[i]);
        if(it == dp.end()) dp.push_back(A[i]);
        else {
            int idx = it - dp.begin();
            dp[idx] = A[i];
        }
    }

    cout << dp.size();  
}