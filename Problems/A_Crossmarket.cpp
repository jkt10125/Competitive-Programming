#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int ans = n + m - 2;
        ans += min(n, m);
        if(n == 1 && m == 1) ans = 0;
        cout<<ans<<endl;
    }
}