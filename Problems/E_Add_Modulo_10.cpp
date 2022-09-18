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

        sort(A.begin(), A.end());

        int f = false;
        for(int i=0; i<n; i++) {
            if(A[i] % 10 == 5 || A[i] % 10 == 0) {
                f = true;
                break;
            }
        }

        if(f) {
            for(int i=0; i<n; i++) {
                if(A[i] % 10 == 5) {
                    A[i] += 5;
                }
            }
            if(A == vector<int> (n, A[0])) {
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
        else {
            for(int i=0; i<n; i++) {
                int a = A[i] % 10;
                if(a == 1 || a == 3 || a == 7 || a == 9) {
                    A[i] += A[i] % 10;
                }
            }
            for(int i=0; i<n; i++) {
                int a = A[i] % 10;
                if(a == 6) A[i] += 6;
                if(a == 2) ;
                if(a == 4) A[i] += 18;
                if(a == 8) A[i] += 14;
            }

            sort(A.begin(), A.end());
            f = true;
            for(int i=n-1; i>0; i--) {
                if((A[i] - A[0]) % 20) {
                    f = false;
                    break;
                }
            }

            if(f) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}