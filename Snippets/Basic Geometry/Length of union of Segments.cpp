#include <bits/stdc++.h>
using namespace std;

int lengthOfUnion (vector<array<int, 2>> &A) {
    int n = A.size();
    vector<array<int, 2>> v(n << 1);
    for (int i = 0; i < n; i++) {
        v[(i << 1)] = {A[i][0], 0};
        v[(i << 1) | 1] = {A[i][1], 1};
    }

    sort(v.begin(), v.end());
    int ans = 0, ctr = 1 - 2 * v[0][1];
    
    for (int i = 1; i < (n << 1); i++) {
        if (ctr) {
            ans += v[i][0] - v[i-1][0];
        }
        ctr += 1 - 2 * v[i][1];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<array<int, 2>> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i][0] >> A[i][1];
    }
    cout << lengthOfUnion(A);

}