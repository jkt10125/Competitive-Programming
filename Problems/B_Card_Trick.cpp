#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];
        cin >> m;
        vector<int> B(m);
        for(int i=0; i<m; i++) cin >> B[i];

        long long sum = 0;
        for(int i=0; i<m; i++) sum += (long long)B[i];

        sum %= n;
        cout<<A[sum]<<"\n";
    }
}