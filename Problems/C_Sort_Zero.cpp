#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        map<int, int> M;
        for(int i=0; i<n; i++) cin >> A[i], M[A[i]] = i;

        int ctr = -1;
        for(int i=n-2; i>=0; i--) {
            if(A[i] > A[i+1]) {
                for(int j=i; j>=0; j--) ctr = max(ctr, M[A[j]]);
                break;
            }
        }

        M.clear();
        for(int i=ctr; i>=0; i--) M[A[i]]++;

        cout<<M.size()<<endl;
    }
}