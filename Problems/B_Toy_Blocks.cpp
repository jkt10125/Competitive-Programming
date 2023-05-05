#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        sort(A.begin(), A.end());

        int cost = 0;
        for (int i = 2; i < n; i++) {
            cost += (A[n - 1] - A[i]);
        }
        int fc = (A[n - 1] - A[0] - A[1]);
        if (fc < 0) {
            // fc = -fc;
            std::cout << cost + fc + n - 1 << std::endl;
        }   
        else {
            std::cout << cost + fc<< std::endl;
        }
    }
}