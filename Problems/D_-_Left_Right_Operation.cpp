#include <iostream>
using namespace std;

#define int long long

signed main() {
    int n, L, R;
    cin >> n >> L >> R;
    int A[n + 1];
    int pre[n + 1];
    int ans = 0; 
    pre[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> A[i];
        pre[i] = pre[i - 1] + A[i];
        ans += pre[i];
    }

    int b_min = 0;
    for(int j = 1; j <= n + 1; ++j){
        ans = min(ans, R * (n + 1 - j) + pre[j - 1] + b_min);
        if(j ^ (n + 1)){
            b_min = min(b_min, L * j - pre[j]);
        }
    }

    cout << min(ans, min(L * n, R * n)) << '\n'; 
}