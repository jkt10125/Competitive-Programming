#include <bits/stdc++.h>
using namespace std;
const int N = 1000000000;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        sort(A.begin(), A.end());
        int c=0;
        while(k--) A[c++] = N;
        sort(A.begin(), A.end());

        
    }
}