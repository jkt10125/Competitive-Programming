#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    int n, x;
    cin >> n >> x;
    int A[n], B[n];
    for(int i=0; i<n; i++) cin >> A[i] >> B[i];

    ll ans = 2000000000000000000;
    ll sum = 0;
    for(int i=0; i<min(n,x); i++) {
        ans = min(ans, sum + A[i] + B[i] * 1ll * (x-i));
        sum += A[i] + B[i];
    }
    cout<<ans;
}