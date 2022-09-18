#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> A(n);
        for(int i=0; i<n; i++) cin >> A[i];

        int mx = -1;
        int ans = 1;
        int ctr = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'B' && mx < i) {ans = -1; break;}
            if(s[i] == 'R') {
                mx = max(mx, i+A[i]);
            }

            if(s[i] == 'B') {
                for(int j=i; j<=min(mx, n-1); j++) {
                    s[j] = 'R';
                }
                mx = i+A[i];
                ctr++;
            }
        }

        if(ans == -1) cout<<-1<<endl;
        else cout<<ctr<<endl;
    }
}