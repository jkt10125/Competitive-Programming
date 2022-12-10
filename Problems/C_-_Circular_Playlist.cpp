#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, t, sum = 0;
    cin >> n >> t;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    t = t % sum;
    int song = 1;
    for (int i = 0; i < n; i++) {
        if (t >= A[i]) {
            song++;
            t -= A[i];
        }
        else break;
    }

    cout << song << ' ' << t;
}