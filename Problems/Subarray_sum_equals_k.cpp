#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    multiset<int> s; s.insert(0);
    int sum = 0, ans = 0;
    for(int i=0; i<n; i++) {
        sum += A[i];
        ans += s.count(sum-k);
        s.insert(sum);
    }

    for(int i : s) cout<<i<<" ";
    cout<<"\n";
    cout<<ans<<"\n";
}