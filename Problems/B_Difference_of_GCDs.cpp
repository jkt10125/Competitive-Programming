#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> A(n+1);
        int flag = 1;
        for(int i=n; i>0; i--) {
            int a;
            if(l % i == 0) a = l;
            else a = l/i*i+i;
            if(a > r) {
                flag = 0;
                break;
            }
            A[i] = a;
        }
        if(!flag) cout<<"NO\n";
        else {
            cout<<"YES\n";
            for(int i=1; i<=n; i++) cout<<A[i]<<" ";
            cout<<endl;
        }
    }
}