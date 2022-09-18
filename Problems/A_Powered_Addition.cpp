#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        for(int i=0; i<n; i++) {
            cin >> A[i];
        }

        int max_element = A[0], ans = -1;
        for(int i=1; i<n; i++) {
            if(A[i] < max_element) {
                ans = max(ans, (int)log2(max_element - A[i]) + 1);
            }
            else max_element = A[i];
        }

        cout<<max(ans, 0)<<endl;
    }
}