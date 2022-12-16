#include <bits/stdc++.h>
using namespace std;

// O(n * m)
// NOTE: Below sort function works only when the numbers are from [0, n - 1]
template <typename T, size_t m>
void countSort (vector<array<T, m>> &A) {
    int n = A.size();
    for (int j = m - 1; j >= 0; j--) {
        vector<int> H(n);
        for (int i = 0; i < n; i++) {
            H[A[i][j]]++;
        }
        for (int i = 1; i < n; i++) {
            H[i] += H[i - 1];
        }
        H.pop_back();
        H.emplace (H.begin(), 0);
        vector<array<T, m>> B(n);
        for (int i = 0; i < n; i++) {
            B[H[A[i][j]]++] = A[i];
        }
        A.swap(B);
    } 
}