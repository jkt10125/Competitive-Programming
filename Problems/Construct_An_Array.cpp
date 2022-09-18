#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ctr = 1;
        ll a[n];
        for(int i=0; i<n-2; i+=3) {
            a[i] = ctr * (ctr+1);
            a[i+1] = (ctr+1) * (ctr+2);
            a[i+2] = (ctr) * (ctr+2);
            ctr+=3;
        }
        for(int i=0; i<n; i++) cout<<a[i]<<" ";
        cout<<"\n";
    }
}