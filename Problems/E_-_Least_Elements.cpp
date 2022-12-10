#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    
    ordered_set<pair<int, int>> s;
    for(int i=0; i<m; i++) s.insert({A[i], i});

    int sum = 0;
    int kk = k;
    for(auto i : s) {
        if (kk) sum += i.first;
        else break;
        kk--;
    }

    cout << sum << ' ';
    for(int i=m; i<n; i++) {
        int r = s.order_of_key({A[i-m] + 1, i-m-1});
        r--;
        if (r >= k) {
            if(k != m) {
                r = s.find_by_order(k-1)->first;
                if (A[i] <= r) {
                    sum -= r;
                    sum += A[i];
                } 
                s.erase(s.find({A[i-m], i-m})); 
                s.insert({A[i], i});
            }
            else {
                sum += A[i];
                sum -= A[i-m];
            }
        }
        else {
            if (k != m) {
                r = s.find_by_order(k)->first;
                s.erase(s.find({A[i-m], i-m}));
                sum -= A[i-m];
                sum += min(r, A[i]);
                s.insert({A[i], i});
            }
            else {
                sum += A[i];
                sum -= A[i-m];
            }
        }
        cout << sum << ' ';
    }
}