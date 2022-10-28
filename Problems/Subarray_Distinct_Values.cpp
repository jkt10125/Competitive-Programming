#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(int &i : A) cin >> i;

    map<int, int> s;
    int l=0, r=0, ans = 0;
    while(r < n) {
        s[A[r]]++;
        if(s.size() > k) { s.erase(A[r]); break; }
        r++;
    }

    ans = r * (r + 1) / 2;

    while(r < n) {
        s[A[r]]++;
        while(s.size() > k) {
            s[A[l]]--;
            if(!s[A[l]]) s.erase(A[l]);
            l++;
        }
        r++;
        ans += r - l;
    }

    cout << ans;
}