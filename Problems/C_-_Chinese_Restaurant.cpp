#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    vector<int> B(n);
    for(int i=0; i<n; i++) {
        int x = A[i] - i;
        if(x < 0) x = n + x;
        B[i] = x;
    }
    map<int, int> a;
    for(int i=0; i<n; i++) {
        a[B[i]]++;
        a[(B[i]+1+n)%n]++;
        a[(B[i]-1+n)%n]++;
    }
    int mx = 0;
    for(auto it :a) {
        if(it.first < 0) continue;
        mx = max(mx, it.second);
    }
    cout<<mx;
}