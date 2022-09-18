#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    vector<int> B = A;
    sort(B.begin(), B.end());
    vector<int> idx;
    for(int i=0; i<n; i++) {
        if(A[i] != B[i]) idx.push_back(i);
    }

    long long AND = (1ll << 55) - 1;
    for(auto it : idx) {
        AND &= A[it];
    }
    cout<<AND;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
}