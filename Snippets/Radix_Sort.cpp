#include <bits/stdc++.h>
using namespace std;
#define int long long
const int SIZE = 1000;

void count_sort(vector<int> &A, int p[]) {
    int n = A.size(), hsh[SIZE] = {0};
    for(int i=0; i<n; i++) hsh[p[i]]++;
    for(int i=1; i<SIZE; i++) hsh[i] += hsh[i-1];
    for(int i=SIZE-1; i>0; i--) hsh[i] = hsh[i-1];
    hsh[0] = 0;
    vector<int> B(n);
    for(int i=0; i<n; i++) {
        B[hsh[p[i]]++] = A[i];
    }
    A = B;
}

void radix_sort(vector<int> &A) {
    const int BLOCKS = 4;
    int n = A.size();
    int p[n];
    for(int i=0; i<BLOCKS; i++) {
        for(int j=0; j<n; j++) p[j] = (i) ? A[j] / (i * SIZE) % SIZE : A[j] % SIZE;
        count_sort(A, p); 
    }
}

signed main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];

    radix_sort(A);
    for(int i=0; i<n; i++) cout<<A[i]<<" ";
    return 0;
}