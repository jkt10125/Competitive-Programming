#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        vector<pair<int, int>> V;
        V.push_back({A[0], 1});

        long long ans = 0;
        int ctr;
        for(int i=1; i<n; i++) {
            int territory = 0;
            ctr = 0;
            while(A[i] <= V.back().first && V.size() > 0) {
                territory = V.back().second + ctr;
                ans = max(ans, V.back().first * 1ll * territory);
                cerr<<V.back().first<<" "<<territory<<"\n";
                V.pop_back();
                ctr++;
            }
            V.push_back({A[i], territory + 1});
        }

        ctr = 0;
        while(V.size() > 0) {
            int territory = V.back().second + ctr;
            ans = max(ans, V.back().first * 1ll * territory);
            cerr<<V.back().first<<" "<<territory<<"\n";
            V.pop_back();
            ctr++;
        }

        cout << ans<<"\n";
    }
}