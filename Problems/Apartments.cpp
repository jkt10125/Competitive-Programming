#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n);
    multiset<int> B;
    for(int &i : A) cin >> i;
    for(int i=0; i<m; i++) {
        int x;
        cin >> x;
        B.insert(x);
    }

    sort(A.begin(), A.end());
    int ans = 0;
    for(int i : A) {
        auto a = B.upper_bound(i-k-1);
        if(a == B.end()) continue;
        if(*a <= i+k) {
            ans++;
            B.erase(B.find(*a));
        }
    }

    cout << ans;
}