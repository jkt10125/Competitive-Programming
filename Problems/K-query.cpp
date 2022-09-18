#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T = int>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int BLOCK_SIZE = 450;

#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>

void print(ordered_multiset<int> A) {
    for(auto it : A) {
        cerr<<it<<" ";
    }
    cerr<<"\n";
}

int main() {
    int n, m;
    cin >> n;
    vi A(n);
    for(int i=0; i<n; i++) cin >> A[i];
    cin >> m;

    vector<vector<pair<pii, pii>>> B(n / BLOCK_SIZE + 1);
    for(int i=0; i<m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        B[l/BLOCK_SIZE].push_back({{r, l}, {k, i}});
    }

    for(auto &it : B) {
        sort(it.begin(), it.end());
    }

    ordered_multiset<int> st;

    vi ans(m);

    for(int i=0; i<B.size(); i++) {
        int l, r;
        l = r = i * BLOCK_SIZE;
        st.clear();
        for(auto &it : B[i]) {
            while(r <= it.ff.ff) {
                st.insert(A[r]);
                r++;
            }
            while(l < it.ff.ss) {
                st.erase((A[l]));
                l++;
            }
            while(l > it.ff.ss) {
                l--;
                st.insert(A[l]);
            }

            ans[it.ss.ss] = st.size() - st.order_of_key(it.ss.ff + 1);
            // cerr<<st.size()<<"\n";
            print(st);
        }
    }

    for(auto &it : ans) cout << it << endl;
}