#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5 + 2;

ll input() { ll a; cin >> a; return a; }

int main() {
    ll dp[N], A[N]={0};
    ll n = input();
    for(int i=0; i<n; i++) A[input()]++;

    dp[0] = 0;
    dp[1] = A[1];
    dp[2] = max(A[1], 2*A[2]);
    dp[3] = max(2*A[2], A[1]+3*A[3]);

    for(int i=4; i<N-1; i++) {
        dp[i] = max(i*A[i]+dp[i-2], dp[i-1]);
    }
    cout<<dp[N-2];
}