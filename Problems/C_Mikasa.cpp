#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        int i = 30, ans = 0;
        while(i >= 0) {
            if(m & (1 << i)) {
                if(n & (1 << i)) ;
                else ans += (1 << i);
            }
            else if(n & (1 << i)) break;
            i--;
        }
        if(i == -1) {
            i = 0;
            while(i < 31) {
                if(((ans | n) & (1 << i)) == 0) {ans |= (1 << i); break;}
                else if(ans & (1 << i)) ans -= (1 << i);
                i++;
            }
        }
        cout<<ans<<endl;

    }
}