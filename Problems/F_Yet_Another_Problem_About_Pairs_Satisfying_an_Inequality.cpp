#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ordered_set<int> A;
        long long ans = 0;
        for(int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if(x >= i) continue;
            ans += A.order_of_key(x);
            A.insert(i);
        }

        cout<<ans<<"\n";
    }
}