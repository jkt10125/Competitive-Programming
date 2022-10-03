#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n, 1);
    int ctr = 0, pos = 0;
    while(ctr < n) {
        while(A[pos] == 0) pos = (pos + 1) % n;
        pos = (pos + 1) % n;
        while(A[pos] == 0) pos = (pos + 1) % n;
        cout<<pos+1<<" ";
        A[pos] = 0;
        ctr++;
    }
}