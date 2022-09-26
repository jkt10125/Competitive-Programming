#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    int ans = 0;
    stack<pair<int, int>> S;
    for(int i=0; i<n; i++) {
        int ctr = 0;
        while(!S.empty() && S.top().first >= A[i]) {
            ans = max(ans, S.top().first * (S.top().second + ctr));
            ctr += S.top().second;
            S.pop();
        }
        S.push({A[i], ctr + 1});
    }
    int ctr = 0;
    while(!S.empty()) {
        ans = max(ans, S.top().first * (S.top().second + ctr));
        ctr += S.top().second;
        S.pop();
    }
    cout<<ans;
}