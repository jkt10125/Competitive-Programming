#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int flag = 1;
    while(t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        int ctr = 34;
        int f = 1;
        int cc=0;
        while(ctr--) {
            if(a == b && b == c) break;
            int A = (a & (1 << cc));
            int B = (b & (1 << cc));
            int C = (c & (1 << cc));

            if(A == B && B == C) {
                f = 0;
                break;
            }
            if(A == B) c += (1ll << cc);
            if(B == C) a += (1ll << cc);
            if(A == C) b += (1ll << cc);
            cc++;
        }
        if(a == b && b == c) f = 1;
        else f = 0; 
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}