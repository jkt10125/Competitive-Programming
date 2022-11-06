#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A;

bool f(int k) {
    multiset<int> s;
    for(int i : A) s.insert(i);
    for(int i=1; i<=k; i++) {
        int b = k - i + 1;
        if(s.empty()) return false;
        auto a = s.upper_bound(b);
        if(a == s.begin()) return false;
        a--;
        s.erase(a);
        if(!s.empty()) s.erase(s.begin());
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        A.resize(n);
        for(int i=0; i<n; i++) cin >> A[i];

        int ans = 0;
        int l = 0, r = n;
        while(l <= r) {
            int m = (l + r) / 2;
            if(f(m)) {
                ans = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        cout << ans << endl;
    }
}