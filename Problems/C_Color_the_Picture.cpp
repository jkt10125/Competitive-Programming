#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> A(k);
        for(int i=0; i<k; i++) cin >> A[i];

        if(*max_element(A.begin(), A.end()) >= n*1ll*m) {
            cout<<"Yes\n";
        }
        else {
            if(n < m) swap(n, m);

            // 2*m ka patta
            int ctr = n;
            int inc_ctr = 0;
            for(int i=0; i<k; i++) {
                if(A[i] / m < 2) continue;
                else {
                    ctr -= A[i]/m;
                    if(A[i]/m > 2) inc_ctr++;
                }
                if(ctr == -1) {
                    if(inc_ctr == 0) ctr = 1;
                }
            }
            if(ctr <= 0) cout<<"Yes\n";
            else {
                // 2*n ka patta
                ctr = m;
                inc_ctr = 0;
                for(int i=0; i<k; i++) {
                    if(A[i] / n < 2) continue;
                    else {
                        ctr -= A[i]/n;
                        if(A[i] / n > 2) inc_ctr++; 
                    }
                    if(ctr == -1) {
                        if(inc_ctr == 0) ctr = 1;
                    }
                }
                if(ctr <= 0) cout<<"Yes\n";
                else cout<<"No\n";\
            }
        }
    }
}