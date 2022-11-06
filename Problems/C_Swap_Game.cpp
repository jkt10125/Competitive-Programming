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

        if(A[0] <= *min_element(A.begin(), A.end())) {
            cout << "Bob\n";
        }
        else cout << "Alice\n";
    }
}