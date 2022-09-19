#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k; 
    vector<int> A(n);
    set<pair<int, int>> S;
    for(int i=0; i<n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        S.insert({x, i});
    }

    int ctr = 0;
    for(int i=0; i<n; i++) {
        auto it = S.lower_bound({A[i]-k, -1});
        if(it == S.end()) continue;
        if(it->first-A[i] > k) continue;
        ctr++;
        S.erase(it);
    }
    cout<<ctr;
}