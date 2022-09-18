#include <iostream>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    int A[n], B[n], C[n];
    for(int i=0; i<n; i++) cin >> A[i] >> B[i] >> C[i];

    int dp_initial[3], dp_current[3];
    dp_initial[0] = A[0]; dp_initial[1] = B[0]; dp_initial[2] = C[0];
    for(int i=1; i<n; i++) {
        dp_current[0] = A[i] + max(dp_initial[1], dp_initial[2]);
        dp_current[1] = B[i] + max(dp_initial[0], dp_initial[2]);
        dp_current[2] = C[i] + max(dp_initial[1], dp_initial[0]);
        for(int i=0; i<3; i++) dp_initial[i] = dp_current[i];
    }
    cout<<max(max(dp_initial[0], dp_initial[1]), dp_initial[2]);
}