#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> k >> n;
        vector<int> A(k);
        A[0] = 1;
        A[k - 1] = n;
        int ctr = 1;
        for (int i = 1; i < k - 1; i++) {
            A[i] = A[i - 1] + ctr;
            ctr++;
        }
        ctr = n - 1;
        int idx = k - 2;
        while (idx >= 0 && A[idx] > ctr) {
            A[idx] = ctr;
            ctr--;
            idx--;
        }

        for (int i = 0; i < k; i++) cout << A[i] << ' ';
        cout << endl;
    }
}