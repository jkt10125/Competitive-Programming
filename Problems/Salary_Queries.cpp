#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T = int>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int n, q;
    cin >> n >> q;
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    ordered_set<pair<int, int>> OM;
    for(int i=0; i<n; i++) OM.insert({A[i], i});
    while(q--) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        if(a == '!') {
            OM.erase({A[--b], b});
            OM.insert({c, b});
            A[b] = c;
        }
        else {
            cout << OM.order_of_key({c+1, -1}) - OM.order_of_key({b, -1}) << "\n";
        }
    }
    // for(auto it : OM) cerr << it<< " ";
}