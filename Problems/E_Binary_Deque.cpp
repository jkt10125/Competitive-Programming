#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        vector<int> A;
        for(int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if(x) A.push_back(i);
        }

        s = A.size() - s;
        if(s <= 0) {
            (s == 0) ? cout<<0 : cout<<-1;
            cout<<endl; continue;
        }

        int ans = INT_MAX;
        for(int i=1; i<s; i++) {
            ans = min(ans, (A[i-1] + n - A[A.size()-s+i] + 1));
        }
        ans = min(ans, A[s-1]);
        ans = min(ans, n - A[A.size()-s]+1);

        cout<<ans<<endl;
    }
}