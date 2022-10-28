#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    int sum = 0, ctr = 0;
    int l = 0, r = 0;
    while(r < n) {
        sum += A[r++];
        while(sum > x) {
            sum -= A[l++];
        }
        if(sum == x) ctr++;
    }

    cout << ctr;
}