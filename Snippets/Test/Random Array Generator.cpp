#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(0, INT_MAX);

vector<int> rand(int n) {
    vector<int> A(n);
    for(int i=0; i<n; i++) A[i] = i + 1;
    while(n) {
        int idx = uid(rng) % n;
        swap(A[idx], A[n-1]);
        n--;
    }
    return A;
}

signed main(int argc, char *argv[]) {
    for(int i = 1; i<argc; i++) {
        int n = atoi(argv[i]);
        vector<int> A = rand(n);
        for(auto it : A) cout << it << " ";
        cout<<endl;
    }
    return 0;
}