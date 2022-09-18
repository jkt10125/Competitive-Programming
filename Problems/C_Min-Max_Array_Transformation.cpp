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

        vector<int> mn(n), mx(n);
        for(int i=0; i<n; i++) {
            mn[i] = *lower_bound(B.begin(), B.end(), A[i]) - A[i];
        }

        vector<int> com(n);
        for(int i=0; i<n; i++) {
            com[i] = --lower_bound(B.begin(), B.end(), A[i]) - B.begin() + 1;
        }

        int l = 0;
        for(int i=0; i<n; i++) {
            if(com[i] >= i) {
                for(int j=l; j<i; j++) {
                    mx[j] = B[i-1] - A[j];
                }
                l = i;
            }
        }
        for(int i=l; i<n; i++) {
            mx[i] = B[n-1] - A[i];
        }

        for(int i=0; i<n; i++) cout<<mn[i]<<" ";
        cout<<endl;
        for(int i=0; i<n; i++) cout<<mx[i]<<" ";
        cout<<endl;

        // for(int i=0; i<n; i++) cerr<<com[i]<<" ";
        // cerr<<endl;
    }
}