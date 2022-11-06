#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(0, INT_MAX);

vector<int> rand_tree(int n) {
    vector<int> A(n);
    const int CHILD_CONSTRAINT = n; /* for printing special trees */
    vector<int> child(n);
    for(int i=1; i<n; i++) {
        int par = uid(rng) % i;
        while(child[par] == CHILD_CONSTRAINT) par = uid(rng) % i;
        A[i] = par;
        child[par]++;
    }
    return A;
}

vector<int> rand_mask(int n) {
    vector<int> A(n);
    for(int i=0; i<n; i++) A[i] = i;
    while(n > 1) {
        int idx = uid(rng) % (n-1) + 1; /* if root(0) is fixed */
        // int idx = uid(rng) % n; /* if root is not fixed */
        swap(A[idx], A[n-1]);
        n--;
    }
    return A;
}

vector<int> rand_arr(int n) {
    vector<int> A(n);
    for(int i=0; i<n; i++) {
        A[i] = uid(rng) % n + 1;
    }
    return A;
}

signed main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    vector<int> A = rand_tree(n);
    vector<int> B = rand_mask(n); /* Mask Array */
    // vector<int> W = rand_arr(n); /* Weight Array */

    cout << n << endl;
    for(int i=1; i<n; i++) {
        // cout << A[i] << ' ' << i << endl; /* if nodes are not masked */
        cout << B[A[i]] << ' ' << B[i] << endl; /* if nodes are masked */
    }
    return 0;
}