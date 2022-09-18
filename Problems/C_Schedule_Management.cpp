#include <bits/stdc++.h>
using namespace std;

vector<int> A;
int n, m;

bool f(int k) {
    long long ctr1 = 0, ctr2 = 0;
    for(int i=1; i<=n; i++) {
        if(A[i] >= k) {
            ctr1 += 2 * 1ll * (A[i] - k);
        }
        else {
            ctr2 += (k - A[i]) / 2 * 1ll * 2;
        }
    }
    return (ctr2 >= ctr1);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        A.assign(n+1, 0);
        for(int i=0; i<m; i++) {
            int tmp;
            cin >> tmp;
            A[tmp]++;
        }

        int l=1, r=m;
        int ans = -1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(f(m)) {
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }

        cout<<ans<<"\n";
    }
}