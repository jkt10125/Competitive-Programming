#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> A(n);
        for(int i=0; i<n; i++) {
            cin >> A[i].first;
            A[i].second = i;
        }

        ordered_set<pair<int, int>> S;
        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans += S.order_of_key({-A[i].first+1, -1});
            S.insert({-A[i].first, i});
        }

        cout<<ans<<endl;
    }
}