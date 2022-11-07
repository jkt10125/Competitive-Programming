#include <bits/stdc++.h>
using namespace std;

int N = 100001;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<int> dp(N);
    dp[0] = 1;
    for (int it : A) {
        for (int i = 0; i < N; i++) {
            if (dp[i] == 1) {
                if (dp[i + it] == 0) {
                    dp[i + it] = 2;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if(dp[i]) dp[i] = 1;
        }
    }
    A.clear();
    for (int i = 1; i < N; i++) {
        if(dp[i]) A.push_back(i);
    }

    cout << A.size() << endl;
    for (int it : A) cout << it << ' ';u
}