#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        for(int i=0; i<n; i++) cin >> A[i];

        long ans = 0;
        int ctr = 1;
        for(int i=1; i<n; i++) {
            if(A[i] > A[i-1]) ctr++;
            else {
                ans = ans + 1l * ctr * (ctr + 1) / 2;
                ctr = 1;
            }
        }
        ans += (ctr * (ctr + 1) / 2);
        cout << ans << endl;
    }
}
