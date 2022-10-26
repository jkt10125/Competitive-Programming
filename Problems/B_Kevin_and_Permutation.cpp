#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int ctr = n, A[n];
        for(int i=1; i<n; i+=2) A[i] = ctr--;
        for(int i=0; i<n; i+=2) A[i] = ctr--;

        for(int i=0; i<n; i++) cout << A[i] << ' ';
        cout << endl;
    }
}