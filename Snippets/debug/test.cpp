#include "debug.hpp" 

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> A(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        A[u].push_back({v, 1});
        A[v].push_back({u, 1});
    }

    for (int i = 0; i < n; i++) {
        for (auto [j, k] : A[i + 1]) {
            debug(j);
        }
        cerr << endl;
    }

    debug(A);
}