// TC O(nlogn)
// Dependencies ordered_set, factoial
// Returns the kth permutation of [0, ... n-1] (*counting starts from k = 0 to n-1)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5;
vector<int> fac;
// do_once() : fact(N)

void fact (int n) {
	fac.resize(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i;
	}
}

vector<int> kth_perm(int n, int k) {
    vector<int> perm(n);
    fact(n);
    ordered_set<int> S;
    for(int i=0; i<n; i++) S.insert(i);
    for(int i=0; i<n; i++) { 
        S.erase(perm[i] = *S.find_by_order(k / fac[n-i-1]));
        k = k % fac[n-i-1];
    }
    return perm;
}
