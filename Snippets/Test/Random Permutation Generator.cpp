#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(0, INT_MAX);

/* Generates a random permutation of [0 .. n-1] */
vector<int> rand_perm(int n) {
    vector<int> A(n);
    for(int i=0; i<n; i++) A[i] = i;
    while(n) {
        int idx = uid(rng) % n;
        swap(A[idx], A[n-1]);
        n--;
    }
    return A;
}

signed main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    
    vector<int> A = rand_perm(n);
    cout << n << endl;
    for(int it : A) cout << it << ' ';
    cout << endl;
    return 0;
}