#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(0, INT_MAX);

/* Generates a random array of n elements whose range is [0 .. m-1] */
vector<int> rand(int n, int m) {
    vector<int> A(n);
    for(int i=0; i<n; i++) {
        A[i] = uid(rng) % m;
    }
    return A;
}

signed main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    vector<int> A = rand(n, m);
    for(int it : A) cout << it << ' ';
    cout << endl;
    return 0;
}