#include <bits/stdc++.h>
using namespace std;

#define ld long double

int main() {
    int t;
    cin >> t;
    for(int ii=1; ii<=t; ii++) {
        int n, m;
        cin >> n;
        cin >> m;
        vector<ld> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        int k = n - m + 1;
        sort(A.begin(), A.end());
        ld sum = 0.0;
        // for(int i=0; i<k; i++) sum += A[i];
        if(k % 2 == 0) {
            sum = (A[k/2-1] + A[k/2]) / 2.0;
        }
        else sum = A[k/2];
        // sum = sum / k;
        for(int i=k; i<n; i++) sum += A[i];
        cout<<"Case #"<<ii<<": "<<sum<<endl;
    }
}