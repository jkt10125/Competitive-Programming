#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        int c1=0, c2=0;
        for(char c: a) c1 += (c-'0');
        for(char c: b) c2 += (c-'0');
        if(abs(c1-c2) & 1) cout<<-1<<endl;
        else {
            x = min(x, 2*y);
            int ans = 0;
            for(int i=0; i<n; i++) {
                if(a[i] != b[i]) {
                    int ctr = 0;
                    for(int j=i+1; j<n; j++) {
                        ctr += (a[j] != b[j]);
                    }
                    if(ctr == 1) {
                        if(a[i+1] != b[i+1]) ans += x;
                        else ans += y;
                        break;
                    }
                    else {
                        ctr = 0;
                        for(int j=i+1; j<n; j++) {
                            if(a[j] != b[j]) {
                                if(ctr) {
                                    a[j] = b[j];
                                    ans += y;
                                    break;
                                }
                                else ctr++;
                            }
                        }
                    }
                    a[i] = b[i];
                }
            }
            cout<<ans<<endl;
        }
    }
}