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

        if(n & 1) {
            cout<<"-1\n";
            continue;
        }
        int one = 0;
        for(int i=0; i<n; i++) {
            if(A[i] == 1) one++;
        }
        cout<<abs(n/2 - one)<<"\n";
    }
}