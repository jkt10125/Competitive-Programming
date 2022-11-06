#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> factor(int n) {
    vector<pair<int, int>> A;
    for(int i=2; i*i<=n; i++) {
        while(n % i == 0) {
            n = n / i;
            if(A.empty()) A.push_back({i, 1});
            else {
                if(A.back().first == i) A.back().second++;
                else A.push_back({i, 1});
            }
        }
    }
    return A;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        int ans = 1;
        // auto f = factor(A[0]);
        for(int i=1; i<n; i++) {
            if(A[i-1] % A[i]) ans = 0;
            int mr = m / A[i];
            A[i-1] = A[i-1] / A[i];
            int val = mr - mr / A[i-1];
            ans = ans * val;
        }

        cout << t << ans << endl;
    }
}