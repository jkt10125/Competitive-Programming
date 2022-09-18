#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int A[3];
        cin >> A[0] >> A[1] >> A[2];
        sort(A, A+3);
        if(A[1] != A[2]) cout<<"NO\n";
        else {
            cout<<"YES\n"<<A[2]<<" ";

            if(A[0] == A[1]) cout<<A[2]<<" "<<A[2]<<endl;
            else cout<<A[0]<<" "<<A[0]<<endl;
        }
    }
}