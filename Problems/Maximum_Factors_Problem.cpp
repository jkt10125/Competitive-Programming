#include <bits/stdc++.h>
using namespace std;

map<int, int> factors(int n) {
    map<int, int> M;
    for(int i=2; i*i<=n; i++) {
        while(n % i == 0) {
            n = n / i;
            M[i]++;
        }
    }
    if(n != 1) M[n]++;
    return M;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> M = factors(n);
        int ans, mn = INT_MAX;
        for(auto it : M) {
            if(it.second < mn) {
                mn = it.second;
                ans = it.first;
            }
        }

        cout<<ans<<endl;
    }
}