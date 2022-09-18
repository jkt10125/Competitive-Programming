#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int pos=0, neg=0, zero=0;
        vector<int> A;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            if(x) {
                A.push_back(x);
                (x > 0) ? pos++ : neg++;
            }
            else zero++;
        }
        if(pos > 2 || neg > 2) {
            cout<<"NO\n";
            continue;
        }
        n = A.size();
        if(n < 2) {
            cout<<"YES\n";
            continue;
        }
        if(n == 2) {
            if(A[0] + A[1] == 0) cout<<"YES\n";
            else cout<<"NO\n";
            continue;
        }
        if(n == 3) {
            if(zero != 0) cout<<"NO\n";
            else {
                long long s = A[0]+ 0ll + A[1] + A[2];
                if(s == A[0] || s == A[1] || s == A[2]) cout<<"YES\n";
                else cout<<"NO\n";
                continue;
            }
        }
        if(n == 4) {
            if(zero != 0) cout<<"NO\n";
            else {
                bool f = 1;
                for(int i=0; i<n; i++) {
                    for(int j=i+1; j<n; j++) {
                        for(int k=j+1; k<n; k++) {
                            int flag = 0;
                            for(int l=0; l<n; l++) {
                                if(A[i]+A[j]+A[k] == A[l]) flag = 1;
                            }
                            if(!flag) f = 0;
                        }
                    }
                }
                if(f) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
}