// TC O(nlogn)
// Dependencies ordered_set, factoial
// Returns the kth permutation of [0, ... n-1] (*counting starts from k = 0 to n-1)
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
