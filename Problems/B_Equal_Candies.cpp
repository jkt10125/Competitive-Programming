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
        cout<<accumulate(A.begin(), A.end(), 0) - *min_element(A.begin(), A.end()) *n <<endl;
    }
}