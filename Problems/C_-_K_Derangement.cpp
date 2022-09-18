#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n+1);
    if(k > n/2) {
        cout<<"-1";
        return 0;
    }

    for(int i=1; i<=n-k; i++) A[i] = i + k;
    for(int i=n-k+1; i<=n; i++) A[i] = i - n + k;
    for(int i=1; i<=n; i++) cout<<A[i]<<" ";
}