#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(0, INT_MAX);

vector<pair<int, int>> rand_graph(int n, int m) {
    vector<pair<int, int>> A(m);
    set<pair<int, int>> tmp;
    for(int i=1; i<min(n, m+1); i++) {
        int u = uid(rng) % i;
        A[i-1] = (uid(rng) & 1) ? make_pair(u, i) : make_pair(i, u);
        // A[i-1] = {u, i}; /* for DAG */
        tmp.insert({i, u});
        tmp.insert({u, i});
    }
    for(int i=n-1; i<m; i++) {
        int u = uid(rng) % n;
        int v = uid(rng) % n;
        while(tmp.find({u, v}) != tmp.end() || u == v) {
            u = uid(rng) % n;
            v = uid(rng) % n;
        }
        tmp.insert({u, v});
        tmp.insert({v, u});
        A[i] = {u, v};
        // A[i] = {min(u, v), max(u, v)}; /* for DAG */
    }
    return A;
}

vector<int> rand_mask(int n) {
    vector<int> A(n);
    for(int i=0; i<n; i++) A[i] = i;
    while(n > 1) {
        int idx = uid(rng) % n;
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
    int m = atoi(argv[2]);

    vector<pair<int, int>> A = rand_graph(n, m);
    vector<int> B = rand_mask(n); /* Mask Array */
    // vector<int> W = rand_arr(m); /* Weight array */
    cout << n << ' ' << m << endl;
    for(int i=0; i<m; i++) {
        cout << B[A[i].first] << ' ' << B[A[i].second] << endl;
    }
    return 0;
}