#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> A(n+1);
        for(int i=1; i<=n; i++) cin >> A[i];
        if(n % 2 == 0) {
            vector<long long> cost(n+2, 0);
            for(int i=2; i<n; i++) {
                cost[i] = max((max(A[i-1], A[i+1]) - A[i] + 1), 0ll);
            }
            vector<long long> p1(n+5), p2(n+5), s1(n+5), s2(n+5);
            for(int i=2; i<n; i++) {
                if(i & 1) p1[i] = p1[i-2] + cost[i];
                else p2[i] = p2[i-2] + cost[i];
            }
            for(int i=n-1; i>1; i--) {
                if(i & 1) s1[i] = s1[i+2] + cost[i];
                else s2[i] = s2[i+2] + cost[i];
            }

            long long ans = 1e15;
            for(int i=2; i<n; i++) {
                if(i == n-3) {
                    if(i & 1) ans = min(ans, p1[i] + s1[i+2]);
                    else ans = min(ans, p2[i] + s2[i+2]);
                    continue;
                }
                if(i >= n-2) {
                    if(i & 1) ans = min(ans, p1[i]);
                    else ans = min(ans, p2[i]);
                    continue;
                }
                if(i & 1) {
                    ans = min(ans, p1[i] + min(s1[i+2], s2[i+3]));
                }
                else ans = min(ans, p2[i] + min(s2[i+2], s1[i+3]));
            }
            cout<<ans<<"\n";
        }
        else {
            long long ctr = 0;
            for(int i=2; i<n; i+=2) {
                ctr += max((max(A[i-1], A[i+1]) - A[i] + 1), 0ll);
            }
            cout<<ctr<<endl;
        }
    }
}