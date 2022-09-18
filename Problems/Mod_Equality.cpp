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
        vector<int> B(n);
        for(int i=0; i<n; i++) {
            B[i] = (A[i] == 0) ? A[i] : (A[i]/2 + A[i]%2 - 1);
        }

        cout << n - count(A.begin(), A.end(), *min_element(B.begin(), B.end())) << "\n";
    }
}