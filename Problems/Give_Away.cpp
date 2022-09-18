#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T = int>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, a, b, c) for(int i=a; i<=b; i+=c)

void print(ordered_set<int> st) {
    for(auto it : st) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m = sqrt(n);
    map<int, ordered_multiset<int>> M;
    for(int i = 0; i < n; i++) {
        M[a[i] / m].insert(a[i]);
    }
    int q;
    cin >> q;
    while(q--) {
        int f;
        cin >> f;
        if(f) {
            int idx, x;
            cin >> idx >> x;
            idx--;
            M[idx / m].erase(a[idx]);
            a[idx] = x;
            M[idx / m].insert(a[idx]);
            // print(M[idx / m]);
        }

        else {
            int l, r, c;
            cin >> l >> r >> c;
            l--; r--;
            int ans = 0;
            FOR(i, ceil(l/m), floor(r/m)-1, 1) {
                ans += M[i].size() - M[i].order_of_key(c);
            }
            FOR(i, l, ceil(l/m)*m-1, 1) {
                if(a[i] >= c) ans++;
            }
            FOR(i, (r/m)*m, r, 1) {
                if(a[i] >= c) ans++;
            }
            cout << ans << endl;
        }
    }
}