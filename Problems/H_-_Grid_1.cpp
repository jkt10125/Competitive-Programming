#include <iostream>
using namespace std;

#define ll long long
const ll mod = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    char A[h+1][w+1];
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            cin >> A[i][j];
        }
    }

    ll dp[h+1][w+1];
    for(int i=0; i<=h; i++) dp[i][0] = 0;
    for(int i=0; i<=w; i++) dp[0][i] = 0;
    dp[1][1] = 1;
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            if(i == j && i == 1) continue;
            if(A[i][j] == '#') dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    cout<<dp[h][w];
}