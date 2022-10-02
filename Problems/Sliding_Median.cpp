#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int n, k;
    cin >> n >> k;
    ordered_set<pair<int, int>> S;
    
    int A[n];
    for(int i=0; i<n; i++) cin >> A[i];

    for(int i=0; i<k; i++) {
        S.insert({A[i], i});
    }
    cout<<S.find_by_order((k-1)/2)->first<<" ";
    for(int i=k; i<n; i++) {
        S.erase({A[i-k], i-k});
        S.insert({A[i], i});
        cout<<S.find_by_order((k-1)/2)->first<<" ";
    }
}