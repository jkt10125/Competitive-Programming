#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for(int i=0; i<n; i++) cin >> A[i];
        for(int i=0; i<n; i++) cin >> B[i];

        int ctr = 0, ans = 0;
        if(A != B) ans++;

        for(int i=0; i<n; i++) ctr += A[i] - B[i];
        ans += abs(ctr);

        cout << ans << endl;
    }
}