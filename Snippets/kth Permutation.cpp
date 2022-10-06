// TC O(nlogn)
// Dependencies ordered_set, factoial
// Returns the kth permutation of [0, ... n-1] (*counting starts from k = 0 to n-1)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> factorial(int n, int mod=0) {
	vector<int> fact(n+1, 1);
	for(int i=1; i<=n; i++) {
		factorial[i] = factorial[i-1] * i;
		if(mod) factorial[i] %= mod;
	}
	return fact;
}

vector<int> kth_perm(int n, int k) {
    vector<int> perm(n), fact = factorial(n);
    ordered_set<int> S;
    for(int i=0; i<n; i++) S.insert(i);
    for(int i=0; i<n; i++) { 
        S.erase(perm[i] = *S.find_by_order(k / fact[n-i-1]));
        k = k % fact[n-i-1];
    }
    return perm;
}