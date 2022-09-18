#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int even=0;
        vector<int> odd;
        for(int i=0; i<n; i++) {
            int a;
            cin >> a;
            if(a % 2 == 0) even++;
            else odd.push_back(a);
        }

        sort(odd.begin(), odd.end());

        long long ans = 0;
        n = odd.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(__gcd(odd[i], 2*odd[j]) > 1) ans++;
            }
        }

        ans += even * 1ll * (even - 1) / 2;
        ans += n * 1ll * even;

        cout<<ans<<"\n";
    }
}