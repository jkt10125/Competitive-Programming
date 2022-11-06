#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) { cin >> A[i]; }

    prev_permutation(A.begin(), A.end());
    for(int i : A) cout << i << ' ';
}