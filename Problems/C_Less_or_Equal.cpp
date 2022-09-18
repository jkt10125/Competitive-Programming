#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    if(n == 1) {
        if(k == 1) cout<<"1000000000";
        else {
            if(A[0] == 1) cout<<"-1";
            else cout<<"1";
        }
        return 0;
    }
    sort(A.begin(), A.end());
    if(k == 0) {
        if(A[0] == 1) cout<<"-1";
        else cout << "1";
        return 0;
    }
    ll a = A[k-1], b = A[k];
    if(a == b) cout<<"-1";
    else cout<<a;
}