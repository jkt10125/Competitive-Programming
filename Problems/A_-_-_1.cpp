#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int A[n+1];
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A[a] = i + 1;
    }

    cout << A[x];
}