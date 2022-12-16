#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    int ctr = 0;
    if (n & 1) {
        while ((n & 1) && n) {
            ctr++;
            n >>= 1;
        }
    }
    else {
        while (!(n & 1) && n) {
            ctr++;
            n >>= 1;
        }
    }
    return ctr;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        int a = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            a = min(a, f(A[i]));
        }

        if (accumulate(A.begin(), A.end(), 0) & 1) {
            cout << a << endl;
        }
        else cout << 0 << endl;
    }
}