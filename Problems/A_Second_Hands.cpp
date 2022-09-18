#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int _t=1; _t<=t; _t++) {
        cout<<"Case #"<<_t<<": ";
        int n, k, Si;
        cin >> n >> k;
        int A[101] = {0};
        for(int i=0; i<n; i++) cin >> Si, A[Si]++;
        if(n > 2 * k) cout<<"NO";
        else {
            bool f = true;
            for(int i=0; i<101; i++) {
                if(A[i] > 2) f = false;
            }
            if(f) cout<<"YES";
            else cout<<"NO";
        }
        cout<<endl;
    } 
}